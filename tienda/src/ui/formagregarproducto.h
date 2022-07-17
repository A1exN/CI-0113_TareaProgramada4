#ifndef FORMAGREGARPRODUCTO_H
#define FORMAGREGARPRODUCTO_H

#include <QDialog>

namespace Ui {
class formAgregarProducto;
}

class formAgregarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formAgregarProducto(QWidget *parent = nullptr);
    ~formAgregarProducto();

private:
    Ui::formAgregarProducto *ui;
};

#endif // FORMAGREGARPRODUCTO_H
