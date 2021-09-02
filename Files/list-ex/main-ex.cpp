// Addition Lab
// COSC140
// This lab adds up linked lists
// Swasti Mishra
// 03/17/21
// Trish Nguyen, Katie Nuchols, Josh Mandzak

# include <iostream>
# include <algorithm>
# include "list.h"

using namespace std ;

int sum ( Node* list1 , Node* list2 ) {
    List resulting ;
    string output ;
    int result = 0 ;
    int carry = 0 ;

    list1 = list1 -> next ;
    list2 = list2 -> next ;
    while( ( list1 != nullptr ) || ( list2 != nullptr ) ){
        if ( list1 != nullptr ){
            result += ( list1 ->  i ) ;
            list1 = list1 -> next ; 
        }
        if ( list2 != nullptr ){
            result += ( list2 -> i ) ;
            list2 = list2 -> next ;
        }
        // these two loops account for the lists being of
        //      different lengths 

        result = carry + result ;
        carry = 0 ;

        if ( result >= 10 ){
            resulting.push( result % 10 ) ;
            carry = result / 10 ;
        }
        else {
            resulting.push( result ) ;
        }
        // accounts for the numbers that need to be carried
        
        result = 0 ;
        // resets the result to zero
    }

    if ( carry != 0 ){
        resulting.push( carry ) ;
    }
    // if there is leftover in the carry, it appends it to the beginning

    resulting.print( resulting.head -> next ) ;
}   // the sum function!

int main(int argc, char *argv[]) {

    string firstString ;
    string secondString ;
    List list1 ;
    List list2 ;
    Node* result = NULL ;

    while ( cin >> firstString ){
        reverse( firstString.begin(), firstString.end() ) ;
        for ( char c: firstString ){
            list1.push( c - '0' ) ;
        }   // pushes into the first list
        cin >> secondString ;
        reverse( secondString.begin(), secondString.end() ) ;
        for ( char c: secondString ){
            list2.push( c - '0' ) ;
        }   // pushes into the second list
            
        sum( list1.head , list2.head ) ;   
        list1.~List() ;
        list2.~List() ;
        // deletes the lists at the end of the loop
    }   
    return 0;
}
