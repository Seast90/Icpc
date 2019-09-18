 // N is 2 size of tree , id of nodes start from 1
struct LCARMQ{
    static const int N = 101010 << 1;
    int a[20][N] , lft[N] , dep[N] , lg[N] , L;
    int rmin(int x,int y){return dep[x] < dep[y] ? x : y;}
    void add(int x){ a[0][L++] = x;}
    void dfs(int x,int fa,const vi e[]){
        lft[x]=L;add(x);
        for(auto u : e[x]) if(u!=fa) dep[u]=dep[x]+1,dfs(u,x,e),add(x);
    }
    void Build(const vi e[]){
        L = 0;dfs(1,0,e);dep[0] = -1;
        rep(i,2,L) lg[i]=lg[i>>1]+1;
        rep(i,1,20){
            int lim = L+1-(1<<i);
            rep(j,0,lim) a[i][j] = rmin(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
        }
    }
    int lca(int x,int y){
        x = lft[x] , y = lft[y];
        if(x > y) swap(x , y);
        int i = lg[y-x+1];
        return rmin(a[i][x] , a[i][y+1-(1<<i)]);
    }
    int dis(int x,int y){
    	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
}
