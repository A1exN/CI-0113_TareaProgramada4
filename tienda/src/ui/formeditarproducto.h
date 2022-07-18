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

    //void cargarInformacion(int id, std::string nombreProducto, int existenciasProducto);
    std::string obtenerNombreProducto();
    int obtenerExistenciasProducto();

private:
    Ui::formEditarProducto *ui;
};

#endif // FORMEDITARPRODUCTO_H
