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
	void cal(int x,int p,int g[]){
		g[0] = 1;
		if(son[x]) cal(son[x],x,g+1), ans[x] = ans[son[x]]+1;
		for(auto u:v[x]){
			if(u==p || u==son[x]) continue;
			int l=md[u]-dep[u]+1, lx=md[x]-dep[x]+1;
			cal(u,x,g+lx);
			rep(i,1,l+1){
				g[i] = g[i] + g[i+lx-1];
				if(g[i]>g[ans[x]] || ((g[i]==g[ans[x]])&&(i<ans[x])))
						ans[x] = i;
			}
		}
		if(g[ans[x]]==1) ans[x] = 0;
	}
	void gao(){
		dfs(1,1);
		dfs1(1,1);
		find();
	}
};
int len[N],son[N],tmp[N],*f[N],*id=tmp,ans[N];
void dp(int u,int ff){
	f[u][0]=1;
	if (son[u]) f[son[u]]=f[u]+1,dp(son[u],u),ans[u]=ans[son[u]]+1;
	for (int e=head[u];e;e=nxt[e]){
		int v=to[e];if (v==ff||v==son[u]) continue;
		f[v]=id;id+=len[v];dp(v,u);
		for (int j=1;j<=len[v];++j){
			f[u][j]+=f[v][j-1];
			if ((j<ans[u]&&f[u][j]>=f[u][ans[u]])||(j>ans[u]&&f[u][j]>f[u][ans[u]]))
				ans[u]=j;
		}
	}
	if (f[u][ans[u]]==1) ans[u]=0;
}
dfs(1,0);
f[1]=id; id+=len[1];
dp(1,0);
