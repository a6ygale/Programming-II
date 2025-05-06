#include <iostream>
using namespace std; 



void simplifySqrt(int radical[2],int divisor=-1){
    
    //initialize divisor value to smaller starting point
    if (divisor == -1){
        divisor = radical[1]/2; 
    }

    //if already checked all possible factor, or sqrt is
    //negative initially, break
    if (divisor<=1){
        return; 
    }

    //when a perfect square is found, simplify expression
    if ( radical[1] % (divisor * divisor) == 0){

        //pulling factor out to front of sqrt
        radical[0] = radical[0]*divisor; 

        //taking out factor from inside sqrt
        radical[1] = radical[1]/(divisor * divisor); 
    }

    //continues to check all possible descending factors
    simplifySqrt(radical, divisor-1); 

}
