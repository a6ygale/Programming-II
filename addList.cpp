#include <iostream>
using namespace std; 

//creates node structure
struct Node {
    //to hold an integer value at each point
    int num; 

    //to hold the link to next node
    Node* next; 
};


//function that adds all values in a linked list
int addList(Node* head){
    //start sum variable at zero
    int sum = 0; 

    //holds current position in linked list when
    //going through values to sum
    Node* index = head; 

    //calls each value at each node until it hits end and
    //adds to sum variable
    while (index != NULL){
        sum = sum + index->num; 
        index = index->next; 
    }

    return sum; 
};


int main(){
    Node* fir = new Node(); 
    fir->num = 1; 
    
    Node* sec = new Node(); 
    sec->num = 2; 
     
    Node* thr = new Node(); 
    thr->num = 3; 
     
    Node* four = new Node(); 
    four->num = 4; 
     

    fir->next = sec; 
    sec->next = thr;
    thr->next = four;
    four->next = NULL;
    
    cout<<addList(fir);

    return 0; 
}
