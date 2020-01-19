#include "Clientes.h"
#include <iostream>
#include <string>
#include <string.h>
#include "fstream"

using namespace std;

Clientes::Clientes()
{
    contador = 0;
}

Clientes::~Clientes()
{
    //dtor
}
void Clientes::menuCliente()
{
    int opc;
    while(opc != 6){
    system("cls");
    cout<<"******************Menu Clientes*****************"<<endl;
    cout<<"1.-Registrar Cliente"<<endl;
    cout<<"2.-Buscar Cliente"<<endl;
    cout<<"3.-Eliminar Cliente"<<endl;
    cout<<"4.-Modificar informacion"<<endl;
    cout<<"5.-Mostrar Cliente"<<endl;
    cin>>opc;
    switch(opc)
    {
        case 1: system("cls");
                agregar();
                system("pause");
            break;
        case 2: system("cls");
                buscar();
                system("pause");
            break;
        case 3:system("cls");
                eliminar();
            break;
        case 4:system("cls");
                modificar();
            break;
        case 5:system("cls");
                mostrar();
            break;
            default: cout<<"Opcion invalida"<<endl;
        }
    }
}
void Clientes::agregar()
{
    int n,d,c,t,cc;
    cout<<"Ingrese el nombre del cliente: "<<endl;
    cin.ignore();
    cin.getline(nombre, 40);
    cout<<"Ingrese el Domicilio: "<<endl;
    cin.getline(domicilio, 40);
    cout<<"Ingrese el Codigo: "<<endl;
    cin.getline(codigo, 40);
    cout<<"Ingrese el telefono de contacto: "<<endl;
    cin.getline(telefono, 40);
    cout<<"Ingrese el correo electronico: "<<endl;
    cin.getline(correo, 40);

    n = strlen(nombre);
    c = strlen(codigo);
    t = strlen(telefono);
    cc = strlen(correo);
    d = strlen(domicilio);

    ofstream fout("Cliente.txt", ios::app);

    if(fout.is_open())
    {
        fout.write((char*) &n, sizeof(int));
        fout.write((char*) &nombre, n);
        fout.write((char*) &c, sizeof(int));
        fout.write((char*) &codigo, c);
        fout.write((char*) &t, sizeof(int));
        fout.write((char*) &telefono, t);
        fout.write((char*) &cc, sizeof(int));
        fout.write((char*) &correo, cc);
        fout.write((char*) &d, sizeof(d));
        fout.write((char*) &domicilio, d);
        contador++;
        fout.close();

    }else
    {
        cout<<"Error al crear/abrir el archivo"<<endl;
    }
}

void Clientes::buscar()
{
    char aux[40];
    int n,d,c,t,cc;

    cout<<"Ingrese el codigo a buscar: "<<endl;
    cin.ignore();
    cin.getline(aux, 40);

    ifstream fin("Cliente.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            fin.read((char*) &n, sizeof(int));
            fin.read((char*) &nombre, n);
            nombre[n] = '\0';
            fin.read((char*) &c, sizeof(int));
            fin.read((char*) &codigo, c);
            codigo[c] = '\0';
            fin.read((char*) &t, sizeof(int));
            fin.read((char*) &telefono, t);
            telefono[t] = '\0';
            fin.read((char*) &cc, sizeof(int));
            fin.read((char*) &correo, cc);
            correo[cc] = '\0';
            fin.read((char*) &d, sizeof(d));
            fin.read((char*) &domicilio, d);
            domicilio[d] = '\0';

            if(fin.eof()) break;

            if(strcmp(codigo, aux) == 0)
            {
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Correo: "<<correo<<endl;
            }


        }
        fin.close();
    }
    else
    {
        cout<<"Error al abrir archivo"<<endl;
    }
}

