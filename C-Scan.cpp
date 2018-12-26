#include<stdio.h>
#include<math.h>
void is( int *A ,int a)
{
	int i,j,temp;
	for(i=1;i<a;i++)
	{
		j=i;
		while(j>0&&(A[j]<A[j-1]))
		{
			temp=A[j];
			A[j]=A[j-1];
			A[j-1]=temp;
			j--;
		}
	}
}
int main()
{
	int n,head,start,end,index,min=1000;
	int seek=0;
	int i=0;
	printf("Enter the no of disk visits\n");
	scanf("%d",&n);
	int a[n];
	for( i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the start\n");
	scanf("%d",&start);
	printf("Enter the end\n");
	scanf("%d",&end);
	printf("Enter the head\n");
	scanf("%d",&head);
	is(a,n);
	n=n+3;
	int b[n];
	for(i=0; i<n-1; i++)
	{
		b[i]=a[i];
	}
	b[i]=start;
	b[i+1]=end;
	b[i+2]=head;
	is(b,n);
	int j=0;
	while(b[j]!=head)
	{
		j++;
	}
	if(start<end && head>=start && head<=end)
	{	
		// Applying C-Scan
		
		seek=seek + abs(head-start);
		seek=seek + abs(end-start);
		seek=seek + abs(end-b[j+1]);
			
	}
	printf("SEEK TIME : %d",seek);
	return(0);
}
