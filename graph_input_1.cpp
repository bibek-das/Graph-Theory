//graph input using adjacency matrix method
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int graph[N][N];					// Adjacency matrix Array (N x N)

int main(){

	int n, m;
	cin >> n >> m;					// n = Number of vertices, m = number of edges 
	for(int i = 0; i < m; i++){
		int v1, v2;					// v1 = vertex_1, v2 = vertex_2	     
		cin >> v1 >> v2;	
		graph[v1][v2] = 1;			
		graph[v2][v1] = 1;			// for undirected graphs
	}

}