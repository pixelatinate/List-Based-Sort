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
	//Node *left = NULL;
	//Node *right = NULL;
	//call partition to divide list
	//partition(head, pivot, left, right, numeric)
	//concatenate(left, right);
	//qsort(head, numeric);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node *current = head;
	Node *prev = NULL;
	Node *leftHead, *rightHead;
	//base cases
	
	//looking through list
	while(current->next != NULL){
		if(numeric){
			if(node_number_compare(current, prev)){
				left->next = prev;
			} else
				right->next = prev;
		} else {
			if(node_string_compare(current, prev))
				left->next = prev;
			else
				right->next = prev;
		}
		prev = current;
		current = current->next;		
	}

		
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
