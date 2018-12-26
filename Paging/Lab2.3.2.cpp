#include<bits/stdc++.h>
using namespace std;

void BF(int partition[], int m, int process[], int n)
{
    int allo[n];
    memset(allo, -1, sizeof(allo));
    for (int i=0; i<n; i++)
    {
        int bestID = -1;
        for (int j=0; j<m; j++)
        {
            if (partition[j] >= process[i])
            {
                if (bestID == -1)
                    bestID = j;
                else if (partition[bestID] > partition[j])
                    bestID = j;
            }
        }
        if (bestID != -1)
        {
            allo[i] = bestID;
            partition[bestID] = 0;
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
	BF(a, part, p, process);
    return (0) ;
}
