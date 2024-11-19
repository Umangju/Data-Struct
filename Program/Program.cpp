#include <iostream>
#define SIZE 10

using namespace std;

template<typename T>
class Stack
{
private:
    int top;
    T container[SIZE];

public:
    Stack()
    {
        top = -1;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }
};

int main()
{
    Stack<int> stack;


    return 0;
}