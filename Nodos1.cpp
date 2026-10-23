#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void SwapAdjacentPairs(Node *&head)
{
    Node *first = head;
    Node *previous_pair_last = nullptr;

    while (first != nullptr && first->next != nullptr)
    {
        Node *second = first->next;
        Node *next_pair = second->next;

        second->prev = previous_pair_last;
        second->next = first;

        first->prev = second;
        first->next = next_pair;

        if (next_pair != nullptr)
        {
            next_pair->prev = first;
        }

        if (previous_pair_last != nullptr)
        {
            previous_pair_last->next = second;
        }
        else
        {
            head = second;
        }

        previous_pair_last = first;
        first = next_pair;
    }
}

int main()
{

    Node *node10 = new Node{10, nullptr, nullptr};
    Node *node20 = new Node{20, nullptr, node10};
    Node *node30 = new Node{30, nullptr, node20};
    Node *node40 = new Node{40, nullptr, node30};

    node10->next = node20;
    node20->next = node30;
    node30->next = node40;

    Node *head = node10;

    std::cout << "Antes:  ";
    for (Node *current = head; current != nullptr; current = current->next)
    {
        std::cout << current->data << ' ';
    }

    SwapAdjacentPairs(head);

    std::cout << "\nDespues: ";
    for (Node *current = head; current != nullptr; current = current->next)
    {
        std::cout << current->data << ' ';
    }

    std::cout << '\n';

    Node *current = head;
    while (current != nullptr)
    {
        Node *next_node = current->next;
        delete current;
        current = next_node;
    }

    return 0;
}