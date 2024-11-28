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

};

int main()
{
	HashTable<int, std::string> hashTable;

	return 0;
}