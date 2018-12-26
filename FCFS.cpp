#include<stdio.h>
#include<math.h>
int main()
{
	int n,head,start,end;
	int seek;
	printf("Enter the no of disk visits\n");
	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the start\n");
	scanf("%d",&start);
	printf("Enter the end\n");
	scanf("%d",&end);
	printf("Enter the head\n");
	scanf("%d",&head);
	if(start<end && head>=start && head<=end)
	{	
		// Applying FCFS
		
		seek = abs(head-a[0]);
		for(int i=0;i<n-1;i++)
		{
			seek = seek+ abs(a[i]-a[i+1]);
		}	
	}
	printf("SEEK TIME : %d",seek);
	return(0);
}
