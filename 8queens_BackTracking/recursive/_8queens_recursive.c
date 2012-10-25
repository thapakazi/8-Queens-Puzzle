/*-------Backtracking NQueens Problem using Recursive Approach--------------*/
#include<stdio.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

#define N 8



int counter=0;

int placeQueen(int q[], int n);
void queenLogic(int q[],int n);
void printQueens(int q[]);

//
FILE *theFile;

/*------------------------------------------------------------------*/

int main(){
	clock_t start;
	int i;
	int queen[N];
	
	theFile = fopen("output.txt","w");
	fprintf(theFile,"******* %d Queen Puzzle**********\n\n",N);	

	start=clock();		
	queenLogic(queen,0);
	fprintf(theFile,"\n\nTime elapsed: %f secs\n", ((double)clock() - start)/CLOCKS_PER_SEC);

	fprintf(theFile,"with %d solutions. :):)",counter);
	fprintf(theFile,"\n");	
	fclose(theFile);
	return 1;
}

/*------------------------------------------------------------------*/
void queenLogic(int qu[], int n){
	
	int i;	
	if (n == N){
		printQueens(qu);
		counter++;
		//printf("\n%d solution found...",counter);
		}
	else {
		for (i = 0; i < N; i++) {
			qu[n] = i;
			if (placeQueen(qu,n))
				queenLogic(qu, n + 1);
		}
	}
}

/*------------------------------------------------------------------*/
int placeQueen(int q[], int n){

	int i;
	for (i = 0; i < n; i++) {
		if (q[i] == q[n])
			return FALSE; // same column
		if ((q[i] - q[n]) == (n - i))
			return FALSE; // same major diagonal
		if ((q[n] - q[i]) == (n - i))
			return FALSE; // same minor diagonal
		}
	return TRUE;
}

/*------------------------------------------------------------------*/
void printQueens(int q[])
{
	int i,j;
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			if (q[i] == j)
				fprintf(theFile,"Q ");
			else
				fprintf(theFile,"* ");
		}
		fprintf(theFile,"\n");
	}
	fprintf(theFile,"\n");
}

