// quick.cpp
// worked on by Carter Earheart-Brown
// implements quick sort using a linked list using a divide and conquer strategy

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
	//base case size 0 or 1 for list
	if(head == NULL or head->next == NULL)
		return head;
	
	Node *left = NULL;
	Node *right = NULL;
	//call partition to divide list
	partition(head, pivot, left, right, numeric);
	left = qsort(left,numeric);
	right = qsort(right,numeric);
	//attatching pivot as head of left so it can be detached and used in concatenate
	pivot->next = left;
	return concatenate(pivot, right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node *current = head->next;
	Node *leftPos = NULL;
	Node *rightPos = NULL;

	
	//looking through list
	while(current != NULL){
		if(numeric){
			if(node_number_compare(current, pivot)){
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
			if(node_string_compare(current, pivot)){
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
		}
		//increment
		current = current->next;
	}
	//update end of left and right sublists
	//check if left and right are empty 
	if(leftPos != NULL)
		leftPos->next = NULL;
	if(rightPos != NULL)
		rightPos->next = NULL;
		
}

//joins left and right sublists
Node *concatenate(Node *left, Node *right) {
	//takes pivot off of left 
	Node *pivot = left;
	left = left->next;
	Node *leftPos = left;
	//cases of left and right sublists being empty
	if (left == NULL){
		pivot->next = right;
		return pivot;
	}	
	//finds end of left list
	while(leftPos->next != NULL)
		leftPos = leftPos->next;
	//joins last element of left to first element of right
	leftPos->next = pivot;
	leftPos->next->next = right;
	return left;
}
