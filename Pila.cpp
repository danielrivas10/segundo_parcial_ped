#include <iostream>
#include <stack>

void RemoveConsecutiveDuplicates(std::stack<int> &values, int target)
{
    std::stack<int> auxiliary; // Crea una pila temporal vacía. Usada para guardaar numeros que no sean 20.

    while (!values.empty())
    {
        int value = values.top(); // O sea si es el valor buscado entonces lo sube
        values.pop();             // Acá lo elimina.

        if (value != target)
        {
            auxiliary.push(value);
            
        }
    }

    // Devolver los elementos a values para conservar su orden. Quitandolo de auxiliary.
    while (!auxiliary.empty())
    {
        values.push(auxiliary.top());
        auxiliary.pop();
    }
}

int main()
{
    std::stack<int> values;

    values.push(10);
    values.push(20);
    values.push(50);
    values.push(20);
    values.push(40);
    RemoveConsecutiveDuplicates(values, 20);


    while (!values.empty())
    {
        std::cout << values.top();

        values.pop();

        if (!values.empty())
        {
            std::cout << ", ";
        }
    }

    std::cout << '\n';

    return 0;
}
