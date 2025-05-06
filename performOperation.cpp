#include <iostream>
using namespace std; 

struct Operation {
    int ProcessTime;
    Operation* next ;
};


 Operation* performOperation(Operation* queue){
    //holds current position in linked list when
    //going through values to find end
    Operation* index = queue; 

    //calls each value at each node until it hits the index
    //before last operation
    while (index->next->next != nullptr){ 
        index = index->next; 
    }

    //remove the link from 2nd to last to last element and replace with null
    delete index->next; 
    index->next = nullptr; 

    //return head value
    return queue; 
 }