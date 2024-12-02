#include <iostream>

using namespace std;

#define SIZE 6

template<typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];
public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}
	}

	template <typename T>
	int HashFunction(T key)
	{
		int hashIndex = (int)key % SIZE;

		return hashIndex;
	}

	template<>
	int HashFunction(std::string key)
	{
		int result = 0;
		for (int i = 0; i < key.length(); i++)
		{
			result += key[i];
		}

		int hashIndex = result % SIZE;

		return hashIndex;
	}

	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node();

		newNode->key = key;
		newNode->value = value;

		newNode->next = nullptr;

		return newNode;
	}

	void Insert(KEY key, VALUE value)
	{
		// 해시 인덱스를 계산하여 해당 버킷을 찾음
		int hashIndex = HashFunction(key);

		// 새로운 노드를 생성
		Node* newNode = CreateNode(key, value);

		// 해당 버킷에 기존 노드가 없다면 새 노드를 그 버킷의 첫 번째 노드로 설정
		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		// 버킷의 노드 수를 증가시킴
		bucket[hashIndex].count++;
	}

	void Remove(KEY key)
	{
		// 해시 인덱스를 계산하여 해당 버킷을 찾음
		int hashIndex = HashFunction(key);

		// 현재 버킷의 첫 번째 노드를 가져옴
		Node* currentNode = bucket[hashIndex].head;
		Node* previousNode = nullptr;

		// 버킷이 비어있는 경우
		if (currentNode == nullptr)
		{
			cout << "Not Key Found." << endl;
			return;
		}
		else
		{
			// 연결 리스트를 순회하며 노드를 탐색
			while (currentNode != nullptr)
			{
				if (currentNode->key == key) // 일치하는 키를 발견한 경우
				{
					if (currentNode == bucket[hashIndex].head) // 첫 번째 노드라면
					{
						bucket[hashIndex].head = currentNode->next;
					}
					else // 중간 또는 마지막 노드라면
					{
						previousNode->next = currentNode->next;
					}

					// 버킷 노드 개수 감소
					bucket[hashIndex].count--;

					// 노드 삭제
					delete currentNode;

					cout << "Key " << key << " removed successfully." << endl;
					return;
				}
				else // 일치하는 키를 찾지 못한 경우 다음 노드로 이동
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}

			// 키를 찾지 못한 경우
			cout << "Not Key Found" << endl;
		}
	}

	void Show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			// 현재 버킷의 head를 가져옴
			Node* currentNode = bucket[i].head;

			cout << "Bucket [" << i << "]: ";

			// 버킷이 비어있으면 출력
			if (currentNode == nullptr)
			{
				cout << "Empty" << endl;
				continue;
			}

			// 연결 리스트 순회
			while (currentNode != nullptr)
			{
				cout << "(" << currentNode->key << ", " << currentNode->value << ") -> ";
				currentNode = currentNode->next;
			}
			cout << "nullptr" << endl;
		}
	}

};

int main()
{
	HashTable<int, std::string> hashTable;

	hashTable.Insert(10, "Vector");
	hashTable.Insert(15, "Stack");
	hashTable.Insert(6, "Queue");
	hashTable.Insert(20, "Linked List");

	hashTable.Remove(15);

	hashTable.Remove(77);

	hashTable.Show();

	return 0;
}