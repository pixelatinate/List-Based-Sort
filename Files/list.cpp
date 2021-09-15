#include "volsort.h"
#include <iostream>

List::List() {
    head = NULL;
    size = 0;
}

List::~List() {
    Node *curr = head;
    while(curr != 0){
        Node *next = curr->next;
        delete curr;
        curr = next;
    } 
    head = 0;
}
void List::push_front(const std::string &s){
  /*  int value = stoi(s);
    Node *newnode , *start;
    start = head;
    while (start -> next != NULL) 
    start = start-> next ;
    newnode = new Node ;
    newnode -> number = (value);
    newnode -> string = s;
    newnode -> next = NULL;
    start -> next =  newnode;
	*/
	if(head==NULL)
	{
		head = new Node;
		head->string = s;
		head->number=stoi(s);
		size=1;
	}
	else{
		Node* newnode = new Node;
		newnode->string = s;
		newnode->number = stoi(s);
		Node* temp = head;
		newnode->next = temp;
		head = newnode;
		head->next = temp;
		size++;
	}
}

bool node_number_compare(const Node *a, const Node *b){
/*  int lengthA = sizeof(a);
  int lengthB = sizeof(b);

  if(lengthA > lengthB){
    return true;
  }
  else if(lengthB > lengthA){
    return false;
  }
      while (a != NULL && b != NULL) {
        if (a->number > b->number)
            return true;
        else if (a->number < b->number)
            return false;
        a = a->next;
        b = b->next;
    }
    return false;
	*/
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b){
  /*int lengthA = sizeof(a);
  int lengthB = sizeof(b);

  if(lengthA > lengthB){
    return true;
  }
  else if(lengthB > lengthA){
    return false;
  }
      while (a != NULL && b != NULL) {
        if (a->string > b->string)
            return true;
        else if (a->string < b->string)
            return false;
        a = a->next;
        b = b->next;
    }
    return false;
	*/
	return a->string < b->string;
}
int c_node_number_compare(const void *a, const void *b){
  return ( ( Node* ) a )->number < ( ( Node* ) b )->number ; 
}

int c_node_string_compare(const void *a, const void *b){
	return ( ( Node* ) a )->string < ( ( Node* ) b )->string ;
}

void dump_node(Node *n){					// implement in this file (volsort.h) to make it easier for TAs to grade
  while(n != NULL){
	 std::cout << "int: " << n->number << std::endl;
	 std::cout << "string: " << n->string << std::endl;
	n = n->next;
  }
}

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation
