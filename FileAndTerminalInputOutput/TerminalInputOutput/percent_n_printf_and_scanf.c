#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NOT RECOMMENDED TO USE!!!!
//DONT USE IT, NOT SECURE, BUFFER OVERFLOW
int main(int argc, char* argv[]){
    /*
    %n format specifier, pointer to an int
    */

    /*%n is considered unsafe, escpecially with user input*/
    
    int num, x;
    /*
    printf("This is a test%n string\n", &num); alone,
    only prints out "This is a test"
    %n is an ouput for printf
    printf, usually, is given data, and printf it out on the screen
    but now, printf gives us data, what data?
    well, %n says, store in this pointer (&num), 
    store the number of characters returned so far
    If you only want the number of characters written, you can use
    num = printf("This is a test string\n");
    This will return the number of the WHOLE string written in printf
    Equivalent to: printf("This is a test string\n%n", &num);
    */
    printf("This is a test%n string\n", &num);

    /*
    This will print out "Number ofcharacters written 14"
    In the printf statement above, there are 14 characters before %n,
    We save this number, and save it in the memory location of num
    */
    printf("Number of characters written: %d\n", num);

    /*
    Also works with scanf() (need to scan a number)
    scanf returns number of arguments this means =>
    int res = scanf("%d", &x) 
    will maximum return 1, as it is only one argument to be read
    */

    scanf("%d%n", &x, &num);
    printf("Number of characters read: %d\n", num);

    return 0;
}