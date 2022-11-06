#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
How can we get numbers between 0..2, including floating point numbers?
aka 0.01 ,1.99 etc...
*/

double rand_double_0_1()
{
    //Cast it to double (or float)
    //And divide by MAX number you can get from rand()
    //Returns number INCLUSIVE 0 to 1
    return ((double)rand()) / ((double)RAND_MAX);
    /*
    Let's say rand() returns 1 / RAND_MAX gonna return very small number (close to 0)
    Let's say rand() returns 32000 / RAND_MAX => return very big number (close to 1)
    */
}

/*
    Let's say we want [0..5]
    0.5 * 5 = 2.5
    0.99 * 5 = 4.95
    0.1 * 5 = 0.5 etc....

    If we want numbers [1, 2]
    rand_double_0_1() => 0.5 + 1 = 1.5
    

*/

double rand_double_interval(double a, double b)
{
    //We asume b is always greater than a
    /*
    b = 10, a = 4
    0.5 * (b - a) + a = 0.5 * 6 + 4 = 7 
    0.1 * (b - a) + a = 0.1 * 6 + 4 = 4.6 
    1.0 * (b - a) + a = 1.0 * 6 + 4 = 10;
    0.0 * (b - a) + a =  0.0 * 6 + 4 = 4
    */
    return rand_double_0_1() * (b - a) + a;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int i = 0;
    /*
    This code printf out number 0..1
    for(i; i < 100; i++){
        printf("%lf ", rand_double_0_1());
    }
    */
   double x = 4.2, y = 9.5;
   for(i; i < 100; i++){
    //prints out numbers x..y including floating point numbers
    printf("%lf ", rand_double_interval(x, y));
   }

   printf("\n");

    return 0;
}