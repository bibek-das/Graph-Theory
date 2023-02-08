#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3*1e5;
vector<pair<ll,ll>> g[N];
const ll INF = LONG_MAX;
vector<ll> dist(N,INF);

void dijkstra(ll src){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0,src});
	dist[src] = 0;
	while(!pq.empty()){
		ll node = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if(dist[node] < cost) continue;
		for(auto child : g[node]){
			ll child_v = child.first;
			ll wt = child.second;
			if(dist[node] + wt < dist[child_v]){
				dist[child_v] = dist[node] + wt;
				pq.push({dist[child_v],child_v});
			}
		}
	}
}

int main(){
	ll v,e;
	cin >> v >> e;
	for(int i = 0;i < e;i++){
		ll u, v, wt;
		cin >> u >> v >> wt;
		g[u].push_back({v,wt});
	}
	dijkstra(1);
	for(int i = 1;i <= v;i++){
		cout << dist[i] << " \n"[i == v];
	}
}
