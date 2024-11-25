#include <bits/stdc++.h>
using namespace std;
void DFS(int node,vector<int>adj[],bool visited_array[])
{
    visited_array[node] = true;
    cout<<node<<" ";
    for (int i : adj[node]) {
        if(!visited_array[i])
        {
            DFS(i,adj,visited_array);
        }
    }

}
void DFS_graph(int node,int v,vector<int>adj[])
{ // space is o(V)
    // time o(v+2E) -> o(v+E)
    bool visited_array[v];
    DFS(node,adj,visited_array);


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
    DFS_graph(1,n+1,adj);

    return 0;
}
