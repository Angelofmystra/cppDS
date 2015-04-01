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
			else { Node * curr = sll.get_initial()->get_next();}
		}
	}
	return ret;
}

void SinglyLinkedList::add(int data){
	Node n(data);
	Node *pn = &n;
	if (sll.sz() == 0){ std::cout << "print";  sll.set_initial(pn); sll.size++; std::cout << "2nd print" << sll.sz() << std::endl; }
	else {
		Node * curr = sll.get_initial();
		while (curr->get_next() != NULL){
			curr = curr->get_next();
		}
		curr->set_next(pn);
		sll.size++;
		std::cout << sll.get_initial()->get_data() << " is the data" <<std::endl;
	}
}

void SinglyLinkedList::remove(int index){
	Node * curr = sll.get_initial();
	Node * last;
	if (index == 0 && sll.get_initial()->get_next() == NULL) { curr->set_next(NULL); }
	else if (index == 0 && sll.get_initial()->get_next() != NULL) {
		sll.set_initial(sll.get_initial()->get_next());
	}
	for (int i = 1; i <= index; i++){
		if (i == index) {
			if (curr->get_next() == NULL){ curr = NULL; }
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
	sll.add(1);
	int v = sll.get_initial()->get_data();
	std::cout << "v is: " << v << std::endl;
	sll.add(5);
	sll.add(10);
	sll.add(7);
	for (int i = 0; i <= sll.sz(); i++){ std::cout << sll.get(i) << ","; }
	return 0;
}
