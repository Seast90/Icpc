void  get_dis(int x,int pre,int d){
	dis[++cnt] = d;
	for(int i=head[x],v=e[i].to;i;i=e[i].next, v= e[i].to)
	if (!f[v]&& v!=pre)  get_dis(v,x,d+e[i].w);
}
void dfssz(int x,int fa,int Sz,int &rt){
        sz[x] = 1;
        for(auto t : g[x]) if(!vis[t]&&t!=fa) dfssz(t,x,Sz,rt) , sz[x]+=sz[t];
        if(!rt && sz[x]*2>Sz) rt=x;
 }
int work(int x,int d){
	cnt = 0;
	get_dis(x,0,d);
	sort(dis+1,dis+cnt+1);
	int num = 0;
	rep(i,1,cnt+1)	{
		int o = m - dis[i];
		num+= upper_bound(dis+i+1,dis+cnt+1,o) - lower_bound(dis+i+1,dis+cnt+1,o);
	}
	return num;
}
int get_ans(int x){
	int rt=0;dfssz(x,0,0,rt);dfssz(x,0,sz[x],rt=0);
	f[root] = 1;
	int sum = work(root, 0);
	for(int i=head[root], v=e[i].to; i ;i = e[i].next, v= e[i].to)
	if (!f[v])	{
		sum -= work(v, e[i].w);
		sum += get_ans(v);
	}
	return sum;
}