void Clientes::eliminar()
{

    char aux[30];
    int n,d,c,t,cc;
    bool flag = true;
    cout<<"Ingrese el codigo del cliente a eliminar: "<<endl;
    cin.ignore();
    cin.getline(aux, 30);

    ifstream fin("Cliente.txt");
    ofstream fout("Auxiliar.txt", ios::app);

    if(fin.is_open())
    {

        while(!fin.eof())
        {
            fin.read((char*) &n, sizeof(int));
            fin.read((char*) &nombre, n);
            nombre[n] = '\0';
            fin.read((char*) &c, sizeof(int));
            fin.read((char*) &codigo, c);
            codigo[c] = '\0';
            fin.read((char*) &t, sizeof(int));
            fin.read((char*) &telefono, t);
            telefono[t] = '\0';
            fin.read((char*) &cc, sizeof(int));
            fin.read((char*) &correo, cc);
            correo[cc] = '\0';
            fin.read((char*) &d, sizeof(d));
            fin.read((char*) &domicilio, d);
            domicilio[d] = '\0';

            if(fin.eof()) break;

            if(strcmp(codigo, aux) == 0)
            {
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Correo: "<<correo<<endl;
                contador--;
                flag = false;
                system("pause");
            }else
            {
                fout.write((char*) &n, sizeof(int));
                fout.write((char*) &nombre, n);
                fout.write((char*) &c, sizeof(int));
                fout.write((char*) &codigo, c);
                fout.write((char*) &t, sizeof(int));
                fout.write((char*) &telefono, t);
                fout.write((char*) &cc, sizeof(int));
                fout.write((char*) &correo, cc);
                fout.write((char*) &d, sizeof(d));
                fout.write((char*) &domicilio, d);

            }


        }
        if(flag == true)
        {
            cout<<"No se encontro el archivo"<<endl;
        }
        fout.close();
        fin.close();
        remove("Cliente.txt");
        rename("Auxiliar.txt", "Cliente.txt");

        system("pause");
    }
}
void Clientes::mostrar()
{
    ifstream fin("Cliente.txt");

    int n,d,c,t,cc;
    if(fin.is_open())
    {
        cout<<"*****Registro Encontrados*****"<<endl;
        while(!fin.eof())
        {
            fin.read((char*) &n, sizeof(int));
            fin.read((char*) &nombre, n);
            nombre[n] = '\0';
            fin.read((char*) &c, sizeof(int));
            fin.read((char*) &codigo, c);
            codigo[c] = '\0';
            fin.read((char*) &t, sizeof(int));
            fin.read((char*) &telefono, t);
            telefono[t] = '\0';
            fin.read((char*) &cc, sizeof(int));
            fin.read((char*) &correo, cc);
            correo[cc] = '\0';
            fin.read((char*) &d, sizeof(d));
            fin.read((char*) &domicilio, d);
            domicilio[d] = '\0';

            if(fin.eof()) break;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Correo: "<<correo<<endl;
                cout<<"-----------------------"<<endl;
        }
    }else
    {
        cout<<"No hay registros para mostrar"<<endl;
    }
    fin.close();
    system("pause");
}

