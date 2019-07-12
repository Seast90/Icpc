struct LongChain{
	void dfs(int x,int p){
		md[x] = dep[x] = dep[p]+1;
		f[x][0] = p;
		rep(i,1,21) f[x][i] = f[f[x][i-1]][i-1];
		for(auto u:v[x]){
			if(u==p) continue;
			dfs(u,x);
			if(md[u] > md[son[x]]) son[x]=u,md[x] = md[u];
		}
	}
	void dfs1(int x,int tp){
		top[x] = tp;
		len[x] = md[x] - dep[top[x]] + 1;
		if(son[x]) dfs1(son[x],tp);
		for(auto u:v[x]){
			if(u==f[x][0] || u==son[x]) continue;
			dfs1(u,u);
		}
	}
	void find(){
		rep(i,2,n+1) hbit[i] = hbit[i>>1] + 1;
		rep(i,1,n+1)
		if(i==top[i]){
			int l=0,x=i;
			while(l<len[i]&&x!=f[x][0]) x=f[x][0], ++l, U[i].pb(x);
			x=i;
			rep(j,1,len[i])
				x=son[x], D[i].pb(x);
		}
	}
	int k_ancestor(int x,int k){
		if(k>=dep[x]) return 0; // !!!
		if(!k) return x;
		x=f[x][hbit[k]]; k^=(1<<hbit[k]);
		if(!k) return x;
		if(dep[x] - dep[top[x]] == k) return top[x];
		if(dep[x] - dep[top[x]] > k) return D[top[x]][dep[x]-dep[top[x]]-k-1];
		return U[top[x]][k-dep[x]+dep[top[x]]-1];
	}
	void gao(){
		dfs(1,1);
		dfs1(1,1);
		find();
	}
};
