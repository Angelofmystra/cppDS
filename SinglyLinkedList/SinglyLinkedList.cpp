// SinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Node {
	private:
		int data;
		Node *next;
	public:
		Node(int a) : data(a), next(NULL){} /* Legacy to use NULL */
		int get_data(){ return data; }
		Node* get_next(){ return next; }
};

class SinglyLinkedList {
	private:
		int size;
		Node *initial;
	public:
		SinglyLinkedList() : size(0), initial(NULL){}
		Node * get_initial();
		void add(int);
		void remove(int);
		int get(int);
		int sz();
} sll;

Node * SinglyLinkedList::get_initial(){ return initial; }

int SinglyLinkedList::get(int index){
	if (index == 0){ return (sll.get_initial().get_data()); }
	else {
		Node * curr = sll.get_initial();
		for (int i = 0; i <= index; i++){
			if (i == index) { return curr.get_data(); }
			else { Node * curr = sll.get_initial().get_next();}
		}
	}
}

void SinglyLinkedList::add(int data){
	Node n(data);
	if (sll.sz() == 0){ *initial = n; }
	else {
		Node * curr = sll.get_initial();
		while (curr != NULL){ Node * curr = sll.get_initial().get_next(); }
		curr = &n;
		sll.size++;
	}
}

void SinglyLinkedList::remove(int index){
	Node * curr = sll.get_initial();
	Node * last;
	if (index == 0 && sll.get_initial().get_next() == NULL) { curr.get_next() = NULL; }
	else if (index == 0 && sll.get_initial().get_next() != NULL) {
		sll.get_initial() = sll.get_initial().get_next();
	}
	for (int i = 1; i <= index; i++){
		if (i == index) {
			if (curr.get_next() == NULL){ curr = NULL; }
			else{
				curr = curr.get_next();
			}
		}
		last = curr;
		curr = curr.get_next();
	}
	sll.size--;
}

int SinglyLinkedList::sz(){ return sll.size; }

int main(){
	return 0;
}
