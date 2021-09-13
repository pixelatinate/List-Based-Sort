// merge.cpp

#include "volsort.h"

#include <iostream>

using namespace std;
// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

// Performs the merge sort algorithm
void merge_sort(List &l, bool numeric) {
	msort(l.head, numeric);
}

// Recursive - Calls split to divide and calls merge to conquer
// Returns new head
Node *msort(Node *head, bool numeric) {
	Node* left;
	Node* right;

	// Handles if list length is <= 1
	if ((head == NULL) || (head->next == NULL))
		return head;
	
	split(head, left, right);
	left = msort(left, numeric);
	right = msort(right, numeric);
	merge(left, right, numeric);
	return head;
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
	left = head;
	right = slow->next;
	slow->next = NULL;
}

// Combines left and right lists and returns the new head
Node *merge(Node *left, Node *right, bool numeric) {
	Node* sorted = NULL;

	// Handles if either node is empty
	if (left == NULL)
		return right;
	else if (right == NULL)
		return left;

	while(left != NULL && right !=NULL){
		if(left <= right){
			sorted = left;
			sorted->next = right;
		}
		else
			sorted = right;
		sorted->next = left;
	}
	return sorted;
}


