// Addition Lab
// COSC140
// This lab adds up linked lists
// Swasti Mishra
// 03/17/21
// Trish Nguyen, Katie Nuchols, Josh Mandzak

# include "list.h"
# include <iostream> 
# include <string>
# include <algorithm>

using namespace std ;

List::List(){
    head = new Node;
    head -> next = nullptr;
}   // constructor

List::~List(){
    Node *i , *n ;
    i = head -> next ;
    head -> next = nullptr ;
    while ( i != nullptr) {
        n = i ;
        i = i -> next ;
        delete n ;
    }
}   // destructor

void List::push( int i ){
    Node *n , *j ;
    j = head ;
    while ( j -> next != nullptr ) j = j-> next ;
    n = new Node ;
    n -> i = ( i ) ;
    n -> next = nullptr ;
    j -> next = n ;
}   // pushes values into the node.
    // also verbatim, pretty much, from Matt's code

void List::print( Node* j ){
    j = head ;
    string out ;
    while( j != nullptr ){
        char c ;
        c = '0' + j -> i ;
        j = j -> next ;
        out += c ;
    }
    reverse ( out.begin(), out.end() ) ;
    out.pop_back() ;
    cout << out << '\n' ;
}   // print function!! massive headache!
    // the '0' is supposed to, like, neutralize the number
    //      the same way it does in the main, but it doesn't
    //      work properly here for some reason. 

