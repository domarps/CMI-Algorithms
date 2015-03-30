/*
  Created by S Pramod <-> domarps
  http://www.iarcs.org.in/inoi/contests/apr2005/Advanced-1.php
  (IARCS OPC Archive, K Narayan Kumar, CMI)
*/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct edge
{
	int e, cost;
	bool operator <(const edge & x) const
	{
		return (cost >= x.cost);	
	}
	
};

int i , j , k , n , m , a, b, c, d;
int ai,aj,wij;

vector<edge> g[2000];
int mark[2000];
int dist[2000];
priority_queue<edge> heap;

void dijkstra(int s)
{	
	memset(dist, -1, sizeof(dist));
	memset(mark, 0, sizeof(mark));
	edge start;
	start.e = s;
	start.cost = 0;
	heap.push(start);
	vector<edge>::iterator it;
	dist[s] = 0;
	
	while(!heap.empty())
	{
		edge x = heap.top();
		heap.pop();
		if( mark[x.e] == 1) continue;
		mark[x.e] = 1;
		for( it = g[x.e].begin(); it < g[x.e].end(); it++)
		{
			if( dist[it->e] < 0 || dist[it->e] > dist[x.e] + it->cost ) 
			{
				dist[it->e] = dist[x.e] + it->cost;
				edge aux;
				aux.e = it->e;
				aux.cost = dist[it->e];
				heap.push(*it);
			}
		}
	}
	
}


int main()
{	
   int edges;
   scanf("%d %d %d", &edges,&m,&n);
   for( i = 0 ; i < edges ; i++)
	{
		scanf("%d %d %d",&ai,&wij,&aj);
	    d = wij;
		b = ai;
		c = aj;
		edge e1, e2; 
		e1.e = b;
		e2.e = c;
		e1.cost = e2.cost = d;
        g[b].push_back(e2);
        g[c].push_back(e1);
	}
	dijkstra(m);
	if( dist[n] == -1) printf("NO\n");
	else               printf("YES\n%d\n", dist[n]);
   return 0;
}
