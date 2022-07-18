#ifndef FORMAGREGARPRODUCTO_H
#define FORMAGREGARPRODUCTO_H

#include <QDialog>
#include <string>

namespace Ui {
class formAgregarProducto;
}

class formAgregarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formAgregarProducto(QWidget *parent = nullptr);
    ~formAgregarProducto();

    int obtenerID();
    std::string obtenerNombreProducto();
    int obtenerExistenciasProducto();

private:
    Ui::formAgregarProducto *ui;
};

#endif // FORMAGREGARPRODUCTO_H
