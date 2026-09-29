void eliminarCancion(Datos datos)
{
    if ( inicio== nullptr)
    {
        std::cout << "La playlist esta vacia. No hay nada que eliminar.\n";
        return;
    }

    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        if (actual->datos.t == datos.carne)
        {
            // Caso 1: Un solo nodo
            if (actual == inicio && actual == fin)
            {
                inicio = nullptr;
                fin = nullptr;
            }
            // Caso 3: Nodo al final
            else if (actual == fin)
            {
                fin = fin->anterior;
                fin->siguiente = nullptr;
            }

            delete actual;

            std::cout << "Datos eliminados exitosamente!\n";
            return;
        }
        actual = actual->siguiente;
    }

    std::cout<< "Datos no encontrados.\n";
}
