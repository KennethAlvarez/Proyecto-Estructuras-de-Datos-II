#include <iostream>
#include "Clientes.h"
#include "Producto.h"
#include "Tickets.h"

using namespace std;

int main()
{
    int op;
    Clientes c;
    Tickets t;
    while(op != 6)
    {
        cout<<"1.-Menu Producto"<<endl;
        cout<<"2.-Menu Clientes"<<endl;
        cout<<"3.-Menu Ticket"<<endl;
        cin>>op;

        switch(op)
        {
        case 1:
            system("cls");
            break;
        case 2:
            system("cls");
            c.menuCliente();
            break;
        case 3:
            t.menu();
            break;
        }
    }
    return 0;
}
