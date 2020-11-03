struct Tree{
	int dis, val, ls, rs, rt ;
}tr[N]; 

inline int get(int x){ 
	return tr[x].rt == x ? x : tr[x].rt = get(tr[x].rt) ; 
}
inline int merge(int x, int y){
	if (!x || !y) return x + y; 
	if (tr[x].val > tr[y].val || (tr[x].val == tr[y].val && x > y)) 
		swap(x, y);
	int &ls = tr[x].ls, &rs = tr[x].rs;
	rs = merge(rs, y); 
	if (tr[ls].dis < tr[rs].dis) 
		swap(ls, rs);
	tr[ls].rt = tr[rs].rt = tr[x].rt = x;
	tr[x].dis = tr[rs].dis + 1;
	return x ;
}
inline void pop(int x){ 
	tr[x].val = -1;
	int ls = tr[x].ls, rs = tr[x].rs;
	tr[ls].rt = ls;
	tr[rs].rt = rs;
	tr[x].rt = merge(ls, rs); 
}
void init(int n){
	tr[0].dis = -1;
	rep(i, 1, n + 1)
		tr[i].rt = i,
		tr[i].ls = tr[i].rs = 0;
}
void uni(int x,int y){
	if(tr[x].val == -1 || tr[y].val == -1) return;
	x = get(x); y = get(y);
	if(x != y)
		tr[x].rt = tr[y].rt = merge(x, y);
}
