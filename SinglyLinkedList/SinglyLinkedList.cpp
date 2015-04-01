// SinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Node {
	// friend class SinglyLinkedList;
	private:
		int data;
		Node *next;
	public:
		Node(int a) : data(a), next(NULL){} /* Legacy to use NULL */
		int get_data(){ return data; }
		Node* get_next(){ return next; }
		void set_next(Node* n){ next = n; } /* Added to remove left operand must be l-value requirement */
};

class SinglyLinkedList {
	private:
		int size = 0;
		Node *initial;
	public:
		SinglyLinkedList() : size(0), initial(NULL){}
		Node * get_initial();
		void set_initial(Node * n){ initial = n; }
		void add(int);
		void remove(int);
		int get(int);
		int sz();
} sll;

Node * SinglyLinkedList::get_initial(){ return initial; }

int SinglyLinkedList::get(int index){
	int ret;
	if (index == 0){ ret = (sll.get_initial()->get_data()); }
	else {
		Node * curr = sll.get_initial();
		for (int i = 0; i <= index; i++){
			if (i == index) { ret = curr->get_data(); }
			else { curr = curr->get_next();}
		}
	}
	return ret;
}

void SinglyLinkedList::add(int data){
	Node *pn = new Node(data);
	if (sll.sz() == 0){ sll.set_initial(pn);  std::cout << sll.get_initial()->get_data() << " is the data" << std::endl; sll.size++; }
	else {
		Node * curr = sll.get_initial();
		while (curr->get_next() != NULL){
			curr = curr->get_next();
		}
		curr->set_next(pn);
		sll.size++;
		std::cout << pn->get_data() << " is the data" <<std::endl;
	}
}

void SinglyLinkedList::remove(int index){
	Node * curr = sll.get_initial();
	Node * last;
	if (index == 0 && sll.get_initial()->get_next() == NULL) { delete sll.get_initial(); }
	else if (index == 0 && sll.get_initial()->get_next() != NULL) {
		sll.set_initial(sll.get_initial()->get_next());
		delete curr;
	}
	for (int i = 1; i <= index; i++){
		if (i == index) {
			if (curr->get_next() == NULL){ delete curr; }
			else{
				curr = curr->get_next();
			}
		}
		last = curr;
		curr = curr->get_next();
	}
	sll.size--;
}

int SinglyLinkedList::sz(){ return sll.size; }

int main(){
	sll.add(3);
	sll.add(5);
	sll.add(10);
	sll.add(7);
	sll.add(44);
	std::cout << sll.sz() << " is the size." << std::endl;
	for (int i = 0; i <= sll.sz(); i++){ std::cout << sll.get(i) << ","; }
	return 0;
}
