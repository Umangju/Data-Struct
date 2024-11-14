#include <iostream>

using namespace std;

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
        /*Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }*/
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                popBack();
            }
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

    void popFront()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
            size--;
        }
    }

    void pushBack(T data)
    {
        if (head == nullptr)
        {
            head = new Node;

            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            Node* newNode = new Node;

            currentNode->next = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }

        size++;
    }

    void popBack()
    {
        if (head == nullptr) // 리스트가 비어 있는 경우
        {
            cout << "Linked List is Empty" << endl;
        }

        else // 노드가 두 개 이상 있는 경우
        {
            Node* previousNode = nullptr;
            Node* deleteNode = head;

            if (size == 1)
            {
                head = deleteNode->next;
                delete deleteNode;
            }
            else
            {
                while (deleteNode->next != nullptr)
                {
                    previousNode = deleteNode;
                    deleteNode = deleteNode->next;
                }

                previousNode->next = deleteNode->next;
                delete deleteNode;
            }
            size--;
        }
    }

    void show() const
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};



int main()
{
    SingleLinkedList<int> singleLinkedList;

    singleLinkedList.pushFront(10);
    singleLinkedList.pushFront(20);

    singleLinkedList.pushBack(5);
    singleLinkedList.pushBack(0);

    singleLinkedList.show();

    singleLinkedList.popBack();

    singleLinkedList.show();

    singleLinkedList.popFront();
    singleLinkedList.popFront();

    return 0;
}