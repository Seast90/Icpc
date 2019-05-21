int get_size(int x,int pre){
	siz[x] = 1;
	for(int i=head[x], v=e[i].to; i ; i=e[i].next, v=e[i].to)
	if (pre!=v && !f[v]) siz[x]+= get_size(v,x);
	return siz[x];
}
void  get_dis(int x,int pre,int d){
	dis[++cnt] = d;
	for(int i=head[x],v=e[i].to;i;i=e[i].next, v= e[i].to)
	if (!f[v]&& v!=pre)  get_dis(v,x,d+e[i].w);
}
void get_root(int x,int pre){
	int num = tot - siz[x]; 
	for(int i=head[x],v=e[i].to;i;i=e[i].next, v =e[i].to)
	if (!f[v]&& v!=pre) get_root(v, x), num = max(num, siz[v]);
	if (num< minn)	{
          minn = num;
          root = x;
	}
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
	cnt = 0;
	minn = INF;
	tot = get_size(x,0);
	get_root(x, 0);
	f[root] = 1;
	int sum = work(root, 0);
	for(int i=head[root], v=e[i].to; i ;i = e[i].next, v= e[i].to)
	if (!f[v])	{
		sum -= work(v, e[i].w);
		sum += get_ans(v);
	}
	return sum;
}
