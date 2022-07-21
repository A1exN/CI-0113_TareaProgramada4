#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formeditarproducto.h"
#include "formagregarproducto.h"
#include "QMessageBox"
#include "QFileDialog"
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tienda = new Tienda();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->tienda;
}


void MainWindow::on_btnEditarProducto_clicked()
{
    QListWidgetItem *productoSeleccionado = this->ui->listaEditable->currentItem();

    if (productoSeleccionado == nullptr)
    {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Producto No seleccionado");
        msgBox->setText("No ha escogido ningún producto");
        msgBox->open();
    }
    else
    {
        formEditarProducto formEditarProducto{this};

        formEditarProducto.cargarInformacion(*(this->ui->listaEditable->currentItem()));

        int resultado = formEditarProducto.exec();

        if (resultado == QDialog::Accepted)
        {
            std::string nombreProducto = formEditarProducto.obtenerNombreProducto();
            int existencias = formEditarProducto.obtenerExistenciasProducto();

            try {
                this->tienda->ObtenerProducto(this->ui->listaEditable->currentRow() + 1)->ModificarNombre(nombreProducto);
                this->tienda->ObtenerProducto(this->ui->listaEditable->currentRow() + 1)->ModificarExistencias(existencias);
            } catch (const std::exception& e) {
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setWindowTitle("Error al guardar");
                msgBox->setText(e.what());
                msgBox->open();
                return;
            }

            // Editar texto en lista
            QString id = QString::number(this->tienda->ObtenerProducto(this->ui->listaEditable->currentRow() + 1)->ObtenerID());
            QString nombre = QString::fromStdString(nombreProducto);
            QString qExistencias = QString::number(existencias);
            this->ui->listaEditable->currentItem()->setText(id + ". " + nombre + ". En existencia: " + qExistencias);
        }
    }
}


void MainWindow::on_btnAgregarProducto_clicked()
{
    formAgregarProducto formAgregarProducto{this};
    int resultado = formAgregarProducto.exec();

    if (resultado == QDialog::Accepted)
    {
        int id = formAgregarProducto.obtenerID();
        std::string nombreProducto = formAgregarProducto.obtenerNombreProducto();
        int existencias = formAgregarProducto.obtenerExistenciasProducto();

        try {
            Producto *nuevoProducto = new Producto(id, nombreProducto, existencias);
            this->tienda->AgregarProducto(nuevoProducto);
        } catch (const std::exception& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error al guardar");
            msgBox->setText(e.what());
            msgBox->open();
            return;
        }

        // Editar texto en lista
        QString qID = QString::number(id);
        QString qNombre = QString::fromStdString(nombreProducto);
        QString qExistencias = QString::number(existencias);
        this->ui->listaEditable->addItem(qID + ". " + qNombre + ". En existencia: " + qExistencias);
        this->ui->listaEditable->sortItems();
    }
}


void MainWindow::on_btnGuardarTienda_clicked()
{
    string nombreTienda = this->ui->txtNombreTienda->text().toStdString();
    string direccionInternet = this->ui->txtDireccionInternet->text().toStdString();
    string direccionFisica = this->ui->txtDireccionFisica->text().toStdString();
    string telefono = this->ui->txtTelefono->text().toStdString();

    try {

        this->tienda->AgregarInformacionGeneralDeTienda(nombreTienda, direccionInternet, direccionFisica, telefono);

    } catch (const std::exception& e) {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Error al guardar");
        msgBox->setText(e.what());
        msgBox->open();
        return;
    }

    QString nombreArchivo = QFileDialog::getSaveFileName(this,
            "Guardar Archivo de Datos", "",
            tr("Archivo de datos (*.dat);;All Files (*)"));

    if (nombreArchivo != "")
    {
        std::string strNombreArchivo = nombreArchivo.toStdString();

        ofstream archivoSalida(strNombreArchivo, ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error al guardar");
            msgBox->setText("Error escribiendo el archivo");
            msgBox->open();
            return;
        }

        this->tienda->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();
    }
}


void MainWindow::on_btnCargarTienda_clicked()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this,
            "Abrir un archivo de datos", "",
            tr("Archivo de datos (*dat);;All files(*)"));

    if (nombreArchivo != "")
    {
        std::string strNombreArchivo = nombreArchivo.toStdString();

        ifstream archivoEntrada(strNombreArchivo, ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error al cargar");
            msgBox->setText("Error leyendo el archivo");
            msgBox->open();
            return;
        }

        //Reiniciamos la tienda
        this->tienda = new Tienda();

        this->tienda->CargarDesdeStreamBinario(&archivoEntrada);

        archivoEntrada.close();

        stringstream streamInformacionTienda;
        streamInformacionTienda << this->tienda;
        string linea {};

        //Cargar informacion general de la tienda en los campos editables
        std::getline(streamInformacionTienda, linea);
        this->ui->txtNombreTienda->setText(QString::fromStdString(linea).mid(0,15));
        std::getline(streamInformacionTienda, linea);
        this->ui->txtDireccionInternet->setText(QString::fromStdString(linea).mid(0,24));
        std::getline(streamInformacionTienda, linea);
        this->ui->txtDireccionFisica->setText(QString::fromStdString(linea).mid(0,24));
        std::getline(streamInformacionTienda, linea);
        this->ui->txtTelefono->setText(QString::fromStdString(linea).mid(0,8));

        // Limpiar lista en caso de que haya algo antes
        this->ui->listaEditable->clear();

        //Cargar informacion de productos en lista editable
        while (std::getline(streamInformacionTienda, linea))
        {
            QString infoProducto = QString::fromStdString(linea);
            this->ui->listaEditable->addItem(infoProducto);
        }
    }
}


void MainWindow::on_btnLimpiarInformacionTienda_clicked()
{
    this->ui->txtNombreTienda->setText("");
    this->ui->txtDireccionInternet->setText("");
    this->ui->txtDireccionFisica->setText("");
    this->ui->txtTelefono->setText("");

    this->ui->txtNombreTienda->setFocus();
}


void MainWindow::on_btnBorrarLista_clicked()
{
    if (this->ui->listaEditable->count() == 0)
    {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Message Box");
        msgBox->setText("La lista ya se encuentra vacía");
        msgBox->open();
    }
    else
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Borrar Lista", "¿Realmente desea borrar la lista de productos?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {

            this->ui->listaEditable->clear();
            //Reinicia tienda
            this->tienda = new Tienda();
            qDebug() << "Yes was clicked";
            //QApplication::quit();

        }else {
            qDebug() << "Yes was *not* clicked";
        }
    }
}


void MainWindow::on_btnEliminarProducto_clicked()
{
    QListWidgetItem *productoSeleccionado = this->ui->listaEditable->currentItem();

    if (productoSeleccionado == nullptr)
    {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Producto No seleccionado");
        msgBox->setText("No ha escogido ningún producto");
        msgBox->open();
    }
    else
    {
        this->tienda->EliminarProducto(this->ui->listaEditable->currentRow() + 1);
        QListWidgetItem *linea = this->ui->listaEditable->takeItem(this->ui->listaEditable->currentRow());
        delete linea;
    }
}

