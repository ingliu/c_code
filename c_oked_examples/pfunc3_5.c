#include <stdio.h>

void pfunc (int *xp, int *yp, int *zp);

int main()
{
	int *px, x = 5; px = &x;
        int *py, y = 10; py = &y; 
        int *pz, z = 20; pz = &z; 

     	printf("sizeof px = %lu \n", sizeof(px));  //%lu: long unsigned int is the type of sizeof
     	printf("xp = %p, *x=%d\n", px,  *px); 
     	printf("yp = %p, *y=%d\n", py,  *py); 
     	printf("zp = %p, *z=%d\n", pz,  *pz); 
     	printf("\n"); 

    	pfunc (px, py, pz);

        printf("\nafter calling  subroutine.....\n"); 
     	printf("xp = %p, *x=%d\n", px,  *px); 
     	printf("yp = %p, *y=%d\n", py,  *py); 
     	printf("zp = %p, *z=%d\n", pz,  *pz); 
     	printf("\n"); 
}

void pfunc (int *xp, int *yp, int *zp)
{
	int tx =*xp;
	int ty =*yp;
	int tz =*zp;

	*xp = ty;    //x=y;
	*yp = tz;    //y=z;
	*zp = tx;    //z=x;

     printf("in subroutine.....\n"); 
     printf("xp =%p, *xp=%d\n", xp, *xp); 
     printf("yp =%p, *yp=%d\n", yp, *yp); 
     printf("zp =%p, *zp=%d\n", zp, *zp); 
}
