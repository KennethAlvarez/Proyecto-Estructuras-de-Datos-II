#include "Tickets.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


Tickets::Tickets()
{
    contador = 0;
}
void Tickets::CargarContador()
{
    ifstream fin("ContadorT.txt");
    fin.read((char*)&contador, sizeof(int));
    fin.close();
}
void Tickets::GuardarContador()
{
    ofstream fout("ContadorT.txt");
    fout.write((char*)&contador,sizeof(int));
    fout.close();
}
void Tickets::menu()
{
    int opc;
        while(opc != 6){
            cout<<"-----Menu Tickets-----"<<endl;
            cout<<"1.-Agregar"<<endl
                <<"2.-Eliminar"<<endl
                <<"3.-Modificar"<<endl
                <<"4.-Buscar"<<endl
                <<"5.-Mostrar"<<endl;
                cin>>opc;

                switch(opc)
                {
                case 1:
                    system("cls");
                    agregar();
                    break;
                case 2: system("cls");
                        eliminar();
                    break;
                case 3:system("cls");
                        modificar();
                    break;
                case 4:system("cls");
                       buscar();
                    break;
                case 5:system("cls");
                        mostrar();
                        system("pause");
                    break;
                }
            }

}

void Tickets::agregar()
{
    CargarContador();
    cout<<"------------Ingrese la informacion-------------"<<endl;
    id = contador;
    cout<<"Ingrese nombre del cliente: "<<endl;
    fflush(stdin);getline(cin, cliente);
    cout<<"Ingrese el modelo del coche: "<<endl;
    fflush(stdin);getline(cin, tipoAuto);
    cout<<"Color del vehículo: "<<endl;
    fflush(stdin);getline(cin, color);
    cout<<"Placas del vehículo: "<<endl;
    fflush(stdin);getline(cin, placas);
    cout<<"Tipo de Servicio: "<<endl;
    fflush(stdin);getline(cin, servicio);
    cout<<"Precio: "<<endl;
    cin>>precio;

    ofstream fout("Ticket.txt", ios::app);
    fout.write((char*)&id, sizeof(Tickets));
    fout.write((char*)&cliente, sizeof(Tickets));
    fout.write((char*)&tipoAuto, sizeof(Tickets));
    fout.write((char*)&color, sizeof(Tickets));
    fout.write((char*)&placas, sizeof(Tickets));
    fout.write((char*)&servicio, sizeof(Tickets));
    fout.write((char*)&precio, sizeof(Tickets));
    fout.close();
    contador++;
    GuardarContador();
}

void Tickets::mostrar()
{
    ifstream fin("Ticket.txt");
    cout<<"********Informacion Encontrada*********"<<endl;
    while(!fin.eof())
    {
        fin.read((char*)&id,sizeof(Tickets));
        fin.read((char*)&cliente,sizeof(Tickets));
        fin.read((char*)&tipoAuto,sizeof(Tickets));
        fin.read((char*)&color,sizeof(Tickets));
        fin.read((char*)&placas,sizeof(Tickets));
        fin.read((char*)&servicio,sizeof(Tickets));
        fin.read((char*)&precio,sizeof(Tickets));
        if(fin.eof()) break;
        cout<<"ID: "<<id<<endl;
        cout<<"Nombre Cliente: "<<cliente<<endl;
        cout<<"Modelo del Auto: "<<tipoAuto<<endl;
        cout<<"Color de vehiculo: "<<color<<endl;
        cout<<"Placas: "<<placas<<endl;
        cout<<"Tipo de Servicio: "<<servicio<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"---------------------------------"<<endl;
    }
    fin.close();
}
void Tickets::eliminar()
{
    int aux;
    bool flag = false;
    cout<<"Ingrese la ID del ticket a eliminar: "<<endl;
    cin>>aux;
    ifstream fin("Ticket.txt");
    ofstream fout("Auxiliar.txt");

    while(!fin.eof())
    {
        fin.read((char*)&id,sizeof(Tickets));
        fin.read((char*)&cliente,sizeof(Tickets));
        fin.read((char*)&tipoAuto,sizeof(Tickets));
        fin.read((char*)&color,sizeof(Tickets));
        fin.read((char*)&placas,sizeof(Tickets));
        fin.read((char*)&servicio,sizeof(Tickets));
        fin.read((char*)&precio,sizeof(Tickets));
        if(fin.eof()) break;
        if(id == aux)
        {
            cout<<"ID: "<<id<<endl;
            cout<<"Nombre Cliente: "<<cliente<<endl;
            cout<<"Modelo del Auto: "<<tipoAuto<<endl;
            cout<<"Color de vehiculo: "<<color<<endl;
            cout<<"Placas: "<<placas<<endl;
            cout<<"Tipo de Servicio: "<<servicio<<endl;
            cout<<"Precio: "<<precio<<endl;
            flag = true;
        }else
        {
            fout.write((char*)&id, sizeof(Tickets));
            fout.write((char*)&cliente, sizeof(Tickets));
            fout.write((char*)&tipoAuto, sizeof(Tickets));
            fout.write((char*)&color, sizeof(Tickets));
            fout.write((char*)&placas, sizeof(Tickets));
            fout.write((char*)&servicio, sizeof(Tickets));
            fout.write((char*)&precio, sizeof(Tickets));
        }

    }
    if(flag == false)
    {
        cout<<"No se encontro la informacion"<<endl;
    }
    fin.close();
    fout.close();
    remove("Ticket.txt");
    rename("Auxiliar.txt","Ticket.txt");
}

