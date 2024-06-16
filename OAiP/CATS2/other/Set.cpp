#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
	int value;
	ListNode* prev;
	ListNode* next;

	ListNode(int _value, ListNode* _prev, ListNode* _next)
		: value(_value), prev(_prev), next(_next)
	{
	}
};

class Set
{
private:
	vector<ListNode*> arr;

	int hash(int v)
	{
		// Реализуйте хеш-функцию сами, 
		// возьмите пример с пары,
		// либо придумайте любой свой
	}

public:
	Set(int size) : arr(size, nullptr)
	{
	}

	ListNode* search(int v)
	{
		ListNode* node = arr[hash(v)];
		// Если ещё ничего не клали по этому индексу
		if (node == nullptr) return nullptr;
		// Если клали, то останавливаемся либо на искомом элементе, либо на последнем элементе списка
		// Реализуйте этот поиск
		return node;
	}

	void insert(int v)
	{
		ListNode* node = search(v);
		// Т.к. у нас множество, то дубликатов нет, а значит,
		// если нашли значение, то просто выходим
		if (node->value == v) return;

		ListNode* inserted_node = new ListNode(v, nullptr, nullptr);
		if (node == nullptr) // Если еще ничего не клали по индексу
		{
			set[hash(v)] = inserted_node; // Создаем первый элемент списка
			return;
		}
		else // Если находимся в конце списка (node - указатель на конец списка)
		{
			// Реализуйте вставку нового элемента в конец списка
		}
	}

	void remove(int v)
	{
		ListNode* node = search(v);
		if (node == nullptr) return; // Ничего не нашли, значит и удалять нечего

		// Реализуйте удаление элемента
		// Обратите внимание, что список двусвязный!
		// Есть и указатель на предыдущий, и указатель на следующий элемент
		// Это облегчит удаление

		delete node; // Чистим память, т.к. node отсоединён от списка и указывает на бесполезный кусок памяти
	}

	vector<int> to_values_array()
	{
		vector<int> values;
		for (int i = 0; i < arr.size(); ++i)
		{
			// Если arr[i] - ненулевой указатель,
			// то пробегаемся до конца списка и добавляем все
			// встреченные значения в values
		}

		return values;
	}
};

int main()
{
	Set s(1000);
	s.insert(5);
	s.insert(2);
	s.insert(7123312);
	s.remove(5);

	vector<int> values = s.to_values_array();
	// Должно вывестись 2 7123312 в любом порядке
	for (int i = 0; i < values.size(); ++i) cout << values[i] << endl;

	// Если получилось - можете решать первую задачу (Сбалансированное дерево)
	// Не забудьте отсортировать в конце!

	return 0;
}