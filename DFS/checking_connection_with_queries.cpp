#include<bits/stdc++.h>
using namespace std;


const int N = 1e5;
vector<int> adj[N];
vector<int> parent(N);
bool vis[N];
int par;



void dfs(int source) {

	vis[source] = true;
	for (auto child : adj[source]) {
		if (vis[child]) continue;
		parent[child] = par;
		dfs(child);
	}
}


int main() {

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for (int i = 0; i < v; i++) {
		if (!vis[i]) {
			par = i;
			parent[i] = i;
			dfs(i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int start, end;
		cin >> start >> end;
		if (parent[start] == parent[end]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
