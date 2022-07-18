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

/*void formEditarProducto::cargarInformacion(int id, std::string nombreProducto, int existenciasProducto)
{

}*/

std::string formEditarProducto::obtenerNombreProducto()
{
    return this->ui->txtNombreProducto->text().toStdString();
}

int formEditarProducto::obtenerExistenciasProducto()
{
    bool ok;
    int existencias = this->ui->txtExistencias->text().toInt(&ok);
    if (ok) {
        return existencias;
    }
    return -1;
}
