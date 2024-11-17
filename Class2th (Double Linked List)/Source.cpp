#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };

    int size;

    Node* head;
    Node* tail;

public:

    DoubleLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            popFront();
        }
    }

    void PushFront(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;

            head = newNode;
        }

        size++;
    }

    void popFront()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                deleteNode->next->previous = nullptr;

                head = head->next;
            }

            delete deleteNode;
            size--;
        }
    }

    void pushBack(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (tail == nullptr)
        {
            tail = newNode;
            head = tail;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;

            tail = newNode;
        }

        size++;
    }

    void popBack()
    {
        if (tail == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = tail;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail->previous->next = nullptr;

                tail = tail->previous;
            }

            delete deleteNode;

            size--;
        }
    }

    int& Size()
    {
        return size;
    }

    void Show()
    {
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }
};

int main()
{
    DoubleLinkedList<int> doubleLinkedList;

    doubleLinkedList.PushFront(10);
    doubleLinkedList.PushFront(20);

    doubleLinkedList.pushBack(30);
    doubleLinkedList.pushBack(40);

    cout << "Double Linked List의 크기 : " << doubleLinkedList.Size() << endl;

    doubleLinkedList.Show();

    doubleLinkedList.popBack();

    doubleLinkedList.popFront();

    doubleLinkedList.popFront();

    doubleLinkedList.popFront();

    return 0;
}