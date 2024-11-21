#include <iostream>
#define SIZE 6

using namespace std;

template <typename T>
class CircleQueue
{
private:
    int size;
    int front;
    int rear;

    T container[SIZE];

public:
    CircleQueue()
    {
        size = 0;
        front = SIZE - 1;
        rear = SIZE - 1;

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
        if ((rear + 1) % SIZE == front)
        {
            cout << "CircleQueue Overflow" << endl;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            container[rear] = data;
            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "CircleQueue is Empty" << endl;
        }
        else
        {
            front = (front + 1) % SIZE;
            container[front] = NULL;
            size--;
        }
    }

    int& Size()
    {
        return size;
    }

    T& Front()
    {
        return container[(front + 1) % SIZE];
    }

    T& Back()
    {
        if (Empty())
        {
            cout << "No Data Exists" << endl;
            exit(1);
        }
        return container[rear];
    }
};

int main()
{
    CircleQueue<char> circlequeue;

    circlequeue.Push('A');
    circlequeue.Push('B');
    circlequeue.Push('C');
    circlequeue.Push('D');

    while (circlequeue.Empty() == false)
    {
        cout << circlequeue.Front() << endl;

        circlequeue.Pop();
    }

    circlequeue.Push('E');
    circlequeue.Push('F');
    circlequeue.Push('G');
    circlequeue.Push('H');

    return 0;
}