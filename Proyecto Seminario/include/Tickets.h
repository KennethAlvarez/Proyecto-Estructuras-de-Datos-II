#ifndef TICKETS_H
#define TICKETS_H
#include <string>
using namespace std;


class Tickets
{
    public:
        Tickets();
        void agregar();
        void eliminar();
        void modificar();
        void mostrar();
        void buscar();
        void menu();
        void CargarContador();
        void GuardarContador();
    private:
        int id;
        string cliente;
        string tipoAuto;
        string color;
        string placas;
        string servicio;
        float precio;
        int contador;
};

#endif // TICKETS_H
