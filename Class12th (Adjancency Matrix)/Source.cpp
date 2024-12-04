#include <iostream>

using namespace std;

#define SIZE 10

template<typename T>
class AdjancencyMatrix
{
private:
    int size;               // 정점의 개수
    T vertex[SIZE];         // 정점의 집합
    int matrix[SIZE][SIZE]; // 인접 행렬

public:
    AdjancencyMatrix()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;

            for (int j = 0; j < SIZE; ++j)
            {
                matrix[i][j] = NULL;
            }
        }
    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "Adjancency Matrix Overflow" << endl;
        }
        else
        {
            vertex[size++] = data;
        }
    }

    void Connect(int i, int j)
    {
        if (size <= 0)
        {
            cout << "Adjancency Matrix is Empty" << endl;
        }
        else if (i >= size || j >= size)
        {
            cout << "Index Out of Range" << endl;
        }
        else
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    void Show() const
    {
        if (size < 0)
        {
            cout << "Adjancency Matrix is Empty" << endl;
        }
        else
        {
            // 정점 출력
            cout << "  "; // 좌측 상단 공백
            for (int i = 0; i < size; ++i)
            {
                cout << vertex[i] << " ";
            }
            cout << endl;

            // 인접 행렬 출력
            for (int i = 0; i < size; ++i)
            {
                cout << vertex[i] << " "; // 행의 라벨 출력
                for (int j = 0; j < size; ++j)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    AdjancencyMatrix<char> adjancencyMatrix;

    adjancencyMatrix.Insert('A');
    adjancencyMatrix.Insert('B');
    adjancencyMatrix.Insert('C');
    adjancencyMatrix.Insert('D');

    adjancencyMatrix.Connect(0, 1);
    adjancencyMatrix.Connect(0, 2);
    adjancencyMatrix.Connect(1, 2);
    adjancencyMatrix.Connect(2, 3);

    adjancencyMatrix.Show();

    return 0;
}