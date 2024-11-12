#include <iostream>

template <typename T>
class SingleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    int size;
    Node* head;

public:
    SingleLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    ~SingleLinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void pushFront(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }
};

int main()
{
    SingleLinkedList<int> singleLinkedList;

    singleLinkedList.pushFront(10);
    singleLinkedList.pushFront(20);
}