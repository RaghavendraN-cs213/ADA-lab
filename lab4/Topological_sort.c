#include<stdio.h>

void main()
{
 int n, a[30][30],i,j,sum,in[30],s[30],t[30],k=0;
 printf("Enter no of vertices: ");
 scanf("%d",&n);
 printf("Enter adjacency matrix:\n");
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
     {
         scanf("%d",&a[i][j]);
     }
 }
 for(j=0;j<n;j++)
 {
     sum=0;
     for(i=0;i<n;i++)
     {
         sum+=a[i][j];
     }
     in[j]=sum;
 }
 int top=-1;
 for(i=0;i<n;i++)
 {
     if(in[i]==0)
     {
         top++;
         s[top]=i;
     }

 }
 while(top!=-1)
 {
    int u=s[top];
    top--;
    t[k++]=u;
    for(int i=0;i<n;i++)
    {
        if(a[u][i]==1)
        {
            in[i]--;
            if(in[i]==0)
            {
                top++;
                s[top]=i;
            }
        }
    }
 }
    printf("Sequence: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",t[i]);
    }
}
