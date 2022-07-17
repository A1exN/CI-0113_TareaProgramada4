#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formeditarproducto.h"
#include "formagregarproducto.h"
#include "QMessageBox"
#include "QFileDialog"
#include <fstream>

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
        formEditarProducto.exec();
    }
}


void MainWindow::on_btnAgregarProducto_clicked()
{
    formAgregarProducto formAgregarProducto{this};
    formAgregarProducto.exec();
}


void MainWindow::on_btnGuardarTienda_clicked()
{
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

