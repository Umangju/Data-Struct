#include <iostream>

using namespace std;

#define SIZE 8

template<typename T>
class Heap
{
private:
    int index;
    T container[SIZE];

public:
    Heap()
    {
        for (int i = 0; i < SIZE; i++)
        {
            container[i] = 0;
        }

        index = 0;
    }

    void Insert(T data)
    {
        if (index >= SIZE)
        {
            cout << "Heap overflow." << endl;
        }
        else
        {
            container[index] = data;

            int child = index;
            int parent = child / 2;

            while (child > 1)
            {
                if (container[parent] < container[child])
                {
                    swap(container[parent], container[child]);
                }

                child = parent;
                parent = child / 2;
            };
        }
    }

    T Remove()
    {
        if (index == 0)
        {
            cout << "Heap underflow." << endl;
            return -1;
        }

        T removed = container[1];
        container[1] = container[index];
        container[index] = 0;
        index--;

        int parent = 1;
        while (true)
        {
            int left = parent * 2;
            int right = parent * 2 + 1;
            int largest = parent;

            if (left <= index && container[left] > container[largest])
            {
                largest = left;
            }

            if (right <= index && container[right] > container[largest])
            {
                largest = right;
            }

            if (largest == parent)
            {
                break;
            }

            T temp = container[parent];
            container[parent] = container[largest];
            container[largest] = temp;

            parent = largest;
        }

        return removed;
    }

    void Show()
    {
        for (int i = 0; i <= index; i++)
        {
            cout << container[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Heap<int> heap;

    heap.Insert(5);
    heap.Insert(7);
    heap.Insert(9);
    heap.Insert(16);

    heap.Show();

    return 0;
}