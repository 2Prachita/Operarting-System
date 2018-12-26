#include<stdio.h>
#include<stdlib.h>

int main()
{
	int f, n, i, j, flag, page_fault=0, max, index;
	
	printf("ENTER THE NO OF FRAMES :");
	scanf("%d", &f);
	printf("\nENTER THE LENGTH OF STRING :");
	scanf("%d", &n);
	
	int a[n], b[f], c[f];
	
	printf("\nENTER THE STRING ");
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<f; i++)
	{
		b[f]=-1;
		c[f]=-1;
	}
	max = -1;
	index=0;
	for(i=0; i<n; i++)
	{
		flag=1;
		max=-1;
		for(j=0; (j<f) && (flag==1); j++)
		{
			if(a[i] == b[j])
			{
				flag = 0;
			}
			else 
			{
				if(b[j] == -1)
				{
					b[j] = a[i];
					page_fault++;
					flag = 0;
					c[j] = 0;
				}
				else if(max < c[j]) 
				{
					max = c[j];
					index = j;	
				}                                           
			}
		}
		if(flag == 1)
        {
        	b[index] = a[i];
        	page_fault++;
        	c[index]=0;
		}
		for(j=0; j<f; j++)
		{
			if(c[j] != -1)
			{
				c[j]++;
			}
		}
		
	}
	printf("THE PAGE-FAULTS ARE : %d", page_fault);
}
