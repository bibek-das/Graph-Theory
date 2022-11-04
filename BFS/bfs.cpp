#include<bits/stdc++.h>
using namespace std;


const int N = 1e5;
vector<int> adj[N];
bool vis[N];

queue<int> que;

void bfs(int source){
	que.push(source);
	vis[source] = true;
	while(!que.empty()){
		int par = que.front();
		cout << par << " ";
		que.pop();
		for(auto x : adj[par]){
			if(vis[x]) continue;
			que.push(x);
			vis[x] = true;
		}
	}
}



int main(){

	int v,e;
	cin >> v >> e;
	for(int i=1;i<=e;i++){
		int v1,v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	bfs(1);
}