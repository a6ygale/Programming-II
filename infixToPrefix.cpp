
/*///////////////////////////////////////////////////////////////////////////////
    Objective:  create a function that takes in a char type equation
            and returns it's equivalent prefix expression. Utilizing 
            LIFO property of stacks to call back operators in new order. 

    Parameters: char epression[]: an array of character values written out
            in infix notation

*///////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////
//                          import libraries
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std; 



///////////////////////////////////////////////////////////////////////
//                  initializing customized stack class    
///////////////////////////////////////////////////////////////////////

class Stack{
    private:   
        char* ex; 
        int capacity; 
        int top; 

    public: 
        Stack(int size = 100) {
            capacity = size;
            ex = new char[capacity];  
            top = -1;               
         }
        char push(char); 
        char pop(); 
        int isEmpty(); 
        int isFull(); 
        char checkTop();
}; 

/////////////////////////////////////////////////////////////////////////////////
//    defining methods of class to access private variables from outside
/////////////////////////////////////////////////////////////////////////////////

int Stack::isEmpty(){
    return(int(top==-1));
}

int Stack::isFull(){
    return(int(top==(99)));
}

char Stack::push(char n){
    if(isFull()){
        return 0; 
    }
    top=top+1; 
    ex[top] = n; 
    return n; 
}

char Stack::pop(){
    int temp; 
    if(isEmpty()){
            return 0; 
    }
    temp = ex[top]; 
    top=top-1; 
    return temp; 
}

//////////////////////////////////////////////////////////////////////////////
//             accessing private variable, last added element, in funct
//////////////////////////////////////////////////////////////////////////////

char Stack::checkTop(){
    if(isEmpty()){
        return 0; 
    }
    return ex[top]; 

}

/////////////////////////////////////////////////////////////////////////////
//             checking that expression follows order of operations
/////////////////////////////////////////////////////////////////////////////

int orderOfOp(char op){
    if(op =='^'){
        return 3; 
    }
    if(op == '*' || op == '/'){
        return 2; 
    }
    if(op =='+' || op == '-' || op == ')'){
        return 1; 
    }
    else{
        return -1; 
    }
}



////////////////////////////////////////////////////////////////////////////
//         Function that takes infix expression and converts to prefix
////////////////////////////////////////////////////////////////////////////

void infixToPrefix( char expression[]){

    //going to need this value later
    int n = strlen(expression); 

    //first check for operator
    Stack operators; //using FIFO of stack to correctly order operators
    string prefix="";//storing new expression
    int j=0; //controls indexing on new expression
    int new_n=n; //size of new array without paranth

    //reverse infix expression
    for(int i=0; i < n/2; i++){
        char temp2 = expression[i]; 
        expression[i] = expression[n-i-1]; 
        expression[n-i-1] = temp2; 
        
    }
    


    //looping through each element and sorting based on cases
    for(int i=0; i< n ; i++){
        //if its a digit, add it to the new expression normally
        if(isdigit(expression[i])){
            prefix += expression[i]; 
        }

        //will need to add ) so that when we run into (
        //we can pop all operators in parenthesis
        else if (expression[i] == ')'){
            operators.push(expression[i]);  
        }

        //if we run into end of parenthesis, 
        //we have to push out operators into expression
        else if (expression[i] == '('){
            new_n-=1; //removed a character, 1 less return element

            while(operators.checkTop() != ')' && !operators.isEmpty()){
                
                prefix+=operators.pop();
 
            }

            //take out other associated parenthesis )
            //marking end of pulling out operators
            operators.pop(); 
            new_n-=1; //removed a character, 1 less return element
        }



        else{
            //case for operators
            while(orderOfOp(expression[i])<orderOfOp(operators.checkTop()) && !operators.isEmpty()){
                prefix += operators.pop(); 
            }
            operators.push(expression[i]); 
        }
  
    }
   


    //after reading through entire expression, 
    //add remaining operators to the end in FIFO sequence
    while(!operators.isEmpty()){
        prefix += operators.pop(); 
    }
    

    
    //reverse the expression back
    for(int i=0; i < new_n/2; i++){
        char temp2 = prefix[i]; 
        prefix[i] = prefix[new_n-i-1]; 
        prefix[new_n-i-1] = temp2; 
        
    }
    

    //redefining the initial array
    for (int i=0; i < new_n; i++){
        expression[i] = prefix[i]; 
    }
    
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TESTING
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
int main() {

    char eq_1[] = "(3+((4+5)*2))"; 
    //expected output  = +3∗+452

    int t = strlen(eq_1) - 6; //final expression will exclude parenthesis

    infixToPrefix(eq_1); //rearange to prefix


    //printing results
    cout<<endl<<"prefix = ";
    for(int i = 0; i < t; i++) {
        cout << eq_1[i]; 
    }
    cout  << endl; 

}

*/