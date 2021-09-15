// list.cpp
// Worked on by all of us!

#include "volsort.h"
#include <iostream>
#include <string>

using namespace std ;

// Constructor
List::List() {
    head = NULL;
    size = 0;
}

// Destructor
List::~List() {
    Node *curr = head;
    while(curr != 0){
        Node *next = curr->next;
        delete curr;
        curr = next;
    } 
    head = 0;
}

// Push front function
void List::push_front(const std::string &s){
	if(head==NULL)
	{
		head = new Node;
		head->string = s;
		head->number=stoi(s);
		head->next = NULL;
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

// These two functions are used in stl sort for comparing nodes
bool node_number_compare(const Node *a, const Node *b){
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b){
	return a->string < b->string;
}

// These two functions are used in the c-style q sort
int c_node_number_compare(const void *a, const void *b){
  Node *aBuff = *( Node ** ) a ;
  Node *bBuff = *( Node ** ) b ;
  int aNumber = aBuff->number ;
  int bNumber = bBuff->number ;
  return aNumber - bNumber ;
}

int c_node_string_compare(const void *a, const void *b){
	Node *aBuff = *( Node ** ) a ;
  Node *bBuff = *( Node ** ) b ;
  string aString = aBuff->string ;
  string bString = bBuff->string ;
  return aString.compare( bString ) ;
}

// For Testing Purposes: Prints out all the integers and strings in a node
void dump_node(Node *n){
  while(n != NULL){
	 cout << "int: " << n->number << std::endl;
	 cout << "string: " << n->string << std::endl;
	n = n->next;
  }
}

// All the sorts!
void stl_sort(List &l, bool numeric);	  // define in stl.cpp    - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp  - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp  - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp  - your implementation
