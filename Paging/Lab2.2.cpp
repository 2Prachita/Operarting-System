#include <bits/stdc++.h>
using namespace std;

bool search(int key, vector<int>& fr)
{
    for (int i = 0; i < fr.size(); i++)
    {
    	if (fr[i] == key)
    	{
    		return true;	
		}
	}    
    return false;
}
int predict(int pg[], vector<int>& fr, int pn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++) 
	{
        int j;
        for (j = index; j < pn; j++) 
		{
            if (fr[i] == pg[j]) 
			{
                if (j > farthest) 
				{
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
        {
        	return i;	
		}   
    }
    return (res == -1) ? 0 : res;
}
int optimalPage(int pg[], int pn, int fn)
{
    vector<int> fr;
    int hit = 0;
    for (int i = 0; i < pn; i++) 
	{
 
        if (search(pg[i], fr)) 
		{
            hit++;
            continue;
        }
        if (fr.size() < fn)
		{
			fr.push_back(pg[i]);
		}
        else 
		{
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    return(pn-hit);
}

int main()
{
    int f,n,page_fault=0,i,j,c=-1,flag,optimal_pf=0;
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
    optimal_pf = optimalPage(a, n, f);
    if(optimal_pf<page_fault)
    {
    	printf("THE ALGORITHM WITH LESS NO OF PAGE FAULTS IS OPTIMAL PAGE REPLACEMENT ALGORITHM\n");
    	
	}
	else
	{
		printf("THE ALGORITHM WITH LESS NO OF PAGE FAULTS IS FCFS REPLACEMENT ALGORITHM\n");
	}
    return(0);
}
