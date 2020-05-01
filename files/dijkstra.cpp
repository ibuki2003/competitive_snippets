// O( (E+V) log V)
using len_type=ll;

struct Edge {int to;len_type cost;};
vector<vector<Edge>> graph;
void dijkstra(int start, vector<len_type>& dist){
    int n=graph.size();
    fill(all(dist), inf<len_type>);
    dist.resize(n, inf<len_type>);
    priority_queue<P,vector<P>,greater<P>> q;
    dist[start]=0;
    q.push(make_pair(0,start));
    while(!q.empty()){
        P p=q.top();
        q.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;
        for(const Edge&e:graph[v]){
            if(dist[e.to]>dist[v]+e.cost){
                dist[e.to]=dist[v]+e.cost;
                q.push(make_pair(dist[e.to],e.to));
            }
        }
    }
}
