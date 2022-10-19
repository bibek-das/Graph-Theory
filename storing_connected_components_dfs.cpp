#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
vector<vector<int>> cc;
vector<int> current_cc;
bool vis[N];

void dfs(int vertex){
	vis[vertex] = true;
	current_cc.push_back(vertex);
	for(int i = 0; i < adj[vertex].size(); i++){
		if(vis[adj[vertex][i]]) continue;
		dfs(adj[vertex][i]);
	}
}

int main(){

	int v, e;
	cin >> v >> e;
	for(int i = 0;i < e; i++){
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for(int i = 1; i <= v; i++){
		if(vis[i]) continue;
		current_cc.clear();
		dfs(i);
		cc.push_back(current_cc);
	}
	for(auto x : cc){
		for(int i = 0; i < x.size(); i++){
			cout << x[i] << " ";
		}
		cout << endl;
	}
}