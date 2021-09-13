// quick.cpp
// worked on by Carter Earheart-Brown

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	
	//qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
	Node *pivot = head;
	//Node *left = new Node;
	//Node *right = new Node;
	//call partition to divide list
	//partition(head, pivot, left, right)
	//call concatenate to conquer

}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
}

//joins left and right sublists
Node *concatenate(Node *left, Node *right) {
	Node *tmp = left;
	//cases of left and right sublists being empty
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;
	//finds end of first list
	while(tmp->next != NULL)
		tmp = tmp->next;
	//joins last element of left to first element of right
	tmp->next = right;
	return left;
}
