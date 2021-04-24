int lg2(int n){
  REPR(i,31){
    if(n&bit(i)){
      return i;
    }
  }
  return -1;
}
int min_2pow(int n){
  int l=lg2(n);
  if(bit(l)<n)l++;
  return bit(l);
}
template<typename T>
struct segtree{
  int size;
  vector<T> tree;
  function<T(T,T)> func;
  T unit;
  segtree(int n, function<T(T,T)> func, T unit): func(func), unit(unit){
    size=min_2pow(n);
    tree=vector<T>(2*size-1, unit);
  }
  
  void put(int pos, const T&value){
    tree[size-1+pos]=value;
  }
void resolve(int pos){
  pos=size-1+pos;
  while(pos!=0){
    pos=(pos-1)/2;
    int child1=pos*2+1;
    int child2=child1+1;
    tree[pos]=func(tree[child1],tree[child2]);
  }
}
  void resolve(){
    REPR(i,size-1){ // bottom(but not leaves) first
      int child1=i*2+1;
      int child2=child1+1;
      tree[i]=func(tree[child1],tree[child2]);
    }
  }
  T get(const int&start, const int&end, int _search_node=0){ // (start,end]
    if(start>end)return unit;
    int row=lg2(_search_node+1);
    int node_width=bit(lg2(size)-row);
    int node_start=node_width*(_search_node-bit(row)+1);
    int node_end=node_start+node_width;
    if(end<=node_start || node_end<=start)return unit;
    if(start<=node_start && node_end<=end){ // all conains
      return tree[_search_node];
    }
    int child1=_search_node*2+1;
    int child2=child1+1;
    
    return func(get(start,end,child1), get(start,end,child2));
  }
};
