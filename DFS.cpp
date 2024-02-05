#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>Adjacencey[N];
bool visited[N];

void dfs(int u) {
    // section 1 : actions just after entering a node
    visited[u] = true;
    cout << "Visiting node: " << u << endl; // Comment: Visiting the current node
    
    for(int val : Adjacencey[u]) {
        // section 2 : actions before entering a new neighbor
        if(visited[val] == true)
            continue;
        dfs(val); // Recursively visit the neighbor
        
        // section 3 : actions after exiting a node
    }
    
    // section 4 : actions before exiting node u
}

int main() {
    int vertex,edges;
    cin>>vertex>>edges;
    
    // Input graph edges
    for(int i=0;i<edges;i++) {
        int u,v;
        cin>>u>>v;
        Adjacencey[u].push_back(v);
        Adjacencey[v].push_back(u);
    }
    
    dfs(1); // Start DFS from node 1
    
    // Output adjacency list of each node
    for(int i=1;i<=vertex;i++) {
        cout<<"Node  : "<<i<<" :- (";
        for(int val : Adjacencey[i]) {
            cout<<val<<" ";
        }
        cout<<")"<<endl;
    }
    
    return 0;
}
