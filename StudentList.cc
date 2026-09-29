#include <iostream>

struct Datos
{
    float carne;
    std::string nombre;
    std::string carrera;
};

// Struct Nodo - Representa cada nodo de la lista

struct Nodo
{
    Datos datos; // Dato almacenado en el nodo
    Nodo *siguiente; // Puntero al siguiente nodo
    Nodo *anterior;  // Puntero al nodo anterior
};

// Variables globales
Nodo *inicio = nullptr; // Puntero al primer nodo
Nodo *fin = nullptr;    // Puntero al último nodo

void eliminar_Final(Datos);
int main(){
std::cout<<"Hola mundo";
     Datos datos1;

            std::cout << "\n--- Eliminar datos al Final---\n";
            std::cin, datos1.carne;

            eliminar_Final(datos1);
}



void eliminar_Final(Datos datos)
{ if(inicio == nullptr){

    std::cout<<"La lista de datos esta vacia. No hay nada que eliminar."<<"\n";
    return;

    Nodo*actual = inicio;

    while(actual != nullptr)
    {
            if(actual == inicio && actual == fin){
                inicio = nullptr;
                fin = nullptr;
            }
            else if(actual == fin){
                fin == fin->anterior;
                fin->siguiente = nullptr;
            }
            delete actual;

            std::cout<<"Datos eliminados exitosamente"<<"\n";

            return;
    }

}
}
