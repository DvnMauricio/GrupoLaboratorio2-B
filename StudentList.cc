#include <iostream>
#include <string>


Datos PedirDatos();
void MostrarDatos();
void AgregarDatos(Datos datos);
void liberarMemoria();

struct Datos
{
    int opcion;

    do
    {
        std::cout << "\n -----CENTRO DE DATOS DE ESTUDIANTES---- \n";
        std::cout << "1. Agregar nuevos datos \n";
        std::cout << "2. Mostrar datos (inicio -> fin) \n";
        std::cout << "0. Salir \n";
        std::cout << "Ingrese una opcion";
        std::cin >> opcion;
        std::cin.ignore();
    
        switch (opcion)
        {
            case 1:
            {
                Datos nuevo = PedirDatos();
                AgregarDatos(nuevo);
                
            }
            break;
            case 2:
            MostrarDatos();
            break;
            case 0:
            std::cout << "Saliendo del programa... \n";
            liberarMemoria();
            break;

            default:
            std::cout << "Opcion invalida, intente nuevamente. \n ";
        } 
    }while (opcion != 0);


    return 0;
}

Datos PedirDatos()
{
    Datos nuevo;

    std::cout << "Añadir nuevos datos" << std::endl;
    std::cout << "Nombre: " << std::endl;
    std::getline(std::cin, nuevo.nombre);
    std::cout << "Carne: " << std::endl;
    while (!(std::cin >> nuevo.carne) || nuevo.carne < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        if (nuevo.carne < 0){
            std::cout << "No se aceptan numeros negativos, ingrese un carne valido";
        }
        else{
            std::cout << "Solo se aceptan numeros, ingrese un carne valido";
        }

    }
    std::cin.ignore();
    std::cout << "Carrera: " << std::endl;
    std::getline(std::cin, nuevo.carrera);
    return nuevo;
}

void AgregarDatos(Datos datos)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo -> datos = datos;
    nuevo_nodo -> siguiente = nullptr;
    nuevo_nodo -> anterior = nullptr;

    if (inicio == nullptr)
    {
        inicio = nuevo_nodo;
        fin = nuevo_nodo;
    }
    else
    {
        nuevo_nodo -> anterior = fin;
        fin -> siguiente = nuevo_nodo;
        fin = nuevo_nodo;
    }
    std::cout << "Datos agregados" << std::endl;
}

void MostrarDatos()
{
    std::cout << "\n Datos de los estudiantes \n";
    if (inicio == nullptr){
        std::cout << "No hay datos registrados" << std::endl;
        return;
    }
    Nodo *actual = inicio;
    int posicion = 1;

    while (actual != nullptr)
    {
        std::cout << "\n Estudiante #" << posicion << "\n";
        std::cout << "Nombre: " << actual -> datos.nombre << "\n";
        std::cout << "Carne: " << actual -> datos.carne << "\n";
        std::cout << "Carrera: " << actual -> datos.carrera << "\n";
        actual = actual -> siguiente;
        posicion++;
    }
}
void liberarMemoria()
{
    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        Nodo *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    inicio = nullptr;
    fin = nullptr;
    std::cout << "Memoria liberada. Hasta luego!\n";
}
