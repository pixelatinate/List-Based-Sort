// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
}

Node *msort(Node *head, bool numeric) {
	Node* left;
	Node* right;

	// Handles if list length is <= 1
	if ((head == NULL) || (head->next == NULL))
		return;

	split(head, &left, &right); 
	merge(&left, &right);
	return &head;
}

// Splits the list
void split(Node *head, Node *&left, Node *&right) {
	
	Node* slow;
	Node* fast;
	slow=head;
	fast=head->next;
	
	// Finds the middle of the list
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	// Splits list in two at middle
	*left = head;
	*right = slow->next;
	slow->next = NULL;
}

// Sorts the list
Node *merge(Node *left, Node *right, bool numeric) {
	Node* sorted = NULL;

	// Handles if either node is empty
	if (left == NULL)
		return right;
	else if (b == NULL)
		return left;

	if(left->data <= right->data){
		sorted = left;
		sorted->next = merge(left, right->next);
	}
	return sorted;
}


