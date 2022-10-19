//graph input using adjacency list method
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

void unweighted(){
	//for unweighted graphs
	vector<int> adj[N];
	int n, m;
	cin >> n >> m;

	adj[n].push_back(m);
	//for undirected graphs
	adj[m].push_back(n);
}

void weighted(){
	// for weighted graphs
	vector<pair<int,int>> adj[N];
	int n, m, wt;
	cin >> n >> m >> wt;

	adj[n].push_back({m,wt});
	//for undirected graphs
	adj[m].push_back({n,wt});

}

int main(){

	unweighted();
	weighted();

}

// Adjacency list
// O(N + M)
// N = 10^5