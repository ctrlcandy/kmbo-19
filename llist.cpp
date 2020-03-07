#include "llist.h"

LList::LList() {
	this->_size = 0;
	this->head = nullptr;
}

LList::~LList() {
	
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

}

void LList::pop_back() {

}

void LList::pop_front() {

}

size_t LList::size() const{
	return _size;
}

int& LList::operator[](size_t idx) {
	Node* temp = head;
	size_t count = 0;

	while (temp->next != nullptr) {
		if (count == idx)
			return temp->data;

		temp = temp->next;
		count++;
	}
}

int LList::operator[](size_t idx) const {

}

void LList::erase_at(size_t idx) {

}

void LList::insert_at(size_t idx, int val) {

}

void LList::reverse() {

}
