#include <bits/stdc++.h>
using namespace std;
void BFS(int v, vector<int> adj[])
{ // space complexity is o(V)
    // time is O(V+2E) -> o(v+E)
    queue<int> q;
    bool visited_array[v+1];
    q.push(1);
    visited_array[0] = false;
    visited_array[1] = true;
    int node;
    while (!q.empty())
    { // time of q is o(V)
        node = q.front();
        cout<<q.front()<<" ";
        q.pop();
        for (int i : adj[node]) { //O(2E)   for every nodes we traverse all neighbour nodes
            if(!visited_array[adj[node][i]])
            {
                q.push(adj[node][i]);
                visited_array[adj[node][i]] = true;
            }
        }

    }



}
int main() {
    int n;
    int m;
    cin>>n>>m;
    vector<int> adj[n+1]; // space is o(v+2E) is o(v+E)
    int u;
    int v;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // if directed graph this line is nothing so space complexity is o(E)

    }
    BFS(n+1,adj);
    return 0;
}
