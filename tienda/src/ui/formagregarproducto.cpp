#include "formagregarproducto.h"
#include "ui_formagregarproducto.h"

formAgregarProducto::formAgregarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formAgregarProducto)
{
    ui->setupUi(this);
}

formAgregarProducto::~formAgregarProducto()
{
    delete ui;
}

int formAgregarProducto::obtenerID()
{
    return this->ui->txtID->text().toInt();
}

std::string formAgregarProducto::obtenerNombreProducto()
{
    return this->ui->txtNombre->text().toStdString();
}

int formAgregarProducto::obtenerExistenciasProducto()
{
    return this->ui->txtExistencias->text().toInt();
}
