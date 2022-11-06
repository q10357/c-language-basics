#include <stdio.h>
#include <stdlib.h>


int sumAndProduct(int a, int b, int* sum, int* prod) {
    /*
    To actually output multiple variables, you're going to have to have
    multiple inputs
    Instead of having the two inputs. 
    // a, b => a + b and a * b
    We are also gonna pass in two more inputs, 
    that ar epointers to some place in memory, where we are gonna save
    the sum and the product
    */
   if( sum == NULL || prod == NULL) {
    return 0;
   }
   *sum = a + b;
   *prod = a * b;

   return 1;
}

int main(int argc, char* argv[]){
    // a, b => a + b and a * b
    /*
    How can we return both of these values from a function?
    short answer: pointers
    */
    int x = 5, y = 12, sum, prod;
    int status = sumAndProduct(x, y, &sum, &prod);
    if(status == 0){
        printf("Something went wrong\n");
        return -1;
    }
    printf("The sum is: %d\nAnd the product is: %d\n", sum, prod);
    return 0;
}