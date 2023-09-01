#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool>vis;
vector<vector<int>>graph;
void dfs(int node){
    if(vis[node]==1)return;
    vis[node] = 1;
    for(int next_node:graph[node])
    {
        dfs(next_node);
    }
}

void graph_init() {
    int n,m;
    cin>>n>>m;
    graph=vector<vector<int>>(n+1);
    vis=vector<bool>(n+1);
    int from,to;
    for(int i=0;i<m;i++){
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

//depth of the tree
int dfs(int node,int c){
    vis[node]=1;
    if(graph[node].empty()) return c + 1;
    for(int next_node:graph[node]){
        return dfs(next_node, c + 1);
    }
    return 0;
}

vector<vector<int>> cycles;

void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
    if (color[u] == 2) {
        return;
    }

    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;

        int cur = p;
        v.push_back(cur);

        while (cur != u) {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;

    color[u] = 1;

    for (int v : graph[u]) {

        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
    color[u] = 2;
}


/*
Graph representation:
______________________________________

1-edge list:-
*Is creating an array of pairs.
**--> pair<ll,ll>edgeList[M]; --->M is number of max edges.
* Memory --> o(M) .
* Finding neighbours of a node --> o(M).
* Finding connectivity of 2 nodes -->o(M).
(It is not very efficient).
----------------------------------------

2-adj matrix:-
*Is creating a bool 2d array, connected nodes is 1 , not connected is 0.
**--> bool adjMatrix[N][N]; --->N is max number of nodes,M is max number of edges.
* Memory -->o(N^2).
* Finding neighbours of a node --> o(N).
* Finding connectivity of 2 nodes -->o(1)  (this is why we use it).
------------------------------------------

3-adj list:-
*Is creating a vector of arrays.
**--> vector<ll> adjList[N];
**--> vector<vector<ll>>adj(N);
* Memory -->o(N) (but this is the worst case ,not like adj matrix which is average case).
* Finding neighbours of a node --> o(N) (the same as memory).
* Finding connectivity of 2 nodes -->o(N)  (the same).
*/
const int N = 1e3 + 3, M = 2e4 + 4;

int n, k, u, v;

pair<int, int> edgeList[M];
bool adjMatrix[N][N];
//vector<int> adjList[N];
vector<vector<ll>>adjList;

void printNeighborsOf(int u) {
    for (int j = 0; j < k; j++) {   // O(k)
        if (edgeList[j].first == u) printf("%d ", edgeList[j].second == u);
        else if (edgeList[j].second == u) printf("%d ", edgeList[j].first == u);
    }

    for (int i = 0; i < n; i++) {   // O(n)
        if (adjMatrix[u][i] == 1)
            cout<<v;
    }

    for (int v : adjList[u]) {  // O(neighbors)
        cout<<v;
    }
}

bool areNeighbors(int u, int v) {
    // for (int j = 0; j < k; j++) {
    //     if (edgeList[j].first == u && edgeList[j].first == v || edgeList[j].first == v && edgeList[j].first == u )
    //         return true;
    // }
    // return false;

    // return adjMatrix[u][v] == true;

    for (int y : adjList[u]) {  // O(neighbors)
        if (y == v) return true;
    }
    return false;
}
