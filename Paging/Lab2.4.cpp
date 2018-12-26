#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int size,m,n,pgno,i,j,frameno;
	int pagetable[3]={5,6,7};
	double m1;
	int ra=0,ofs;
	printf(“ENTER THE PROCESS SIZE (in KB of max 12KB) :”);
	scanf(“%d”,&size);
	m1=size/4;
	n=ceil(m1);
	printf(“TOTAL NO OF PAGES : %d”,n);
	printf(“\nENTER RELATIVE ADDRESS(in hexadecimal notation eg.0XRA) \n”);
	scanf(“%d”,&ra);
	pgno=ra/1000; 
	ofs=ra%1000;
	printf(“PAGE NO = %d\n”,pgno);
	printf(“PAGE TABLE”);
	for(i=0;i<n;i++)
	{
		printf(“\n %d [%d]”,i,pagetable[i]);
	}
	frameno=pagetable[pgno];
	printf(“\n EQUIVALENT PHYSICAL ADDRESS : %d%d”,frameno,ofs);
	return(0);
}
