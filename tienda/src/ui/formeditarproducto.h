#ifndef FORMEDITARPRODUCTO_H
#define FORMEDITARPRODUCTO_H

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

private:
    Ui::formEditarProducto *ui;
};

#endif // FORMEDITARPRODUCTO_H
