#include "listaint.h"
#include "functions.h"
#include <iostream>

using namespace std;

void showMenu(){
    cout << "------------------------------" << endl;
    cout << "Introduzca que desea hacer: " << endl;
    cout << "(a) Anadir un elemento a la lista. " << endl;
    cout << "(b) Borrar un elemento de la lista." << endl;
    cout << "(m) Modificar un elemento de la lista. " << endl;
    cout << "(v) Mover un elemento de la lista. " << endl;
    cout << "(r) Recorrer " << endl;
    cout << "(i) Imprimir la lista por pantalla." << endl;
    cout << "(x) Salir" << endl;
    cout << "------------------------------" << endl;
}

int main()
{
    try{

        ListaInt lista;
        int aux, aux2;
        char option='z';
        while(option != 'x'){
            switch(option){
            case 'a':
                cout << "Introduzca un entero: ";
                cin >> aux;
                lista.push_back(aux);
                break;

            case 'b':
                cout << "Que numero desea borrar: ";
                cin >> aux;
                if(lista.erase(aux)) cout << "Numero borrado correctamente" << endl;
                else cout << "No se ha encontrado el numero " << aux << endl;
                break;

            case 'm':
                cout << "Cual es el indice del elemento desea modificar: " << endl;
                lista.printAll();
                cin >> aux;
                cout << "Que valor desea que tenga: ";
                cin >> aux2;
                lista.at(aux) = aux2;
                break;

            case 'v':
                cout << "Cual es el indice del elemento desea mover: " << endl;
                lista.printAll();
                cin >> aux;
                cout << "A que posicion desea moverlo: ";
                cin >> aux2;
                move(&lista, aux, aux2);
                break;

            case 'r':
                cout << "Recorrer por índice: " << endl;
                for(unsigned int i {1}; i <= lista.getSize(); i++){
                    cout << i << ": " << lista.at(i) << endl;
                }

                cout << "Recorrer por puntero: " << endl;
                for(ListaInt* it = lista.getNext(); it != nullptr; it = it->getNext()){
                    cout << it->getDato() << endl;
                }

                break;

            case 'i':
                cout << "Lista: " << endl;
                lista.printAll();
                break;
            }

            showMenu();
            cin >> option;
        }

        cout << "Buen dia!" << endl;
        return 0;

    }catch(string e){
        cout << e << endl;
        return -1;
    }


}
