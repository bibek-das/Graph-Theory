#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];

void dfs(int vertex){
	vis[vertex] = true;
	for(int child : adj[vertex]){
		if(vis[child]) continue;
		dfs(child);
	}
}

int main(){

	int v, e;
	int cnt = 0;
	cin >> v >> e;
	for(int i = 0; i < e; i++){
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for(int i = 1; i <= v; i++){
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}