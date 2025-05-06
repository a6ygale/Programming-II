#include <iostream>
#include <vector>
using namespace std; 

int checkPath(int node,vector<vector<int>>& AdjMatrix) {
    //if on B node, return
    if (node == 1) return 0; 

    int maxLen = 0;
    //check all outputs of node, if there's a 1 in box
    //recursively go down path and add to length
    for(int next = 0; next<AdjMatrix.size(); next++){
        if(AdjMatrix[node][next] == 1){
            int latency = checkPath(next, AdjMatrix);

            //if its not the input or output node, add to 
            //total latency of path
            if(next != 1 && next != 0){
                latency = latency+ 1;
            }

            //if the latency found is greater than current recorded, 
            //replace value
            if(latency > maxLen){
                maxLen = latency;
            } 
        }
    }

    return maxLen;
}

int circuitLatency(vector<vector<int>> AdjMatrix, int vertices){
    //case if less than 2 vertices
    if (vertices < 2 ){
        return -1; 
    }
    
    return checkPath(0,AdjMatrix); 

}

//test code
// int main(){
//     vector<vector<int>> adj = 
//     {{0, 0, 1, 1, 1, 1},
//     {0, 0, 0, 0, 0, 0},
//     {0, 1, 0, 0, 1, 0},
//     {0, 1, 1, 0, 0, 0},
//     {0, 1, 0, 0, 0, 0},
//     {0, 0, 1, 0, 0, 0}}; 

//     cout<<circuitLatency(adj,6); 

//     return 0; 
// }