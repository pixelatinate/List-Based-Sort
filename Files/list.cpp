#include "volsort.h"


List::List() {
    head = new Node;
    head -> next = NULL;
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
    int value = stoi(s);
    Node *newnode , *start;
    start = head;
    while (start -> next != NULL) 
    start = start-> next ;
    newnode = new Node ;
    newnode -> number = (value);
    newnode -> string = s;
    newnode -> next = NULL;
    start -> next =  newnode;
}

bool node_number_compare(const Node *a, const Node *b){
  int lengthA = sizeof(a);
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
}

bool node_string_compare(const Node *a, const Node *b){
  int lengthA = sizeof(a);
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
}

void dump_node(Node *n){					// implement in this file (volsort.h) to make it easier for TAs to grade
  while(n != NULL){
    cout << "int: " << n->number << endl;
    cout << "string: " << n->string << endl;
    n = n->next;
  }
}

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation