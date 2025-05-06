#include <iostream>
#include <vector>
using namespace std; 

int getMin(vector<int> items){
    int i = 0; 
    int j = 0; 
    while(items.size()>j){
        //finding minimum by comparing values throughout vector
        if(items[i]>items[j]){
            i=j; 
        }
        
        j++; 
    }
    return i; //return index
}

int getOptimalMergeCost(vector<int> ropeSizes){
    //trick is to add lowest numbers first

    int totalCost = 0; //initialize cost variable
    

    //while theres more than one rope, keep merging
    while (ropeSizes.size() > 1) {
        //take out minimum value in vector
        int merge1 = getMin(ropeSizes); 
        int merge1_size = ropeSizes[merge1]; 
        ropeSizes.erase(ropeSizes.begin() + merge1); 

        //take out next minimum value in vector
        int merge2 = getMin(ropeSizes); 
        int merge2_size = ropeSizes[merge2];
        ropeSizes.erase(ropeSizes.begin() + merge2); 
        

        //merge them and count cost
        int mergeNew = merge1_size + merge2_size;
        totalCost = totalCost + mergeNew;

        //put new merged rope into vector
        ropeSizes.push_back(mergeNew); 
        
    }

    return totalCost;
    }


// int main(){
//     vector<int> ropes = {100, 300, 600, 500}; 
//     cout<<getOptimalMergeCost(ropes)<<endl; 

//     return 0; 
// }