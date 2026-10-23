//Invertir toda la lista.

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void Insert(Node*& head, int value)
{
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}
//Parte 1.1
void ReverseList(Node*& head)
{
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr)
    {
        // Guarda el enlace anterior original.
        temp = current->prev;

        // Intercambia los enlaces del nodo actual.
        current->prev = current->next;
        current->next = temp;

        // Avanza usando el enlace que era next antes del intercambio.
        current = current->prev;
    }

    if (temp != nullptr)
    {
        // El último nodo recorrido ahora es el primero.
        head = temp->prev;
    }
}

void PrintForward(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << '\n';
}
//Parte 1.2
void SwapAdjacentPairs(Node*& head) {




};

int main()
{
    Node* head = nullptr;

    Insert(head, 50);
    Insert(head, 60);
    Insert(head, 70);
    Insert(head, 80);

    std::cout << "Antes:   ";
    PrintForward(head);

    ReverseList(head);

    std::cout << "Despues: ";
    PrintForward(head);

    return 0;
}















