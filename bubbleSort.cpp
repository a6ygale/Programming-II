#include <iostream>
using namespace std; 

/////////////////////////////////////////////////////////////
//  write a function to bubble sort array in descending order
////////////////////////////////////////////////////////////

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


