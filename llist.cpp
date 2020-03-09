#include <llist.h>

LList::LList() {
	this->_size = 0;
	this->_head = nullptr;
}

LList::~LList() {
	while (_size)
		pop_front();
}

int& LList::data(size_t idx) const {
	Node* temp = _head;
	size_t count = 0;

	for (size_t i = 0; i < idx; i++)
	{
		if (temp != nullptr) {
			temp = temp->next;
		}
	}
	return temp->data;
}

void LList::push_back(int val) {
	if (_head == nullptr) 
		_head = new Node(val);
	else {
		Node* temp = _head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = new Node(val);
	}
	_size++;
}

void LList::push_front(int val) {
	_head = new Node(val, _head);
	_size++;
}

void LList::pop_back() {
	erase_at(_size - 1);
}

void LList::pop_front() {
	if (_head == nullptr)
		return;

	Node* temp = _head;
	_head = _head->next;
	delete temp;
	_size--;
}

size_t LList::size() const{
	return _size;
}

int LList::operator[](size_t idx) const {
	return data(idx);
}

int& LList::operator[](size_t idx) {
	return data(idx);
}

void LList::erase_at(size_t idx) {
	if (idx != 0) {
		Node* temp = _head;
		for (size_t i = 0; i < idx - 1; i++)
			temp = temp->next;

		Node* newNode = temp->next;
		temp->next = temp->next->next;
		delete newNode;
		_size--;
	}
	else
		pop_front();
}

void LList::insert_at(size_t idx, int val) {
	if (idx != 0) {
		Node* temp = _head;
		for (size_t i = 0; i < idx - 1; i++)
			temp = temp->next;

		Node* newNode = new Node(val, temp->next);
		temp->next = newNode;
		_size++;
	}
	else
		push_front(val);

}

void LList::reverse() {
	Node* prev = nullptr;
	Node* next = nullptr;
	Node* curr = _head;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	_head = prev;
}
