#include<bits/stdc++.h>
using namespace std;
 
void FF(int partition[], int m, int process[], int n)
{
    int allo[n];
    int flag;
    memset(allo, -1, sizeof(allo));
    for (int i=0; i<n; i++)
    {
    	flag=0;
        for (int j=0; j<m && flag==0; j++)
        {
            if (partition[j] >= process[i])
            {
                allo[i] = j;
                partition[j] = 0;
                flag=1;
            }
        }
    }
    cout << "\nPROCESS NO.\tPROCESS SIZE\tPARTITION NO.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allo[i] != -1)
        {
		    cout << allo[i] + 1;
		}
        else
        {
            cout << "NOT ALLOCATED";
    	}
        cout << endl;
    }
}
 
int main()
{
	int part, process,i;
	printf(" ENTER THE NO OF PARTITIONS OF MEMORY : ");
	scanf("%d", &part);
	printf(" ENTER THE NO OF PROCESS :\t\t");
	scanf("%d", &process);
	int a[part], p[process];
	printf(" \nENTER THE MEMORY SIZE OF PARTITIONS : ");
	for(i=0; i<part; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\nENTER THE SIZE OF PROCESS :\t \t");
	for(i=0; i<process; i++)
	{
		scanf("%d", &p[i]);
	}
	FF(a, part, p, process);
    return (0) ;
}
