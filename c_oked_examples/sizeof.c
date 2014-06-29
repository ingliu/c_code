#include<stdio.h>
#include<string.h>


typedef unsigned char *byte_pointer;

int main(int argc, char *argv[])
{

    printf("\n"); 


    printf ("size of char  = %lu bytes.\n", sizeof(char ));
    printf ("size of unsigned char   = %lu bytes. \n", sizeof(unsigned char ));
    printf ("size of signed char  = %lu bytes. \n", sizeof(signed char));
    printf ("size of char pointer  = %lu bytes. \n", sizeof(char *));
    printf ("size of signed char pointer  = %lu bytes. \n", sizeof(signed char *));
    printf ("size of unsigned char pointer  = %lu bytes. \n", sizeof(unsigned char *));
    printf ("size of typedef byte_pointer  = %lu bytes. \n", sizeof(byte_pointer));

    printf ("size of short = %lu bytes. \n", sizeof(short ));

    printf ("size of int   = %lu bytes. \n", sizeof(int ));
    printf ("size of long int   = %lu bytes. \n", sizeof(long int));
    printf ("size of long long int   = %lu bytes. \n", sizeof(long long int));

    printf ("size of float   = %lu bytes. \n", sizeof(float));


    printf ("size of void  = %lu bytes. \n", sizeof(void));
    printf ("size of void pointer  = %lu bytes. \n", sizeof(void *));

    printf("\n"); 

}
