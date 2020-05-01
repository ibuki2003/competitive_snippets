struct Edge {
    int to, cost;

};
typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;

vector<int> dist;


bool bellman_ford(int n, int s){
    dist = vector<int>(n,INF);
    dist[s] = 0;
    for(int i=0;i<n;i++){
        for(int v=0;v<n;v++){
            for(int k=0;k<graph[v].size();k++){
                Edge e = graph[v][k];
                if(dist[v] != INF && dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    if(i == n-1) return true;
                }
            }
        }
    }
    return false;
}
graph = AdjList(n); // 頂点数
graph[from].push_back((Edge){to,cost});
bellman_ford(n,origin);
