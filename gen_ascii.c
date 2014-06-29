/* The purpose of this program is to practice the printf format and the concept of the ascii table */

#include <stdio.h>

int main(int argc, char *argv[])
{
        unsigned char my_char;
        int idx;
	if(argc == 2)
	{	
		my_char = * argv[1];
		printf ("Char\t dec\t hex\t oct\n"); 
		printf ("%c \t %d \t %x \t %o\n", *argv[1], (int)*argv[1], (int)*argv[1], (int)*argv[1]); 
	} else {
		printf ("ASCII Table\n" );
                for (idx = 0; idx <=177; idx++)
		{
		     printf("dec=%d\t hex=%x\t oct=%o\t %c\n", idx, idx, idx, idx);

                }  
	}
}
