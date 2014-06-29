#include<stdio.h>
#include<string.h>

#define PRINT_CHAR 1 
#define PRINT_INT  2 
#define PRINT_FLOAT  3 
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);
void show_int(int ix);
void show_float(float fx);
void show_pointer(void *px);

int print_format;
int main(int argc, char *argv[])
{

    char carray[5]={'a', 'b', 'c', 'd', 'e'};
    int ix = 11111;
    //float fx = 0.5; 
    float fx = -0.75; 

    int idx; 
    if (argc == 1 )
    {
	printf ( "help info: %s\n", "the input format is");
    } else { 
    	for (idx = 0; idx<argc; idx++)
    	{
   		printf ("argv[%d] = %s ", idx, argv[idx]); 
    	}

    	if (strcasecmp(argv[1], "-c") == 0) 
        {
                print_format = PRINT_CHAR; 
        	printf("argv show_bytes...\n");
    		show_bytes(carray, 5);
    		//show_pointer(carray);

	}
    	if (strcasecmp(argv[1], "-i") == 0) 
        {
                print_format = PRINT_INT; 
                show_int(ix);
    		show_pointer(&ix);
        }
    	if (strcasecmp(argv[1], "-f") == 0) 
        {
                print_format = PRINT_FLOAT; 
                show_float(fx);
    		show_pointer(&fx);
        }
    }
//    printf("show_bytes...\n");
//   show_bytes(carray, 5);
//    show_int(ix);
//    show_float(fx);
}

void show_bytes(byte_pointer start, int len)
{
	int i;
        for (i=0; i<len; i++)
        {
            if ( print_format == PRINT_CHAR ) {
            	printf("%c=0x%x", start[i], start[i]);
            } else {
            	printf("%x", start[i], start[i]);

            }
            printf("\n");

        }

/*
        for (i=0; i<len; i++)
        {
            printf(" %d", start[i]);
            printf("\n");
        }
*/
}

void show_int(int start)
{
        printf("show_int... %d\n", start);
	show_bytes((byte_pointer) &start, sizeof(int));
}

void show_float(float start)
{
        printf("show_float...\n");
	show_bytes((byte_pointer) &start, sizeof(float));
}

void show_pointer(void *start)
{
        printf("show_pointer...\n");
	show_bytes((byte_pointer) &start, sizeof(void *));
}
