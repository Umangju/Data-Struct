#include <iostream>

using namespace std;

template <typename T>
class CircularLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;
    int size;

public:
    CircularLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~CircularLinkedList()
    {
        while (head != nullptr)
        {
            popFront();
        }
    }

    void pushBack(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }

        size++;
    }

    void pushFront(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
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
            Node* deleteNode = head->next;

            if (head == head->next)
            {
                head = nullptr;
            }
            else
            {
                head->next = deleteNode->next;
            }

            delete deleteNode;

            size--;
        }
    }

    void popBack()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head->next;

            if (head == head->next)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node* currentNode = head->next;
                Node* previousNode = head;

                while (currentNode->next != head->next)
                {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }

                previousNode->next = head->next;
                deleteNode = currentNode;
                delete deleteNode;

                head = previousNode;
            }

            size--;
        }
    }

    void Show()
    {
        if (head != nullptr)
        {
            Node* currentNode = head->next;

            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << " ";

                currentNode = currentNode->next;
            }
        }
    }
};

int main()
{
    CircularLinkedList<int> circularLinkedList;

    circularLinkedList.pushBack(10);
    circularLinkedList.pushBack(20);
    circularLinkedList.pushBack(30);

    circularLinkedList.pushFront(5);

    circularLinkedList.popFront();

    circularLinkedList.popBack();

    circularLinkedList.Show();

    return 0;
}