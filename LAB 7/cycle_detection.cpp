#include <bits/stdc++.h>
#include <vector> 
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
    bool dfs( int node , vector<vector<int>>& adj , int vis[] , int path[] ){
        vis[node] = 1;
        path[node]= 1;
        for ( auto it : adj[node]){
            if( !vis[it] )
        {
                if ( dfs( it , adj , vis , path) == true)
                    return true ;
        }
            else if ( path[it] )
                return true ;
   }
   path[node]=0;
    return false;  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                adj[u].push_back(v);   }
int path[V];
int vis[V];
for (int i =0 ; i < V ; i++ ){
    path[i]= 0;
    vis[i] = 0;}
for ( int i =0 ; i< V ; i++){
    if ( !vis[i] )  {
        if ( dfs ( i , adj , vis , path) == true)
            return true ;
                    }
    }
    return false ; 
}
int main(){
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};   
    if (isCyclic(V, edges)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    return 0;
}