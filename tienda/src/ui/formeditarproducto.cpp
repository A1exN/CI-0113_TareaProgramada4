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
