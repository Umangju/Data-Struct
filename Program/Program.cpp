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

    circularLinkedList.Show();

    return 0;
}