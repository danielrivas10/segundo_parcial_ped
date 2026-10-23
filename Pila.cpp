//Pilas.

#include <iostream>
#include <stack>

void RemoveConsecutiveDuplicates(std::stack<int> &values)
{
    std::stack<int> auxiliary;
    bool has_previous = false;
    int previous = 0;

    
    while (!values.empty())
    {
        int current = values.top();
        values.pop();

        if (!has_previous || current != previous)
        {
            auxiliary.push(current);
            previous = current;
            has_previous = true;
        }
    }


    while (!auxiliary.empty())
    {
        values.push(auxiliary.top());
        auxiliary.pop();
    }
}

int main()
{
    std::stack<int> values;

    values.push(2);
    values.push(2);
    values.push(7);
    values.push(7);
    values.push(3);
    values.push(8);
    values.push(8);
    values.push(5);
    values.push(5);
    values.push(5);

    RemoveConsecutiveDuplicates(values);

    std::cout << "Resultado: ";

    while (!values.empty())
    {
        std::cout << values.top() << ' ';
        values.pop();
    }

    std::cout << '\n';
    return 0;
}