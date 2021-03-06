#ifndef FORMEDITARPRODUCTO_H
#define FORMEDITARPRODUCTO_H

#include "qlistwidget.h"
#include <QDialog>

namespace Ui {
class formEditarProducto;
}

class formEditarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formEditarProducto(QWidget *parent = nullptr);
    ~formEditarProducto();

    void cargarInformacion(QListWidgetItem currentItem);
    std::string obtenerNombreProducto();
    int obtenerExistenciasProducto();

private:
    Ui::formEditarProducto *ui;
};

#endif // FORMEDITARPRODUCTO_H
