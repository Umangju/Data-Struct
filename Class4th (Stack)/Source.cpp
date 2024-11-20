#pragma region stack 내 코드
//#include <iostream>
//#define SIZE 10
//
//using namespace std;
//
//template<typename T>
//class Stack
//{
//private:
//    int top;
//    T container[SIZE];
//
//public:
//    Stack()
//    {
//        top = -1;
//        for (int i = 0; i < SIZE; i++)
//        {
//            container[i] = T();
//        }
//    }
//
//    void push(T data)
//    {
//        if (top >= SIZE - 1)
//        {
//            cout << "Stack Overflow" << endl;
//        }
//        else
//        {
//            container[++top] = data;
//        }
//    }
//
//    void Pop()
//    {
//        if (Empty())
//        {
//            cout << "Stack Underflow" << endl;
//        }
//        else
//        {
//            top--;
//        }
//    }
//
//    bool Empty()
//    {
//        return top == -1;
//    }
//
//    int Size()
//    {
//        return top + 1;
//    }
//
//    T& Top()
//    {
//        if (Empty())
//        {
//            cout << "Stack is Empty!" << endl;
//        }
//        return container[top];
//    }
//};
//
//int main()
//{
//    Stack<int> stack;
//
//    stack.push(10);
//    stack.push(20);
//    stack.push(30);
//    stack.push(40);
//    stack.push(50);
//
//    cout << "stack의 크기 : " << stack.Size() << endl;
//
//    while (!stack.Empty())
//    {
//        cout << stack.Top() << endl;
//        stack.Pop();
//    }
//
//    return 0;
//}
#pragma endregion

#pragma region stack 강사님 코드
#include <iostream>
#define SIZE 10

using namespace std;

template<typename T>
class Stack
{
private:
    int top;
    int size;
    T container[SIZE];

public:
    Stack()
    {
        top = -1;
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        if (top >= SIZE - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            container[++top] = data;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    bool Empty()
    {
        if (top <= -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int& Size()
    {
        size = top + 1;

        return size;
    }

    T& Top()
    {
        return container[top];
    }
};

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "stack의 크기 : " << stack.Size() << endl;

    while (stack.Empty() == false)
    {
        cout << stack.Top() << endl;

        stack.Pop();
    }

    return 0;
}
#pragma endregion