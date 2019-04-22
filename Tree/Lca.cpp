void dfs(int x,int p,int d){ // dfs(rt,rt,0)
	dep[x] = d;
	f[x][0] = p;
	rep(i,1,30)
		f[x][i] = f[f[x][i-1]][i-1];
	for(auto u:v[x])
		if(u!=p)
			dfs(u,x,d+1);
}
int lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	for(int i=29,d=dep[u]-dep[v];i>=0;i--)
		if(d>>i&1) u=f[u][i];
	if(u==v) return v;
	for(int i=29;i>=0;i--)
	if(f[u][i]!=f[v][i])
		u=f[u][i], v=f[v][i];
	return f[u][0];
}
