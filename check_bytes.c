#include<stdio.h>
#include<string.h>

#define PRINT_CHAR 1 
#define PRINT_INT  2 
#define PRINT_FLOAT  3 

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);
void show_chars(char *ca, int len);
void show_int(int ix);
void show_float(float fx);
void show_pointer(void *px);

int print_format;
int main(int argc, char *argv[])
{

    char carray[5] = {'a','b','c','d','e'};
    int ix = 11111;
    float fx = -0.75; 

    int idx; 

    //validate the command line input and display the help info.
    if( argc < 2  || !((strcasecmp(argv[1], "-all") == 0)   
		   || (strcasecmp(argv[1], "-char") == 0) 
		   || (strcasecmp(argv[1], "-int") == 0 ) 
		   || (strcasecmp(argv[1], "-fl") == 0 )))  
    {

       printf ("%s", "Invalid input: ");
       //display the command line input
       for (idx = 0; idx<argc; idx++)
       {
          printf ("argv[%d] = %s ", idx, argv[idx]); 
       }
   	printf ("\n"); 
       printf ( "%s\n", "The input format: program -[all, char, int, fl] number\n"); 

    } else {
    	if (strcasecmp(argv[1], "-all") == 0) 
        {
                print_format = PRINT_CHAR; 
        	printf("show_bytes...\n");
    		show_bytes(carray, 5);
    		//show_pointer(carray);

                print_format = PRINT_INT; 
                show_int(ix);
    		show_pointer(&ix);

                print_format = PRINT_FLOAT; 
                show_float(fx);
    		//show_pointer(&fx);
	} else {
    	   if (strcasecmp(argv[1], "-char") == 0) 
           {
                print_format = PRINT_CHAR; 
        	printf("show_characters...\n");
    		show_chars(carray, sizeof(carray));
    		show_pointer(carray);
	   } else if (strcasecmp(argv[1], "-int") == 0) {
                  print_format = PRINT_INT; 
                  show_int(ix);
    		  show_pointer(&ix);
           } else if (strcasecmp(argv[1], "-fl") == 0) {
                print_format = PRINT_FLOAT; 
                show_float(fx);
    		show_pointer(&fx);
           }
        }
   }
//    printf("show_bytes...\n");
//    show_bytes(carray, 5);
//    show_int(ix);
//    show_float(fx);
}

void show_bytes(byte_pointer start, int len)
{
	int i;
        printf("show_bytes is called....\n");
        printf("The byte_pointer = 0X%x\n", start);

        for (i=0; i<len; i++)
        {
            if ( print_format == PRINT_CHAR ) {
            	printf("%c=0X%x\n", start[i], start[i]);
            } else {
            	printf("byte[%d]=%x\n", i, start[i]);

            }
        }

/*
        for (i=0; i<len; i++)
        {
            printf(" %d", start[i]);
            printf("\n");
        }
*/
}

void show_chars(char *start, int len)
{
	int i;
        for (i=0; i<len; i++)
        {
            	printf("character=%c  HEX=0X%x, Address=0X%x\n",  start[i],  start[i],  &start[i]);

        }
        printf("end of show_chars.\n");

}

void show_int(int start)
{
        printf("The integer number = %d\n", start);
	show_bytes((byte_pointer) &start, sizeof(int));
}

void show_float(float start)
{
        printf("The float number = .5f\n", start);
	show_bytes((byte_pointer) &start, sizeof(float));
}

void show_pointer(void *start)
{
        printf("The pointer  = %x\n", start);
	printf("the size of (void*) = %d\n", sizeof(void *));
	show_bytes((byte_pointer) start, sizeof(void *));
}
