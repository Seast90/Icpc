struct Dsuontree{
  void add(int x,int p,int d){
    cal(x);
    for(auto u:v[x]){
      if(u==p || u==Son) continue;
      add(u,x,d);
    }
  }
  void dfs(int x,int p,int ty){
    for(auto u:v[x]){
      if(u==son[x] || u==p) continue;
      dfs(u,x,0);
    }
    if(son[x]) dfs(son[x],x,1), Son=son[x];
    add(x,p,1);
    ans[x] = sum;   Son=0;
    if(!ty) add(x,p,-1), sum=0,mx=0;
  }
}
