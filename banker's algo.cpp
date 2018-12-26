 #include<stdio.h>  
 #include<conio.h>

int main()
{
  int process,resource,i,j,instanc,k=0,count1=0,count2=0; //count,k      variables are taken for counting purpose
  printf("\n Enter No. of Process:-\n");
  scanf("%d",&process);                            //Entering No. of Processes
  printf("\nEnter No. of Resources:-\n");
  scanf("%d",&resource);                       //No. of Resources

  int avail[resource],max[process][resource],allot[process][resource],need[process][resource],completed[process];

  for(i=0;i<process;i++)
  completed[i]=0;                             //Setting Flag for uncompleted Process

  printf("\nEnter No. of Available Instances\n");

  for(i=0;i<resource;i++)
  {
    scanf("%d",&instanc);
    avail[i]=instanc;                        // Storing Available instances
  }

  printf("\nEnter Maximum No. of instances of resources that a Process need:\n");

  for(i=0;i<process;i++)
  {
    printf("\nFor P[%d]",i);
    for(j=0;j<resource;j++)
     {
        scanf("%d",&instanc);
        max[i][j]=instanc;              
     }
  }    
  printf("\nEnter no. of instances already allocated to process of a resource:\n");

  for(i=0;i<process;i++)
  {
    printf("\nFor P[%d]\t",i);
    for(j=0;j<resource;j++)
     {
        scanf("%d",&instanc);
        allot[i][j]=instanc;
        need[i][j]=max[i][j]-allot[i][j];       //calculating Need of each process
     } 
 }
printf("\nSafe Sequence is:- \t");

 while(count1!=process)
 {
  count2=count1;
  for(i=0;i<process;i++)
  {
    for(j=0;j<resource;j++)
    {
        if(need[i][j]<=avail[j])
          {
            k++;
          }  
    }    
    if(k==resource && completed[i]==0 )
     {
       printf("P[%d]\t",i);
       completed[i]=1;
       for(j=0;j<resource;j++)
         {
           avail[j]=avail[j]+allot[i][j];
          } 
         count1++;
     }
     k=0;
   }

     if(count1==count2)
     {
     printf("Stop ..After this.....Deadlock \n");
     break;
   } 
 }
 return(0);
}
