#include "llist.h"

LList::LList() {
	this->_size = 0;
	this->head = nullptr;
}

LList::~LList() {
	while (_size)
		pop_front();
}

void LList::push_back(int val) {
	if (head == nullptr) 
		head = new Node(val);
	else {
		Node* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = new Node(val);
	}
	_size++;
}

void LList::push_front(int val) {
	head = new Node(val, head);
	_size++;
}

void LList::pop_back() {
	erase_at(_size - 1);
}

void LList::pop_front() {
	if (head == nullptr)
		return;

	Node* temp = head;
	head = head->next;
	delete temp;
	_size--;
}

size_t LList::size() const{
	return _size;
}

int LList::operator[](size_t idx) const {
	Node* temp = head;
	size_t count = 0;

	while (temp != nullptr) {
		if (count == idx)
			return temp->data;

		temp = temp->next;
		count++;
	}
}

int& LList::operator[](size_t idx) {
	//...
}


void LList::erase_at(size_t idx) {
	if (idx != 0) {
		Node* temp = head;
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
		Node* temp = head;
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

}
