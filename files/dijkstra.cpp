// O( (E+V) log V)
using len_type=ll;

struct Edge {int to;len_type cost;};
vector<vector<Edge>> graph;
void dijkstra(int start, vector<len_type>& dist){
  using qp = pair<len_type, int>;
  int n=graph.size();
  dist.clear();
  dist.resize(n, inf<len_type>);
  priority_queue<qp, vector<qp>, greater<qp>> q;
  dist[start]=0;
  q.push({0, start});
  while(!q.empty()){
    qp p=q.top();
    q.pop();
    int v=p.second;
    if(dist[v]<p.first)continue;
    for(const Edge&e:graph[v]){
      if(chmin(dist[e.to], dist[v]+e.cost)){
        q.push({dist[e.to], e.to});
      }
    }
  }
}
