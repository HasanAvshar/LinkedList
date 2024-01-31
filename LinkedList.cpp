#include <iostream>
#include<cassert>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};

template<typename T>
class SingleLinkedList
{
	Node<T>* _head;
public:
	SingleLinkedList() { _head = NULL; }

	// add_front
	// add_back
	// pop_back
	// pop_front
	// Print


	void Add_front(Node<T>* item)
	{
		if (_head == NULL)
		{
			_head = item;
			return;
		}

		Node<T>* temp = _head;
		_head = NULL;
		_head = item;
		_head->next = temp;
		temp = NULL;
	}

	void Add_front(const T item)
	{
		Node<T>* newItem = new Node<T>(item);
		Add_front(newItem);
	}


	void Add_back(Node<T>* item)
	{
		if (_head == NULL)
		{
			_head = item;
			return;
		}

		Node<T>* endItem = _head;
		while (endItem->next != NULL)
			endItem = endItem->next;

		endItem->next = item;
	}
	void Add_back(const T item)
	{
		Add_back(new Node<T>(item));
	}

	string Pop_Back()
	{
		if (_head == NULL) assert(!"Element yoxdur");
		if (_head->next == NULL)
		{
			string item = _head->data;
			delete _head;
			_head = NULL;
			return item;
		}


		Node<T>* endItem = _head;
		while (endItem->next->next != NULL)
			endItem = endItem->next;

		string item = endItem->next->data;
		delete endItem->next;
		endItem->next = NULL;
		return item;
	}
	string Pop_front() {
		if (_head == NULL) assert(!"Element yoxdur");
		if (_head->next == NULL)
		{
			string item = _head->data;
			delete _head;
			_head = NULL;
			return item;
		}
		Node<T>* Item = _head->next;
		string item = _head->data;
		delete _head;
		_head = Item;
		return item;
	}

	void addBefore(const T x, const T item) {
		Node<T>* newNode = new Node<T>(item);

		if (_head == NULL)
		{
			_head = newNode;
			return;
		}

		if (_head->data == x)
		{
			Add_front(newNode);
			return;
		}

		Node<T>* current = _head;

		while (current->next != NULL && current->next->data != x)
		{
			current = current->next;
		}

		if (current->next != NULL)
		{
			newNode->next = current->next;
			current->next = newNode;
		}
		else
		{
			Add_back(newNode);
		}
	}

