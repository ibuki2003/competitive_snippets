using len_type=ll;

struct Edge {int to;len_type cost;};
vector<vector<Edge>> graph;
bool bellman_ford(int s, vector<len_type>& d) {
  const int n = g.size();
  d.clear();
  d.resize(n, inf<len_type>);
  d[s] = 0;
  REP(i, n) {
    REP(v, n) {
      REPA(k, graph[v]) {
        const Edge& e = graph[v][k];
        if(d[v] != inf<len_type> && d[e.to] > d[v] + e.cost){
          d[e.to] = d[v] + e.cost;
          if(i == n-1) return true;
        }
      }
    }
  }
  return false;
}
