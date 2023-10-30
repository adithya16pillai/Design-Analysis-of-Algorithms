#include <iostream>
#include <queue>
#define maxN 101
using namespace std;

bool BFS(int ways[maxN][maxN], int * parent, bool * visited, int n, int s, int t){
    queue<int> q;
    parent[s] = -1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n ; ++i) {
            if (!visited[i] && ways[u][i] > 0) {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }
    return visited[t];
}

bool DFS(int rGraph[maxN][maxN], int * parent, bool * visited, int n, int x, int t){
	if(x == t) return true;
	visited[x] = true;
	for(int i = 0; i < n; ++i){
		if(rGraph[x][i] > 0 && !visited[i]){
			parent[i] = x;
			if(DFS(rGraph, parent, visited, n, i, t))
				return true;
		}
	}
	return false;
}

int FordFulkerson(int graph[maxN][maxN], int n, int s, int t){
	int rGraph[maxN][maxN];
	int parent[maxN];
	bool visited[maxN];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			rGraph[i][j] = graph[i][j];
	int max_flow = 0;
	while(BFS(rGraph, parent, visited, n, s, t)){ 
		memset(visited, false, sizeof(visited));
		int path_flow = 0xfffffff; 
		for(int v = t; v != s; v = parent[v]){
			int u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		for(int v = t; v != s; v = parent[v]){
			int u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main (){
	int n, m;
	int graph[maxN][maxN];
	cin >> n >> m; 
	for(int j = 0, a, b, k; j < m; ++j){
		cin >> a >> b >> k;
		graph[a][b] = k;
	}
	int s, t;
	cin >> s >> t; 
	cout << "Max Flow in this graph is: " << FordFulkerson(graph, n, s, t) << endl;

}