	void addAfter(const T x, const T item) {
		Node<T>* newNode = new Node<T>(item);

		if (_head == NULL)
		{
			_head = newNode;
			return;
		}

		Node<T>* current = _head;

		while (current != NULL && current->data != x)
		{
			current = current->next;
		}

		if (current != NULL)
		{
			newNode->next = current->next;
			current->next = newNode;
		}
		else
		{
			Add_back(newNode);
		}
	}
	void deleteItem(const T item) {
		if (_head == NULL)
		{
			return;
		}

		if (_head->data == item)
		{
			Node<T>* temp = _head;
			_head = _head->next;
			delete temp;
			return;
		}

		Node<T>* current = _head;

		while (current->next != NULL && current->next->data != item)
		{
			current = current->next;
		}

		if (current->next != NULL)
		{
			Node<T>* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
	}


	void Print() {
		if (_head == NULL) {
			cout << "[]" << endl;
			return;
		}

		cout << "[";
		Node<T>* item = _head;

		while (item != NULL)
		{
			cout << item->data;
			item = item->next;
			if (item != NULL) cout << ",";
		}
		cout << "]" << endl;
	}
	~SingleLinkedList() {
		if (_head != nullptr) delete[] _head;
		_head = nullptr;
	}
};

template<typename T>
class Chain
{
public:
	T data;
	Chain<T>* next;
	Chain<T>* prev;
	Chain(T data)
	{
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

template<typename T>
class DoubleLinkedList
{
	Chain<T>* _head;
	Chain<T>* _tail;
public:
	// add_front
	//add_back
	// pop_front
	// pop_back
	// printBack
	// printFront

	DoubleLinkedList()
	{
		_head = NULL;
		_tail = NULL;
	}


	void Add_back(const T item)
	{
		Add_back(new Chain<T>(item));
	}

	void Add_back(Chain<T>* item)
	{
		if (_head == NULL)
		{
			_head = item;
			_tail = item;
			return;
		}

		_tail->next = item;
		item->prev = _tail;
		_tail = item;
	}

	void Add_front(Chain<T>* item)
	{
		if (_head == NULL)
		{
			_head = item;
			_tail = item;
			return;
		}

		Chain<T>* temp = _head;
		_head = item;
		temp->prev = _head;
		_head->next = temp;
		temp = NULL;
	}
	void Add_front(const string item)
	{
		Add_front(new Chain<T>(item));
	}

	string Pop_back()
	{
		if (_tail == NULL) assert(!"Error");

		if (_tail->prev == NULL)
		{
			string item = _tail->data;
			delete _tail;
			_tail = NULL;
			_head = NULL;
			return item;
		}

		string item = _tail->data;
		Chain<T>* temp = _tail->prev;
		temp->next = NULL;

		delete _tail;
		_tail = temp;
		return item;
	}

	string Pop_front()
	{
		if (_head == NULL) assert(!"Error");

		if (_head->next == NULL)
		{
			string item = _head->data;
			delete _head;
			_tail = NULL;
			_head = NULL;
			return item;
		}
		string item = _head->data;
		Chain<T>* temp = _head->next;
		temp->prev = NULL;

		delete _head;
		_head = temp;
		return item;
	}

	void Print_Back()
	{
		if (_head == NULL)
		{
			cout << "[]" << endl;
			return;
		}

		cout << "[";
		Chain<T>* item = _tail;

		while (item != NULL)
		{
			cout << item->data;
			item = item->prev;
			if (item != NULL) cout << ",";
		}
		cout << "]";
	}

	void Print_Front()
	{
		if (_head == NULL)
		{
			cout << "[]" << endl;
			return;
		}

		cout << "[";
		Chain<T>* item = _head;

		while (item != NULL)
		{
			cout << item->data;
			item = item->next;
			if (item != NULL) cout << ",";
		}
		cout << "]" << endl;
	}

	void addBefore(const T x, const T item)
	{
		Chain<T>* current = _head;

		while (current != NULL && current->data != x)
		{
			current = current->next;
		}

		if (current == NULL)
		{
			cerr << x << " not found in the list." << endl;
			return;
		}

		Chain<T>* newNode = new Chain<T>(item);

		if (current->prev == NULL)
		{
			_head = newNode;
		}
		else
		{
			current->prev->next = newNode;
			newNode->prev = current->prev;
		}

		newNode->next = current;
		current->prev = newNode;
	}

	void addAfter(const T x, const T item)
	{
		Chain<T>* current = _head;

		while (current != NULL && current->data != x)
		{
			current = current->next;
		}

		if (current == NULL)
		{
			cerr << x << " not found in the list." << endl;
			return;
		}

		Chain<T>* newNode = new Chain<T>(item);

		if (current->next == NULL)
		{
			_tail = newNode;
		}
		else
		{
			current->next->prev = newNode;
			newNode->next = current->next;
		}

		newNode->prev = current;
		current->next = newNode;
	}

	void deleteItem(const T item)
	{
		Chain<T>* current = _head;

		while (current != NULL && current->data != item)
		{
			current = current->next;
		}

		if (current == NULL)
		{
			cerr << item << " not found in the list." << endl;
			return;
		}

		if (current->prev == NULL)
		{
			_head = current->next;
		}
		else
		{
			current->prev->next = current->next;
		}

		if (current->next == NULL)
		{
			_tail = current->prev;
		}
		else
		{
			current->next->prev = current->prev;
		}

		delete current;
	}
	~DoubleLinkedList() {
		if (_head != nullptr) delete[] _head;
		if (_tail != nullptr) delete[] _tail;
		_head = nullptr;
		_tail = nullptr;
	}

};


int main()
{

	SingleLinkedList<string> list;
	list.Add_back("23");
	list.Add_front("34");
	list.addAfter("34", "5");
	list.Print();
	list.addBefore("5", "100");
	list.Print();
	list.deleteItem("34");
	list.Print();

	cout << endl;

	DoubleLinkedList<string> listt;
	listt.Add_front("12");
	listt.Add_back("109");
	listt.Print_Back();
	listt.addAfter("109", "36");
	cout << endl;
	listt.Print_Front();
	listt.addBefore("109", "57");
	listt.Print_Front();
}