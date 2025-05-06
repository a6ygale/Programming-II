#include <iostream>
using namespace std; 


///////////////////////////////////////////////////////
//   function that checks if first linked list is
//   a subset of the second linked list input
///////////////////////////////////////////////////////

//creates node structure
struct Node {
    //to hold an integer value at each point
    int num; 

    //to hold the link to next node
    Node* next; 
};

bool isSublist(Node* head_1, Node* head_2){

    //variables to hould current position in each linked list
    Node* index_1 = head_1; 
    Node* index_2 = head_2; 

    //keeps track of if 2nd list achieves requirements
    //for sublist
    bool subset = true; 

    //holds position of larger while loop
    //when needing to check sublist internal loop
    Node* temp; 

    //looping through each value of first list
    while(index_1 != nullptr){

        //if we find value of first list that equals 
        //starting value of second list
        if (index_1->num == index_2->num){

            //hold position so we can go back if its a false positive
            temp = index_1; 

            //as long as we dont find a value thats unincluded
            //in list 1, and we're still within bounds of 2nd list
            //keep comparing
            while(index_2 !=nullptr && subset==true){
                //checks if next values of linked lists correspond
                subset = (index_1->num == index_2->num); 

                //continue on to next elements of each list to compare
                index_1 = index_1->next; 
                index_2 = index_2->next;  
            }


            //if it goes through all values of sublist and
            //they correspond with original list, return true
            if(subset == true && index_2 == nullptr){
                return 1; 
            }

            //if the subset wasn't a match, reset to top of
            //2nd list incase the number repeats to  
            //check later in sequence
            index_2 = head_2; 
            index_1 = temp; 
        }

        //if a match isn't found, go to next value of original list
        index_1 = index_1->next; 
    }

    //if all values of original list are checked, and they 
    //don't contain the sublist, return a false boolean
    return 0; 
}


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




    
    Node* sec_2 = new Node(); 
    sec_2->num = 2; 
     
    Node* thr_2 = new Node(); 
    thr_2->num = 1; 
     
    Node* four_2 = new Node(); 
    four_2->num = 4; 
     

    sec_2->next = thr_2;
    //thr_2->next = four_2;
    thr_2->next = NULL;
    
    cout<<isSublist(fir,sec_2);

    return 0; 
}
