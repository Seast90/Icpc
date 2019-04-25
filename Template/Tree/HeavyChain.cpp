int p, n, m, r, cnt ,a[maxn];
int s[maxn<<2],  lz[maxn<<2];
int fa[maxn], siz[maxn],id[maxn];
int top[maxn],son[maxn],wt[maxn],dep[maxn];
vector < int > v[maxn];
int add(int a, int b) {
	if((a += b) >= p) a -= p;
	return a;
}
int mul(int a, int b) {
	return 1ll * a * b % p; 
}
void push_down(int rt,int m){
	if(lz[rt]){
		lz[ls] = add(lz[ls],lz[rt]);
		lz[rs] = add(lz[rs],lz[rt]);
		s[rs] = add(s[rs],mul(lz[rt],m>>1));
		s[ls] = add(s[ls],mul(lz[rt],(m-(m>>1))));
		lz[rt]=0;
	}
}
int qr(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return s[rt];
    }
    int mid = l+r>>1,res=0;
    push_down(rt,r-l+1);
    if(mid>=L) res=add(res,qr(L,R,lson));
    if(mid<R) res=add(res,qr(L,R,rson));
    return res;
}
void build(int l,int r,int rt){
	if(l==r) {
		s[rt]=wt[l];
		return ;
	}
	int mid = l+r>>1;
	build(lson);	build(rson);
	s[rt]=add(s[ls],s[rs]);
}
void update(int L,int R,int z,int l,int r,int rt){
	if(L<=l&&r<=R){
		s[rt]=add(s[rt],mul(z,(r-l+1)));
		lz[rt] = add(lz[rt],z);
		return ;
	}
	int mid = l+r>>1;
	push_down(rt,r-l+1);
	if(mid>=L) update(L,R,z,lson);
	if(mid <R) update(L,R,z,rson);
	s[rt]=add(s[ls],s[rs]);
}
void dfs(int x,int p){ // dfs(r,0)
    dep[x] = dep[p]+1;
    fa[x] = p;
    siz[x] = 1;
    int maxson = -1;
    for(auto u:v[x]){
        if(u!=p){
            dfs(u,x);
            siz[x]+=siz[u];
            if(siz[u]>maxson) son[x]=u,maxson=siz[u];
        }
    }
}
void dfs2(int x,int topf){ //dfs2(r,r)
    id[x]= ++cnt;
    wt[cnt]=a[x];
    top[x]=topf; 
    if(!son[x]) return ;
    dfs2(son[x],topf);
    for(auto u:v[x]){
        if(u!=fa[x] && u!=son[x])
            dfs2(u,u);
    }
}
int qr2(int x,int y){
	int ans = 0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=add(ans,qr(id[top[x]],id[x],1,n,1));
        x=fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x,y);  // y is lca
    ans =add(ans,qr(id[y],id[x],1,n,1));
    return ans; 
}
void qr1(int x,int y,int z){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(id[top[x]],id[x],z,1,n,1);
		x=fa[top[x]];
	}
	if(dep[x]< dep[y]) swap(x,y);
	update(id[y],id[x],z,1,n,1);
}