void Clientes::modificar()
{
    char aux[30];
    int n,d,c,t,cc;
    bool flag = true;
    int opc;

    ifstream fin("Cliente.txt");
    ofstream fout("Auxiliar.txt", ios::app);

    if(fin.is_open())
    {
        cout<<"Ingrese el codigo del usuario a modificar: "<<endl;
        cin.ignore();
        cin.getline(aux, 30);

        while(!fin.eof())
        {
            fin.read((char*) &n, sizeof(int));
            fin.read((char*) &nombre, n);
            nombre[n] = '\0';
            fin.read((char*) &c, sizeof(int));
            fin.read((char*) &codigo, c);
            codigo[c] = '\0';
            fin.read((char*) &t, sizeof(int));
            fin.read((char*) &telefono, t);
            telefono[t] = '\0';
            fin.read((char*) &cc, sizeof(int));
            fin.read((char*) &correo, cc);
            correo[cc] = '\0';
            fin.read((char*) &d, sizeof(d));
            fin.read((char*) &domicilio, d);
            domicilio[d] = '\0';

            if(fin.eof()) break;
            if(strcmp(codigo, aux) == 0)
            {
                cout<<"*****Registro localizado******"<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Correo: "<<correo<<endl;
                flag = false;
                cout<<"Seleccione el campo a modificar: "<<endl;
                cout<<"1.-Nombre"<<endl
                    <<"2.-Codigo"<<endl
                    <<"3.-Telefono"<<endl
                    <<"4.-Correo"<<endl
                    <<"5.-Domicilio"<<endl;
                    cin>>opc;
                    switch(opc)
                    {
                    case 1:
                        cout<<"Ingrese nuevo nombre: "<<endl;
                        cin.ignore();
                        cin.getline(aux, 30);
                        n = strlen(aux);
                        fout.write((char*) &n, sizeof(int));
                        fout.write((char*) &aux, n);
                        fout.write((char*) &c, sizeof(int));
                        fout.write((char*) &codigo, c);
                        fout.write((char*) &t, sizeof(int));
                        fout.write((char*) &telefono, t);
                        fout.write((char*) &cc, sizeof(int));
                        fout.write((char*) &correo, cc);
                        fout.write((char*) &d, sizeof(d));
                        fout.write((char*) &domicilio, d);
                        break;
                    case 2:
                        cout<<" Ingrese el nuevo codigo: "<<endl;
                        cin.ignore();
                        cin.getline(aux, 30);
                        c = strlen(aux);
                        fout.write((char*) &n, sizeof(int));
                        fout.write((char*) &nombre, n);
                        fout.write((char*) &c, sizeof(int));
                        fout.write((char*) &aux, c);
                        fout.write((char*) &t, sizeof(int));
                        fout.write((char*) &telefono, t);
                        fout.write((char*) &cc, sizeof(int));
                        fout.write((char*) &correo, cc);
                        fout.write((char*) &d, sizeof(d));
                        fout.write((char*) &domicilio, d);
                        break;
                    case 3:
                        cout<<"Ingrese nuevo telefono: "<<endl;
                        cin.ignore();
                        cin.getline(aux, 30);
                        t = strlen(aux);
                        fout.write((char*) &n, sizeof(int));
                        fout.write((char*) &nombre, n);
                        fout.write((char*) &c, sizeof(int));
                        fout.write((char*) &codigo, c);
                        fout.write((char*) &t, sizeof(int));
                        fout.write((char*) &aux, t);
                        fout.write((char*) &cc, sizeof(int));
                        fout.write((char*) &correo, cc);
                        fout.write((char*) &d, sizeof(d));
                        fout.write((char*) &domicilio, d);
                        break;
                    case 4:
                        cout<<"Ingrese nuevo Correo: "<<endl;
                        cin.ignore();
                        cin.getline(aux, 30);
                        cc = strlen(aux);
                        fout.write((char*) &n, sizeof(int));
                        fout.write((char*) &nombre, n);
                        fout.write((char*) &c, sizeof(int));
                        fout.write((char*) &codigo, c);
                        fout.write((char*) &t, sizeof(int));
                        fout.write((char*) &telefono, t);
                        fout.write((char*) &cc, sizeof(int));
                        fout.write((char*) &aux, cc);
                        fout.write((char*) &d, sizeof(d));
                        fout.write((char*) &domicilio, d);
                        break;
                    case 5:
                        cout<<"Ingrese nuevo domicilio: "<<endl;
                        cin.ignore();
                        cin.getline(aux, 30);
                        d = strlen(aux);
                        fout.write((char*) &n, sizeof(int));
                        fout.write((char*) &nombre, n);
                        fout.write((char*) &c, sizeof(int));
                        fout.write((char*) &codigo, c);
                        fout.write((char*) &t, sizeof(int));
                        fout.write((char*) &telefono, t);
                        fout.write((char*) &cc, sizeof(int));
                        fout.write((char*) &correo, cc);
                        fout.write((char*) &d, sizeof(d));
                        fout.write((char*) &aux, d);
                        break;
                        default: cout<<"No existe esa opcion"<<endl;

                    }
            }else
            {
                fout.write((char*) &n, sizeof(int));
                fout.write((char*) &nombre, n);
                fout.write((char*) &c, sizeof(int));
                fout.write((char*) &codigo, c);
                fout.write((char*) &t, sizeof(int));
                fout.write((char*) &telefono, t);
                fout.write((char*) &cc, sizeof(int));
                fout.write((char*) &correo, cc);
                fout.write((char*) &d, sizeof(d));
                fout.write((char*) &domicilio, d);
            }

        }
        fin.close();
        fout.close();
        remove("Cliente.txt");
        rename("Auxiliar.txt", "Cliente.txt");
    }else
    {
        cout<<"No se encontro el registro"<<endl;
    }

}
