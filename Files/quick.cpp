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
	qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
	Node *pivot = head;
	//base case size 0 or 1 for list
	if(head == NULL or head->next == NULL)
		return head;
	Node *left = NULL;
	Node *right = NULL;
	//call partition to divide list
	partition(head, pivot, left, right, numeric);
	//need to add pivot to one of the lists before concatenate
	concatenate(left, right);
	//qsort(left half, numeric);
	//qsort(right half, numeric);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node *current = pivot->next;
	Node *tmp;
	Node *leftHead, *rightHead;
	
	//looking through list
	while(current->next != NULL){
		if(numeric){
			if(node_number_compare(pivot, current)){
				if(left == NULL){
					leftHead = current;
					left = current;
				} else
					left->next = current;
			} else {
			 	if(right == NULL){
					rightHead = current;
					right = current;
				} else {
					right->next = current;
				}
			}
		} else {
			if(node_string_compare(pivot, current)){
				if(left == NULL){
					leftHead = current;
					left = current;
				} else
					left->next = current;
			} else {
			 	if(right == NULL){
					rightHead = current;
					right = current;
				} else {
					right->next = current;
				}
			}
		}
		//increment
		current = current->next;

	}
	//update left and right sublists so pivot is in place
		
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
