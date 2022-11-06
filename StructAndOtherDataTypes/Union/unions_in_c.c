#include <stdio.h>
#include <stdlib.h>

typedef union Example {
    long long num;
    char bytes[8];
    float floats[2];
} Example;

void print_floats(const Example* e){
    printf("%.02f %.02f\n", e->floats[0], e->floats[1]);

    printf("Sizeof floats[]: %llu\n", sizeof(e->floats)); // => 8 bytes
}
void print_bytes(const char* arr){
    for(int i = 0; i < 8; i++){
        /*
        %02hhx - print whatever is in there as a one bye
                    in hexadecimal, and if t's only one character, pad with 0s
        */
        printf("%02hhx ", arr[i]);
    }
    printf("\n");
}
int main(int argc, char argv[])
{
    /*
    Are They The Same?
    Here we initialize two values of type Example.
    In one we define .num member, in the othfer .bytes member
    You can see the explanation below under <Explanation>
    */
    Example e1 = {
        .num = 17
    };

    Example e2 = {
        .bytes[0] = 17
    };

    printf("E1 .num: %lld\n", e1.num);
    //Below will show you, even as an int, it will have a memory of 64 bytes
    //Just like char[8]
    printf("E1 .num number of bytes: %d\n", sizeof(e1.num)); // => 8 bytes
    
    printf("E1 bytes: ");
    print_bytes(&e1);
    printf("E1 floats: ");
    print_floats(&e1);

    printf("E2 bytes: ");
    print_bytes(&e2);

    printf("E2 .num: %lld\n", e2.num);
    printf("E2 floats: ");
    print_floats(&e2);
    

    /*
    What???! It prints out the hexadecimal value for 17! But we didnt define e1.bytes?

    Well, all the union members share the exact same memory;
    see <Are They The Same?> above
    */
    return 0;
}

    /*
    Our Code:
    long long num = 17;
    printf("%lld\n", num);

    But, what I want is, that instead of just printing out the number,
    I wanna print out every single byte of that 64 bit integer

    How? We could cast it to a char* and keep adding, visiting every address,
    but we dont want to do any casting here, we want it to happen automatically

    Here unions may help
    */

   /*
    ------------ Explanation --------------
    Union members all point to the same place in memory!

    All union members have the same value, but you can choose what member you initialize
    the Example with. 
    If you then point to the value of another member, you will
    be served with the value of whatever you defined, even if
    you defined another field. 
    Ex: In our code we initialized Example e1 with .num. 
    By referencing the .bytes member, you will be served with the value of .num, here 17.
    Same place in memory. 

    You may ask: 
    "Well, here the long long num, is of 64 bits. char[8] is of 8 * 8 = 64 bytes,
        What if we defined .num as an int (32 bits), and then reffered to the .bytes?
            Wouldn't that override the memory of e1 and serve garbage values?"
    
    Good question, but the union allocates enough memory for the LARGEST member.
    An int will be of 64 bytes when with char[8].
   */