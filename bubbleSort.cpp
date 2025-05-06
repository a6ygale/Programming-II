#include <iostream>
using namespace std; 


//problem 4 
//a 
int i, j, tmp; 
void bubbleSort( int nums[ ], int n ){
    //looping through all elements
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++)
            if (nums[j]<nums[j+1]) { 
                //create a temporary variable to store j+1 while overwriting
                tmp = nums[j+1];

                //swap values so that greater # comes first 
                nums[j+1] = nums[j]; 
                nums[j] = tmp;
            }
        }
}



int main(){
    char ex_1[] = "(3+((4+5)*2))"; 
    //char ex_1[] = "(4-(6/3))*((4/2)-5)"; 
    int t = strlen(ex_1)-6; 

    infixToPrefix(ex_1); 

    for (int i=0; i<t; i++){
        cout<<ex_1[i]<<endl; 
    }
        
    return 0; 
}