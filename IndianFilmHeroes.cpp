/*
Problem Link: http://opc.iarcs.org.in/index.php/problems/GREATESC
(IARCS OPC Archive, K Narayan Kumar, CMI)
Created by S Pramod <-> domarps
*/

#include <stdio.h>
#include <limits.h>

#define INF 1000000
int n;

int Distance[4000];  
int Q[4000];  // Queue it is
int A[4000][4000]; //Adjacency Matrix, because the List is not for the weak hearted.

void BreadthFirstSearch(int begin)
{
	int Headead = 0;
	int Tail = -1;
	int j,k;
	Distance[begin] = 0;

	Q[Tail+1] = begin;
	Tail = Tail+1;

	while(Tail>=Head){
		j = Q[Head];

		for (k = 0;k < n; k++){
			if(A[j][k] == 1 && Distance[k] == INF)
			{
				Distance[k] = Distance[j]+1;
				Q[Tail+1] = k;
				Tail = Tail+1;
			}
		}
		Head = Head+1;
	}
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	int i,j;
	int a,b,s,t;

	for(i = 0;i < n; i++)
	{
		Distance[i] = INF;
	}

	for(i = 0;i < n; i++)
	{
		for(j = 0;j < n; j++)
		{
			A[i][j] = 0;
		}
	}

	for(i = 0;i < m; i++)
	{
		scanf("%d%d",&a,&b);
		A[a-1][b-1] = 1;
		A[b-1][a-1] = 1;
	}


	scanf("%d%d",&start,&finish);


	if(start > 0 && finish > 0 && s <= n && t <= n)
	{
		start--;
		finish--;
		BreadthFirstSearch(start);

		if(Distance[finish] == INF)
		{
			printf("0");
		}
		else 
		{
			printf("%d",Distance[finish]);
		}
	}
	else
	{
		printf("0");
	}
        return 0;
}
