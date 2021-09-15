// qsort.cpp
// Worked on by Swasti Mishra

# include "volsort.h"

# include <vector>
# include <iostream>

using namespace std ;

void qsort_sort( List &l, bool numeric ) { 
    
    // Variables
    Node *main = l.head ;
    vector<Node *> numbers ;

    // Finds length of the list. We don't have to define it again
    int length = findlength( l ) ;

    // Pushes the list into a vector
    for(int i = 0; i < length; i++){
        numbers.push_back( main ) ;
        main = main->next ;
    }
    
    // Compares using c-style compares and qsort
    if( numeric ){
        qsort( &numbers[0] , numbers.size() , sizeof( Node* ) , c_node_number_compare ) ;
    }
    else{
        qsort( &numbers[0] , numbers.size() , sizeof( Node* ) , c_node_string_compare ) ;
    }

    // Finds the head of the function and sets the iterator
    l.head = numbers[0] ;

    // Iterates through and pushes to list
    for( int i = 1 ; i < length ; i++ ){
        numbers[ i-1 ]->next = numbers[ i ] ;
       
       // Account for the last item in the list
       if( i == ( length-1 ) ){
            numbers[i]->next = NULL ;
        }
    }

}