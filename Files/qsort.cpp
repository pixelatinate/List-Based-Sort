// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
# include <vector>

int findlength(List &head)
{
    int length = 0;
    Node *main = head.head;                                                 //start at the top of the list
    while(main != NULL){                                                    //while there is information to get cycle through
        length++;
        main = main->next; 
    }
    return length;                                                          //return the length of the list
}

void qsort_sort(List &l, bool numeric) { 
    vector<Node *> numbers;                                                 //create a vector for storing
    Node *main = l.head;
    int length = findlength(l);                                             //get the length of the list
    for(int i = 0; i < length; i++){                                        //find all of the elements in the list and store in a vector
        numbers.push_back(main);
        main = main->next;                                                  //go to the next element in the file
    }
    if(numeric){
        qsort(numbers.begin(), numbers.end(), node_number_compare);          //use the compare function and the qsort to run through the vector
    }
    else{
        qsort(numbers.begin(), numbers.end(), node_string_compare);          //use the compare function and the qsort to run through the vector
    }

    l.head = numbers[0];                                                    //get the head of the function
    for(int i = 1; i < length; i++){                                        //iterate through the vector and output information
        numbers[i-1]->next = numbers[i];
       if(i == length-1){
            numbers[i]->next = NULL;                                        //at end of file set nullptr
        }
    }
}