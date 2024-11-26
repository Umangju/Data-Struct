#include <iostream>

using namespace std;

class String
{
private:
	int size;
	char* container;

public:
	String()
	{
		size = 0;
		container = nullptr;
	}

	~String()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

	void operator = (const char* word)
	{
		int arraySize = strlen(word) + 1;

		size = strlen(word);

		if (container == nullptr)
		{
			container = new char[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				container[i] = word[i];
			}
		}
		else
		{
			char* newContainer = new char[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				newContainer[i] = word[i];
			}

			delete container;

			container = newContainer;
		}


	}

	void Append(const char* word)
	{
		int newSize = strlen(container) + strlen(word);

		char* newContainer = new char[newSize];

		for (int i = 0; i < strlen(container); i++)
		{
			newContainer[i] = container[i];
		}

		for (int i = 0; i < strlen(word); i++)
		{
			newContainer[strlen(container) + i] = word[i];
		}

		size = newSize;

		delete[] container;

		container = newContainer;
	}

	int Compare(const char* word)
	{
		int count = 0;

		for (int i = 0; i < strlen(word); i++)
		{
			if (container[i] != word[i])
			{
				break;
			}
			else
			{
				count++;
			}
		}

		if (strlen(word) == count)
		{
			return 0;
		}

		int classString = 0;
		int otherString = 0;

		for (int i = 0; i < strlen(container); i++)
		{
			classString += container[i];
		}

		for (int i = 0; i < strlen(word); i++)
		{
			otherString += word[i];
		}

		if (classString > otherString)
		{
			return 1;
		}
		else
		{
			return -1;
		}

	}

	char operator [ ] (const int& index)
	{
		return container[index];
	}

	int& Size()
	{
		return size;
	}

	/*void Show()
	{
		if (container != nullptr)
		{
			cout << container << endl;
		}
	}*/
};

int main()
{
	String string;

	string = "Janna";

	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}

	cout << endl;

	string = "Bard";

	string.Append(" Character");

	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}

	return 0;
}