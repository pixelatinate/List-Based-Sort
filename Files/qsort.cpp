// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

void qsort_sort(List &l, bool numeric) { 
    vector<Node *> numbers ;                                                 //create a vector for storing
    Node *main = l.head;
    Node **qArray ;

    int length = findlength(l);                                             //get the length of the list
    for(int i = 0; i < length; i++){                                        //find all of the elements in the list and store in a vector
        numbers.push_back(main);
        main = main->next;                                                  //go to the next element in the file
    }
    qArray = new Node*[ length ] ;

    for ( unsigned int i = 0 ; i < numbers.size() ; i++ ){
        qArray[ i ] = numbers[ i ] ;
    }

    if(numeric){
        qsort(qArray, length, sizeof( qArray[0] ), c_node_number_compare) ;          //use the compare function and the qsort to run through the vector
    }
    else{
        qsort(qArray, length, sizeof( qArray[0] ), c_node_string_compare) ;          //use the compare function and the qsort to run through the vector
    }

    l.head = qArray[0];                                                    //get the head of the function
    for(int i = 1; i <= length; i++){                                        //iterate through the vector and output information
        qArray[i]->next = qArray[i];
        if(i == length-1){
            qArray[i]->next = NULL;                                        //at end of file set nullptr
        }
    }
}