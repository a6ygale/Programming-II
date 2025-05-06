#include <iostream>
using namespace std; 

////////////////////////////////////////////////////
// function to remove duplicated int in sorted array
///////////////////////////////////////////////////

int deduplicate(int nums[], int n){
    
    for(int i=0; i<n; i++){

        //if one number is equal to its next number, 
        //move all other numbers up to overwrite it
        if (nums[i] == nums[i+1]){

            for (int j=i; j<n; j++){
                nums[j] = nums[j+1];  
            }

            //resizing callback of array, since we
            //essentially overwrote one element
            n=n-1; 

            //go back to recheck the next value isnt
            //also a repeat
            i = i-1; 
        }
    }
    
    return n; 

}
