//2.2 Separar solicitudes de una cola.


#include <iostream>
#include <queue>
/*
void SeparateRequests(
std::queue<int>& requests,
std::queue<int>& priority) {}

*/

void RemoveValue(std::queue<int>& request)
{
    std::queue<int> auxiliary;

    // Sacamos todos los elementos de la cola original.
    while (!requests.empty())
    {
        int value = requests.front();
        requests.pop();

        // Guardamos únicamente los que no se deben eliminar.
        if (value % 3==0)
        {
            auxiliary.push(value);
        }
    }

    // Devolvemos los conservados a la cola original.
    while (!auxiliary.empty())
    {
        requests.push(auxiliary.front());
        auxiliary.pop();
    }
}

void PrintQueue(std::queue<int> requests)
{
    while (!requests.empty())
    {
        std::cout << requests.front() << " ";
        requests.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::queue<int> requests;
    requests.push(5);
    requests.push(2);
    requests.push(3);
    requests.push(3);
    requests.push(5);


    std::cout << "Despues de separar las colas ";
    PrintQueue(requests);

    return 0;
}






