#include <iostream>
#include <vector>
using namespace std; 

//absurdly large number to invalidate cases
//that arent optimal
int const INF = 1000000; 

vector<int> moves= {1,2,6,7}; 
vector<int> costs= {2,3,7,4}; 


//clears current position and two adjacent spots
void clear(int arr[], int pos, int n){
    if(pos-1>=0){ arr[pos-1] = 0; }
    if(pos+1<n){arr[pos+1] =0; }
    arr[pos] = 0; 
}

//checks if entire array is assigned zeros
bool done(int arr[], int n){
    for(int i = 0; i<n; i++){
        if (arr[i] == 1){ return false;}
    }
    return true; 
}

//reassigns original values to array before last clear
void undo(int arr[], int pos, int original[], int n) {
    if(pos - 1 >= 0) {arr[pos - 1] = original[pos - 1];}
    arr[pos] = original[pos];
    if(pos + 1 < n) {arr[pos + 1] = original[pos + 1];}
}

int findMin(int arr[], int n, int pos){
    //exit case if cleared
    if(done(arr,n)){return 0;} 
    //exit case if out of bounds
    if(pos>=n){return INF;}

    int minCost = INF; //start off with large case so smaller solutions can override

    //go through different combinations of moves and corresponding costs recursively
    for(int i = 0; i < 4; i++) {
        int nextPos = pos+moves[i];//move up from legal step sizes

        if (nextPos>= n) continue;//if we havent reched the end of array, keep going

        int original[1000]; 
        //copy array so we can retry different combos of moves
        for (int j = 0; j < n; j++){
             original[j] = arr[j];
        }

        clear(arr, nextPos, n);
        int cost = findMin(arr, n, nextPos) + costs[i];

        //takes moves with lowest total cost
        if (cost < minCost){
            minCost = cost;
        }

        //reverts back to last array to try other moves
        undo(arr, nextPos, original, n);
    }
    return minCost; 
}

int minCost(int arr[], int n){
    return findMin(arr,n,0); 
}


//test code
// int main(){
//     int arr[] = {1, 0, 1, 1, 0, 1};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     cout << minCost(arr,size) << endl;

//     return 0; 
// }