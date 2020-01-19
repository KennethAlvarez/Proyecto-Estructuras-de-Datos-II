#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

using namespace std;

class Producto
{
    public:
        Producto();
        string getNombre();
        void setNombre(string nombre);
        int getPrecio();
        void setPrecio(int dato);
        int getCodigo();
        void setCodigo(int dato);
        int getCantidad();
        void setCantidad(int dato);

        virtual ~Producto();
    private:
        string nombre;
        int precio;
        int codigo;
        int cantidad;

};

#endif // PRODUCTO_H
