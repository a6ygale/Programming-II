#include <iostream>
using namespace std; 

//structure containing operation variables
//of processing time and next item that it's linked to
struct Operation {
    int ProcessTime;
    Operation* next ;
    };


//op parameter is start of current operation linked list, 
//op_new is the added operation
Operation* addOperation(Operation* op, Operation* queue){
    op->next = queue; 
    return queue; 
}


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


 //function that adds all values in a linked list
int totalProcessingTime(Operation* queue){
    //start sum variable at zero
    int sum = 0; 

    //holds current position in linked list when
    //going through values to sum
    Operation* index = queue; 

    //calls each value at each node until it hits end and
    //adds to sum variable
    while (index != NULL){
        sum = sum + index->ProcessTime; 
        index = index->next; 
    }

    return sum; 
};
