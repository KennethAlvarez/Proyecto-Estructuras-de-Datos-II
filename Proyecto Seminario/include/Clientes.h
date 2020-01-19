#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>

using namespace std;

class Clientes
{
    public:
        Clientes();
        void menuCliente();
        void agregar();
        void eliminar();
        void buscar();
        void modificar();
        void mostrar();
        virtual ~Clientes();
    private:
        char nombre[40];
        char domicilio[40];
        char correo[20];
        char telefono[12];
        char codigo[20];
        int contador;
};

#endif // CLIENTES_H
