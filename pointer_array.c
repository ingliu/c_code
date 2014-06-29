#include<stdio.h>
typedef unsigned char *byte_pointer;
main()
{

    int x = 55555;
    show_bytes(&x, 5);
}
    void show_bytes(byte_pointer start, int len)
    {
        int i;
        for (i=0; i<len; i++)
        {
            printf(" %.2x", start[i]);
            printf("\n");

        }

        for (i=0; i<len; i++)
        {
            printf(" %d", start[i]);
            printf("\n");
        }
    }

