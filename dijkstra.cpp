//Adonis!!
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9 + 10;
vector<int> dist(N, INF);
vector<pair<int, int>> graph[N];
bool vis[N];

void dijkstra(int src) {
    
    set<pair<int, int>> st;
    st.insert({0, src});
    dist[src] = 0;
    while (st.size() > 0) {
        auto node = *st.begin();
        int v = node.second;
        int dist_v = node.first;
        st.erase(st.begin());
        if (vis[v]) continue;
        vis[v] = true;
        for (auto child : graph[v]) {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 1;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        while (e--) {
            int v1, v2, wt;
            cin >> v1 >> v2 >> wt;
            graph[v1].push_back({v2, wt});
            graph[v2].push_back({v1, wt});
        }
        int source;
        cin >> source;
        dijkstra(source);
        cout << "Case " << cs << ":" << endl;
        for (int i = 0; i < v; i++) {
            if (dist[i] == INF) cout << "Impossible" << endl;
            else cout << dist[i] << endl;
        }
        for (int i = 0; i < N; i++) {
            dist[i] = INF;
        }
        memset(vis, 0, sizeof(vis));
        for (auto x : graph) {
            x.clear();
        }
        cs++;
    }

    return 0;
}
