// merge.cpp

#include "volsort.h"
#include<iostream>
// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

// Performs the merge sort algorithm
void merge_sort(List &l, bool numeric) {
	l.head=msort(l.head, numeric);
}

// Recursive - Calls split to divide and calls merge to conquer
// Returns new head
Node *msort(Node *head, bool numeric) {
	Node* left;
	Node* right;
	for(Node* temp=head; temp!=NULL; temp=temp->next)
		std::cout<< temp->number<<std::endl;
	std::cout<<std::endl;	
	// Handles if list length is <= 1
	if ((head == NULL) || (head->next == NULL))
		return head;

	split(head, left, right);
	left = msort(left, numeric);
	right = msort(right, numeric);
	merge(left, right, numeric);
//	cout<<"in recursive function";
	std::cout<<"after merge \n";
	for(Node* temp=head; temp!=NULL; temp=temp->next)
		std::cout<< temp->number<<std::endl;
	std::cout<<std::endl;	
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
	Node* head=NULL;
	// Handles if either node is empty
	if (left == NULL)
		return right;
	else if (right == NULL)
		return left;

	while(left!=NULL && right!=NULL){
//		cout<<"in while loop";
		if(sorted==NULL){
			if(numeric){
				if(node_number_compare(left,right)){
					sorted = left;
					head=sorted;
					left=left->next;
				}
				else{
					sorted = right;
					head=sorted;
					right=right->next;
				}
			}			
			else{	
				if(node_string_compare(left, right)){
					sorted = left;
					head=sorted;
					left=left->next;
				}
				else{
					sorted = right;
					head=sorted;
					right=right->next;
				}		
			}	
		}
		else{
			if(numeric){
				if(node_number_compare(left,right)){
					sorted->next = left;
					left = left->next;
				}
				else{
					sorted->next=right;
					right=right->next;
				}
				sorted=sorted->next;
			}
			else{
				if(node_string_compare(left,right)){
					sorted->next = left;
					left = left->next;
					
				}
				else{
					sorted->next=right;
					right=right->next;
				}
				sorted=sorted->next;
			}	
		}
	
	}
	//Checks for a final node containing a value
	if(left != NULL)
		sorted->next=left;
	else
		sorted->next=right;

	return head;
}

