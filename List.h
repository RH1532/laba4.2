#pragma once
using namespace std;
template<class T>
class List
{
private:
	class Node {
	public:
		Node(T data = T(), Node* Next = NULL) {
			this->data = data;
			this->Next = Next;
		}
		Node* Next;
		T data;
	};
public:
	void push_back(T obj) { // add to end bc
		if (head != NULL) {
			this->tail->Next = new Node(obj);
			tail = tail->Next;
		}
		else {
			this->head = new Node(obj);
			this->tail = this->head;
		}
		Size++;
	}
	void push_front(T obj) { // add to start bc
		if (head != NULL) {
			Node* current = new Node;
			current->data = obj;
			current->Next = this->head;
			this->head = current;
		}
		else {
			this->head = new Node(obj);
		}
		this->Size++;
	}
	void pop_back() { // delete last item bc
		if (head != NULL) {
			Node* current = head;
			while (current->Next != tail)//looking for the penultimate
				current = current->Next;
			delete tail;
			tail = current;
			tail->Next = NULL;
			Size--;
		}
		else throw std::out_of_range("out_of_range");
	}
	void pop_front() { // delete the first item bc-+
		if (head != NULL) {
			Node* current = head;
			head = head->Next;
			current->Next = NULL;
			delete current;
			Size--;
		}
		else throw std::out_of_range("out_of_range");
	}
	void insert(T obj, size_t k) {// adding an element by index (insertion before an element that was previously available at this index) bc
		if (k >= 0 && this->Size > k) {
			if (this->head != NULL) {
				if (k == 0)
					this->push_front(obj);
				else
				{
					Node* current = new Node;// to add an item
					Node* current1 = head;// to search for the total item
					for (int i = 0; i < k - 1; i++) {
						current1 = current1->Next;
					}
					current->data = obj;
					current->Next = current1->Next;// retells on the trail element
					current1->Next = current;
					Size++;
				}
			}
		}
		else {
			throw std::out_of_range("out_of_range");
		}
	}
	T at(size_t k) {// getting an item by index bc
		if (this->head != NULL && k >= 0 && k <= this->Size - 1) {
			if (k == 0)
				return this->head->data;
			else
				if (k == this->Size - 1)
					return this->tail->data;
				else
				{
					Node* current = head;
					for (int i = 0; i < k; i++) {
						current = current->Next;
					}
					return current->data;
				}
		}
		else {
			throw std::out_of_range("out_of_range");
		}
	}
	void remove(int k) { // delete item by index bc
		if (head != NULL && k >= 0 && k <= Size - 1) {
			if (k == 0) this->pop_front();
			else
				if (k == this->Size - 1) this->pop_back();
				else
					if (k != 0) {
						Node* current = head;
						for (int i = 0; i < k - 1; i++) {// go to pre-element
							current = current->Next;
						}

						Node* current1 = current->Next;
						current->Next = current->Next->Next;
						delete current1;
						Size--;
					}
		}
		else {
			throw std::out_of_range("out_of_range");
		}
	}
	size_t get_size() { // getting list size bc
		return Size;
	}
	void print_to_console() { // output of list items to the console through a separator, do not use at bc
		if (this->head != NULL) {
			Node* current = head;
			for (int i = 0; i < Size; i++) {
				cout << current->data << ' ';
				current = current->Next;
			}
		}
	}
	void clear() { // delete all list items
		if (head != NULL) {
			Node* current = head;
			while (head != NULL) {
				current = current->Next;
				delete head;
				head = current;
			}
			Size = 0;
		}
	}
	void set(size_t k, T obj)  // replacement of an element by index with a transmitted element 
	{
		if (this->head != NULL && this->get_size() >= k && k >= 0) {
			Node* current = head;
			for (int i = 0; i < k; i++) {
				current = current->Next;
			}
			current->data = obj;
		}
		else {
			throw std::out_of_range("out_of_range");
		}
	}
	void sort() {
		T* array = new T[this->Size];
		Node* cur = head;
		int i = 0;
		while (cur != NULL) {
			array[i] = cur->data;
			cur = cur->Next;
			i++;
		}
		QuickSort(array, 0, this->Size - 1);
		cur = head;
		i = 0;
		while (cur != NULL) {
			cur->data = array[i];
			cur = cur->Next;
			i++;
		}
	}
	bool isEmpty() { // check for empty list bc
		return (bool)(head);
	}
	void reverse() { // reorders items in a list
		int Counter = Size;
		Node* HeadCur = NULL;
		Node* TailCur = NULL;
		for (int j = 0; j < Size; j++) {
			if (HeadCur != NULL) {
				if (head != NULL && head->Next == NULL) {
					TailCur->Next = head;
					TailCur = head;
					head = NULL;
				}
				else {
					Node* cur = head;
					for (int i = 0; i < Counter - 2; i++)
						cur = cur->Next;
					TailCur->Next = cur->Next;
					TailCur = cur->Next;
					cur->Next = NULL;
					tail = cur;
					Counter--;
				}
			}
			else {
				HeadCur = tail;
				TailCur = tail;
				Node* cur = head;
				for (int i = 0; i < Size - 2; i++)
					cur = cur->Next;
				tail = cur;
				tail->Next = NULL;
				Counter--;
			}
		}
		head = HeadCur;
		tail = TailCur;
	}
public:
	List(Node* head = NULL, Node* tail = NULL, int Size = 0) :head(head), tail(tail), Size(Size) {}
	~List() {
		if (head != NULL) {
			this->clear();
		}
	};
private:
	Node* head;
	Node* tail;
	int Size;
	void swap(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}
	void QuickSort(T* arr, int first, int last)
	{
		T mid;
		int f = first, l = last;
		mid = arr[(f + l) / 2];
		do
		{
			while (arr[f] < mid) f++;
			while (arr[l] > mid) l--;
			if (f <= l)
			{
				swap(arr[f], arr[l]);
				f++;
				l--;
			}
		} while (f < l);
		if (first < l) QuickSort(arr, first, l);
		if (f < last) QuickSort(arr, f, last);
	}
};