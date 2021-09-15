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
	l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
	Node *pivot = head;
	Node *leftSorted, *rightSorted;
	Node *sorted;
	//base case size 0 or 1 for list
	if(head == NULL or head->next == NULL)
		return head;
	Node *left = NULL;
	Node *right = NULL;
	//call partition to divide list
	partition(head, pivot, left, right, numeric);
	leftSorted = qsort(left,numeric);
	rightSorted = qsort(right,numeric);
	//need to add pivot to one of the lists before concatenate
	sorted = concatenate(leftSorted, rightSorted);
	return sorted;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node *current = pivot->next;
	Node *leftPos, *rightPos;
	Node *tmp;
	
	//looking through list
	while(current->next != NULL){
		if(numeric){
			if(node_number_compare(pivot, current)){
				if(left == NULL){					
					left = current;
					leftPos = current;
				} else {
					leftPos->next = current;
					leftPos = leftPos->next;
				}
			} else {
			 	if(right == NULL){
					right = current;
					rightPos = current;
				} else {
					rightPos->next = current;
					rightPos = rightPos->next;
				}
			}
		} else {
			if(node_string_compare(pivot, current)){
				if(left == NULL){
					left = current;
					leftPos = current;
				} else {
					leftPos->next = current;
					leftPos = leftPos->next;
				}
			} else {
			 	if(right == NULL){
					right = current;
					rightPos = current;
				} else {
					rightPos->next = current;
					right = rightPos->next;
				}
			}
		}
		//increment
		current = current->next;
	}
	//update end of left and right sublists and put pivot in place
	//want to put pivot where rightHead is
	left->next = NULL;
	right->next = NULL;
	tmp = right;
	right = pivot;
	right->next = tmp;
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
