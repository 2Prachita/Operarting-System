#include<stdio.h>
#include<stdlib.h>

int main()
{
    int f,n,page_fault=0,i,j,c=-1,flag;
    printf("ENTER THE LENGTH OF STRING \n");
    scanf("%d",&n);
    printf("ENTER THE NO OF FRAMES \n");
    scanf("%d",&f);
    int a[n],b[f];
    for(i=0;i<n;i++)
    {
        printf("\nENTER THE PROCESS ID \n");
        scanf("%d,&a[i]");
    }
    for(i=0;i<f;i++)
    {
        b[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        flag=0;            
        for(j=0;(j<f)&&(flag==0);j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
        	b[c]=a[i];
        	page_fault++;
        	c++;
        	if(c==f)
        	{
        		c=0;
			}
		}
    }
    printf("THE NO OF PAGE FAULTS ARE : %d",page_fault);
    return(0);
}

