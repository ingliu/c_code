#include<stdio.h>
#include<string.h>

#define PRINT_CHAR 1 
#define PRINT_INT  2 
#define PRINT_FLOAT  3 

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);
void show_int_bytes(int ix);
void show_float_bytes(float fx);
void show_void_pointer(void *px);

int print_format;

int main(int argc, char *argv[])
{
    char carray[5]={'a', 'b', 'c', 'd', 'e'};
    int ix = 11111;
    float fx = -0.75; 

    int idx; 
    char char_1 = 128 ; 
    signed char sc = 129;
    unsigned char uch = 128;


    printf("\n"); 

    printf("unsighed char uch = 128 is: %u\n",  uch);  /* -128, 0x80 */ 
    show_bytes (&char_1, 1); /* 0x80  binary: 10000000 for unsigned it is 128, but for 2's complement, it is -128*/
    printf("signed char sc 129 =%d\n", sc); 
    printf("unsigned char uch 256 =%d\n", uch); 
    printf("\n"); 

    char ch2 = 255;  /* -128 to  127*/
    signed char sc2 = -128; /*-128 to 127 */
    unsigned char uch2 = 255; /* 0 to 255 */

    printf("char ch2 127 =%d\n", ch2); 
    printf("signed char sc2 -128 =%d\n", sc2); 
    printf("unsigned char uch2 255 =%d\n", uch2); 

    printf("\n"); 

    printf ("size of unsigned char pointer   = %d\n", sizeof(unsigned char * ));
    printf ("size of unsigned char   = %d\n", sizeof(unsigned char ));

    printf ("size of char  pointer = %d\n", sizeof(char *));
    printf ("size of char  = %d\n", sizeof(char ));

    printf ("size of signed char pointer  = %d\n", sizeof(signed char *));
    printf ("size of signed char  = %d\n", sizeof(signed char));

    printf ("size of void pointer  = %d\n", sizeof(void *));
    printf ("size of void  = %d\n", sizeof(void));

    printf("\n"); 

    if (strcasecmp(argv[1], "-c") == 0) 
    {
                print_format = PRINT_CHAR; 
    		printf("\n"); 
        	printf("show character bytes...\n");
    		show_bytes(carray, sizeof(carray));
    		printf("\n"); 
    		show_void_pointer(carray);
    		printf("\n"); 
    }
    if (strcasecmp(argv[1], "-i") == 0) 
    {
                print_format = PRINT_INT; 
                show_int_bytes(ix);
    		printf("\n"); 
    		show_void_pointer(&ix);
    		printf("\n"); 
    }
   if (strcasecmp(argv[1], "-f") == 0) 
   {
                print_format = PRINT_FLOAT; 
                show_float_bytes(fx);
    		show_void_pointer(&fx);
    		printf("\n"); 
   }
//    printf("show_bytes...\n");
//    show_bytes(carray, 5);
//    show_int(ix);
//    show_float(fx);
}

void show_bytes(byte_pointer bp, int len)
{
	int i;
        for (i=0; i<len; i++)
        {
            if ( print_format == PRINT_CHAR ) {
            	printf("character_%d=%c ; address=0x%x\n", i,  bp[i], &bp[i]);
            } else {
            	printf("byte_%d=0x%x , address=%x\n", i, bp[i], &bp[i]);

            }
        }
        printf("\n");

}

void show_int_bytes(int ix)
{
        printf("show bytes for int... %d\n", ix);
	show_bytes((byte_pointer) &ix, sizeof(int));
}

void show_float_bytes(float fx)
{
        printf("show_bytes for float...\n");
	show_bytes((byte_pointer) &fx, sizeof(float));
}

void show_void_pointer(void *vx)
{
        printf("show bytes for void type...\n");
	show_bytes((byte_pointer) vx,  sizeof(void *));
}
