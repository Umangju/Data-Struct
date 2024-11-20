#include <iostream>
#define SIZE 5

using namespace std;

template <typename T>
class LinearQueue
{
private:
    int size;
    int front;
    int rear;

    T container[SIZE];

public:
    LinearQueue()
    {
        size = 0;
        front = 0;
        rear = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "LinearQueue Overflow" << endl;
        }
        else
        {
            container[rear++] = data;

            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "LinearQueue Underflow" << endl;
        }
        else
        {
            front = (front + 1) % SIZE;
            size--;
        }
    }
};

int main()
{
    LinearQueue<int> linearQueue;

    linearQueue.Push(10);
    linearQueue.Push(10);
    
    return 0;
}