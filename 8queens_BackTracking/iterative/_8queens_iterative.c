/*-------Backtracking NQueens Problem using Iterative Approach--------------*/
#include <stdio.h>
#include<time.h>

#define N 4

int a[N][N];
int check(int,int);
FILE *outputFile;
main()
{
 int n=N,row,col,prev,flag,count=0,i,j;

 clock_t start=clock();
 outputFile=fopen("iterOutput.txt","w");
 fprintf(outputFile,"******* %d Queen Puzzle**********\n\n",N);
 for(row=0;row<N;row++)
 {
 //clear all values to 0 in a row
  for(prev=0;prev<N;prev++)
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
for(col=prev+1;col<N;col++)
  {

   if(check(row,col))
   {
    a[row][col]=1;
    flag=1;
    break;
   }
  }

  if(row==0&&flag==0)
                     break;
  else if(col==N)
       row=row-2;
  else if(row==N-1&&flag==1)
  {
   count++;

   fprintf(outputFile,"\t \t \t  %dsolution found \n ",count);
  for(i=0;i<N;i++){
                   for(j=0;j<N;j++)
                   {
                                   if(a[i][j]==1)
                                                 fprintf(outputFile,"Q ");
                                   else
                                                 fprintf(outputFile,"* ");
                   }
           fprintf(outputFile,"\n");
   }
  row=row-1;
                                 
  }
 }

fprintf(outputFile,"\n\nTime elapsed: %f secs\n", ((double)clock() - start)/CLOCKS_PER_SEC);
fprintf(outputFile," \ntotal solutions are %d",count);
// system("pause");
fclose(outputFile);
}

int check(int row,int col)
{
 int i;
 for(i=0;i<row;i++)
 {
  if((a[row-1-i][col]==1)||(a[row-1-i][col-1-i]==1&&(col-i-1)>=0)||(a[row-1-i][col+1+i]==1&&(col+1+i<=N-1)))
  return 0;
  }

  return 1;
}

