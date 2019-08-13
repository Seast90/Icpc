int merge(int x,int y){
	if(!x || !y) return x|y;
	int t=++cnt;
	s[t] = min(s[x],s[y]);
	ls[t] = merge(ls[x],ls[y]);
	rs[t] = merge(rs[x],rs[y]);
	return t;
}
