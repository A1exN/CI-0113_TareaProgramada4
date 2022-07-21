#include "formeditarproducto.h"
#include "ui_formeditarproducto.h"

formEditarProducto::formEditarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formEditarProducto)
{
    ui->setupUi(this);
}

formEditarProducto::~formEditarProducto()
{
    delete ui;
}

void formEditarProducto::cargarInformacion(QListWidgetItem currentItem)
{
    std::string linea = currentItem.text().toStdString();
    std::string nombreProducto = linea.erase(0, 3).erase(linea.find_first_of("."));
    linea = currentItem.text().toStdString();
    std::string existencias = linea.erase(0, linea.find_first_of(":") + 2);

    this->ui->txtNombreProducto->setText(QString::fromStdString(nombreProducto));
    this->ui->txtExistencias->setText(QString::fromStdString(existencias));
}

std::string formEditarProducto::obtenerNombreProducto()
{
    return this->ui->txtNombreProducto->text().toStdString();
}

int formEditarProducto::obtenerExistenciasProducto()
{
    // Si es una letra retorna 0, por lo que no saltaría la excepcion, por eso se retorna -1
    bool ok;
    int existencias = this->ui->txtExistencias->text().toInt(&ok);
    if (ok) {
        return existencias;
    }
    return -1;
}
