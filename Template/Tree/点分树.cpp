// id starts from 1
namespace Centriod{
	const int N=101010<<1;
	bool vis[N];
	int sz[N], fa[N]; vi e[N];
	void dfssz(int x,int p,int Sz,int &rt){
		sz[x] = 1;
		for(auto u:e[x]) if(!vis[u] && u!=p) dfssz(u, x, Sz, rt), sz[x]+=sz[u];
		if(!rt && sz[x]*2 > Sz) rt = x;
	}
	int dfs(int x){
		int rt = 0;
		dfssz(x,0,0,rt); dfssz(x, 0,sz[x], rt=0);
		vis[rt] = 1;
		for(auto u:e[rt]) if(!vis[u]){
			int v = dfs(u);
			e[rt].pb(v);
			fa[v] = rt;
		}
		return rt;
	}
};
