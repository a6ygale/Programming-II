#include <iostream>
#include <vector>
using namespace std; 

///////////////////////////////////////////////////////////////
//  (greedy alg) find minimum amount of coins to give back using
//  double int of change required and array of denominations. 
//////////////////////////////////////////////////////////////

void minimumCoins(double change, int* arr){
    int cents = change*100; //finds value of change in cents
    int denominations[5] = {100,25,10,5,1}; //value of coin at each respective arr index

    int i = 0; 
    while (cents!=0){//while more money is still needed
        arr[i] = cents / denominations[i]; //find how many times larger coin can go into value
        cents = cents-arr[i]*denominations[i]; //remove that value, coins alr added
        i++; 
    }

}

// int main(){
//     int coins[5] = {0,0,0,0,0}; 
//     minimumCoins(0.74, coins); 

//     int k=0; 
//     while(k< 5){
//         cout<<coins[k]<<endl; 
//         k++; 
//     }
// }
