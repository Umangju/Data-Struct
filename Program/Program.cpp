#include <iostream>

using namespace std;
    
template<typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
    };

    Node* root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    Node* RootNode()
    {
        return root;
    }

    Node* CreateNode(T data)
    {
        Node* newNode = new Node();

        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    void Insert(T data)
    {
        if (root == nullptr)
        {
            root = CreateNode(data);
        }
        else
        {
            Node* currentNode = root;

            while (currentNode != nullptr)
            {
                if (currentNode->data == data)
                {
                    if (currentNode->left == nullptr)
                    {
                        return;
                    }
                    else if (currentNode->data > data)
                    {
                        if (currentNode->left == nullptr)
                        {
                            currentNode->left = CreateNode(data);
                            break;
                        }
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else 
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = CreateNode(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }

    void Inorder(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        Inorder(node->left);

        cout << node->data << " ";

        Inorder(node->right);
    }

    void Destroy(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        // 왼쪽 서브트리 삭제
        Destroy(node->left);
        // 오른쪽 서브트리 삭제
        Destroy(node->right);

        // 현재 노드 삭제
        delete node;
    }

    // 소멸자
    ~BinarySearchTree()
    {
        // 루트부터 트리를 삭제
        Destroy(root);
    }
};

int main()
{
    BinarySearchTree<int> binarySearchTree;

    binarySearchTree.Insert(15);
    binarySearchTree.Insert(9);
    binarySearchTree.Insert(7);
    binarySearchTree.Insert(20);

    cout << "Inorder Traversal: ";
    binarySearchTree.Inorder(binarySearchTree.RootNode());
    cout << endl;


    return 0;
}