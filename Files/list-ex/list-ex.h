// Addition Lab
// COSC140
// This lab adds up linked lists
// Swasti Mishra
// 03/17/21
// Trish Nguyen, Katie Nuchols, Josh Mandzak

# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <string>

typedef struct node_s {
    int i ;
    struct node_s *next ;
} Node ;

class List {
    public:
        List() ;
        ~List() ;
        List& operator=( const List& );
        void push( int i );
        void print( Node* j ) ;
        Node *head;
        
} ;
// This list is verbatim from Matt's code. 
// I did move the Node *head inside the public section,
//      though. I was getting some weird errors without it 
