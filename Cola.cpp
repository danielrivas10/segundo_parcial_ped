//Colas


#include <iostream>
#include <queue>

void SeparateRequests(std::queue<int> &requests,std::queue<int> &priority)
{

    std::size_t original_size = requests.size();

    for (std::size_t i = 0; i < original_size; ++i)
    {
        int request = requests.front();
        requests.pop();

        if (request % 3 == 0)
        {
            priority.push(request);
        }
        else
        {
            requests.push(request);
        }
    }
}

int main()
{
    std::queue<int> requests;
    std::queue<int> priority;

    requests.push(4);
    requests.push(6);
    requests.push(9);
    requests.push(2);
    requests.push(12);
    requests.push(5);
    requests.push(7);
    requests.push(3);

    SeparateRequests(requests, priority);

    std::cout << "requests: ";
    while (!requests.empty())
    {
        std::cout << requests.front() << ' ';
        requests.pop();
    }

    std::cout << "\npriority: ";
    while (!priority.empty())
    {
        std::cout << priority.front() << ' ';
        priority.pop();
    }

    std::cout << '\n';
    return 0;
}