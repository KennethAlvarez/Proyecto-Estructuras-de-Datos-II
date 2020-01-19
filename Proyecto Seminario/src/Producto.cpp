#include "Producto.h"

Producto::Producto()
{
    //ctor
}

Producto::~Producto()
{
    //dtor
}

string Producto::getNombre()
{
    return nombre;
}
void Producto::setNombre(string nom)
{
    nombre = nom;
}
int Producto::getPrecio()
{
    return precio;
}
void Producto::setPrecio(int d)
{
    precio = d;
}
int Producto::getCantidad()
{
    return cantidad;
}
void Producto::setCantidad(int d)
{
    cantidad = d;
}
void Producto::setCodigo(int d)
{
    codigo = d;
}
