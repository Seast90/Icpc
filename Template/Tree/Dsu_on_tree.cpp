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
      dfs(u,x,0); //暴力统计轻边的贡献，ty= 0表示递归完成后消除对该点的影响
    }
    if(son[x]) dfs(son[x],x,1), Son=son[x]; //统计重儿子的贡献，不消除影响
    add(x,p,1); 
    ans[x] = sum;   Son=0;//暴力统计所有轻儿子的贡献
    if(!ty) add(x,p,-1), sum=0,mx=0; //如果需要删除贡献的话就删掉
  }
}
