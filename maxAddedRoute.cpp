#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

///////////////////////////////////////////////////
//  Takes heap tree root node and traverses to find
//  the highest sum resulting from addition of
//  traversed node values
///////////////////////////////////////////////////

struct Node {
    int data;
    int length = 0; 
    Node* left;
    Node* right;

    };

int getMax(vector<int> items){
    int i = 0; 
    int j = 0; 
    while(items.size()>j){
        //finding minimum by comparing values throughout vector
        if(items[i]<items[j]){
            i=j; 
        }
        
        j++; 
    }
    return items[i]; //return index
}


int maxAddedRoute(Node* root){
    vector<int> totals; 
     
    std::stack<Node*> s;
    s.push(root);
    root->length = root->data; 

    while (!s.empty()) {
    // Pop node from stack to process
    Node* curr = s.top();
    s.pop();

    //tests current node information
    //cout<<curr->data<<endl<<curr->length<<endl<<endl;  


    // Push right child first so that left is processed first
    // (right will only be processed once all subtrees in left are processed)
    if (curr->right) {
        s.push(curr->right);
        curr->right->length = curr->right->data + curr->length; 
    }

    if (curr->left) {
        s.push(curr->left);
        curr->left->length = curr->left->data + curr->length; 
    }

    //if no children add as path length
    if(!curr->left && !curr->right){
        totals.push_back(curr->length); 
        
    }

    }

    //find the longest path and return
    return getMax(totals); 
}
    

/* test code
int main(){
    struct Node* root = new Node(25);
    root->left = new Node(17);
    root->left->left = new Node(10);
    root->left->right = new Node(8);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(9);

    root->right = new Node(20);
    root->right->right = new Node(15);
    root->right->left = new Node(12);

    cout<< maxAddedRoute(root)<<endl; 


    return 0 ; 
}*/
