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