void Tickets::buscar()
{
    int aux;
    bool flag = false;
    ifstream fin("Ticket.txt");
    cout<<"---------------Busqueda por ID-------------"<<endl;
    cout<<"Ingrese la Id del ticket a buscar: "<<endl;
    cin>>aux;
    while(!fin.eof())
    {
        fin.read((char*)&id,sizeof(Tickets));
        fin.read((char*)&cliente,sizeof(Tickets));
        fin.read((char*)&tipoAuto,sizeof(Tickets));
        fin.read((char*)&color,sizeof(Tickets));
        fin.read((char*)&placas,sizeof(Tickets));
        fin.read((char*)&servicio,sizeof(Tickets));
        fin.read((char*)&precio,sizeof(Tickets));
        if(fin.eof()) break;
        if(id == aux)
        {
            cout<<"********Informacion Encontrada*********"<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Nombre Cliente: "<<cliente<<endl;
            cout<<"Modelo del Auto: "<<tipoAuto<<endl;
            cout<<"Color de vehiculo: "<<color<<endl;
            cout<<"Placas: "<<placas<<endl;
            cout<<"Tipo de Servicio: "<<servicio<<endl;
            cout<<"Precio: "<<precio<<endl;
            flag = true;
        }

    }
    if(flag == false)
    {
        cout<<"No se encontro la informacion"<<endl;
    }
}
void Tickets::modificar()
{
    int aux, op;
    bool flag = false;
    cout<<"Ingrese la ID del ticket a modificar: "<<endl;
    cin>>aux;
    ifstream fin("Ticket.txt");
    ofstream fout("Auxiliar.txt");

    while(!fin.eof())
    {
        fin.read((char*)&id,sizeof(Tickets));
        fin.read((char*)&cliente,sizeof(Tickets));
        fin.read((char*)&tipoAuto,sizeof(Tickets));
        fin.read((char*)&color,sizeof(Tickets));
        fin.read((char*)&placas,sizeof(Tickets));
        fin.read((char*)&servicio,sizeof(Tickets));
        fin.read((char*)&precio,sizeof(Tickets));
        if(fin.eof()) break;
        if(id == aux)
        {
            cout<<"ID: "<<id<<endl;
            cout<<"Nombre Cliente: "<<cliente<<endl;
            cout<<"Modelo del Auto: "<<tipoAuto<<endl;
            cout<<"Color de vehiculo: "<<color<<endl;
            cout<<"Placas: "<<placas<<endl;
            cout<<"Tipo de Servicio: "<<servicio<<endl;
            cout<<"Precio: "<<precio<<endl;
            flag = true;

            cout<<"******Seleccione la opcion a modificar******"<<endl;
            cout<<"1-Nombre"<<endl
                <<"2.-Modelo"<<endl
                <<"3.-Color"<<endl
                <<"4.-Placas"<<endl
                <<"5.-Tipo de Servicio"<<endl
                <<"6.-Precio"<<endl;
                cin>>op;
                switch(op)
                {
                case 1:
                    cout<<"Ingrese el nuevo nombre del Cliente: "<<endl;
                    fflush(stdin);getline(cin, cliente);
                    break;
                case 2:
                    cout<<"Ingrese el nuevo modelo: "<<endl;
                    fflush(stdin);getline(cin, tipoAuto);
                    break;
                case 3:
                    cout<<"Ingrese el nuevo Color: "<<endl;
                    fflush(stdin);getline(cin, color);
                    break;
                case 4:
                    cout<<"Ingrese las nuevas Placas: "<<endl;
                    fflush(stdin);getline(cin, placas);
                    break;
                case 5:
                    cout<<"Ingrese el nuevo Servicio: "<<endl;
                    fflush(stdin);getline(cin,servicio);
                    break;
                case 6:
                    cout<<"Ingrese el nuevo precio: "<<endl;
                    cin>>precio;
                    break;
                }
                fout.write((char*)&id, sizeof(Tickets));
                fout.write((char*)&cliente, sizeof(Tickets));
                fout.write((char*)&tipoAuto, sizeof(Tickets));
                fout.write((char*)&color, sizeof(Tickets));
                fout.write((char*)&placas, sizeof(Tickets));
                fout.write((char*)&servicio, sizeof(Tickets));
                fout.write((char*)&precio, sizeof(Tickets));
        }else
        {
            fout.write((char*)&id, sizeof(Tickets));
            fout.write((char*)&cliente, sizeof(Tickets));
            fout.write((char*)&tipoAuto, sizeof(Tickets));
            fout.write((char*)&color, sizeof(Tickets));
            fout.write((char*)&placas, sizeof(Tickets));
            fout.write((char*)&servicio, sizeof(Tickets));
            fout.write((char*)&precio, sizeof(Tickets));
        }

    }
    if(flag == false)
    {
        cout<<"No se encontro la informacion"<<endl;
    }
    fin.close();
    fout.close();
    remove("Ticket.txt");
    rename("Auxiliar.txt","Ticket.txt");
}
