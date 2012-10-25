#include <stdio.h>
#include <time.h> 
#define MAX_N 20

 
int a[MAX_N][MAX_N];
int check(int,int,int);
main()
{
 int values=4;
 int n=values,row,col,prev,flag,count=0,i,j;
 for(values=4;values<=MAX_N;values++)
 {
    clock_t start = clock();
    for(row=0;row<values;row++)
    {
        for(prev=0;prev<values;prev++)
        {
            flag=0;
            if(a[row][prev]==1)
            {
                a[row][prev]=0;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            prev=-1;
        }
        flag=0;
        for(col=prev+1;col<values;col++)
        {
            if(check(row,col,values))
            {
                a[row][col]=1;
                flag=1;
                break;
            }
        }
        if(row==0&&flag==0)
            break;
        else if(col==values)
            row=row-2;
        else if(row==values-1&&flag==1)
        {
            count++;  
            for(i=0;i<values;i++)
            {
                for(j=0;j<values;j++)
                {
                    if(a[i][j]==1)
                    {
                        printf("Q ");
                    }
                    else
                    {
                        printf("* ");
                    }
                }
                printf("\n");
            }
            if(count>10)
            {
                system("pause");
            }
            printf("\n");
            row=row-1;                         
        }
        }
 
    clock_t finish = clock();
    printf("\nProblem size:%d\n",values);
    printf(" \ntotal solutions are %d",count);
    printf("\ntotal time spent:%f milliseconds.\n",((double)(finish-start)/CLOCKS_PER_SEC));
    }
    system("pause");
    system("pause");
}

int check(int row,int col,int values)
{
 int i;
 for(i=0;i<row;i++)
 {
  if((a[row-1-i][col]==1)||(a[row-1-i][col-1-i]==1&&(col-i-1)>=0)||(a[row-1-i][col+1+i]==1&&(col+1+i<=values-1)))
  return 0;
  }

  return 1;
}
