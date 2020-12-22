#define ls (rt<<1)
#define rs (ls | 1)
struct node {
	ll sm;
	int ma, mi, sa, si, na, ni, ln, ti, ta, lz;
	inline void pr(const int x) { 
		sm = ma = mi = x, sa = -inf, si = inf;
		na = ni = 1;
	}
	inline void pu(const int x){
		sm += 1ll * x * ln;
		ma += x, mi += x, sa += x, si += x, lz += x;
	}
	inline void pi(const int x){
		sm += 1ll * x * ni;
		if(ma == mi) ma += x;
		if(sa == mi) sa += x;
		mi += x, ti += x;
	}
	inline void pa(const int x){
		sm += 1ll * x * na;
		if(mi == ma) mi += x;
		if(si == ma) si += x;
		ma += x, ta += x; 
	}
	inline void merge(const node &l,const node &r){
		sm = l.sm + r.sm; mi = min(l.mi, r.mi); ma = max(l.ma, r.ma);
		ni = 0, (mi == l.mi)&&(ni += l.ni), (mi == r.mi)&&(ni += r.ni);
		na = 0, (ma == l.ma)&&(na += l.na), (ma == r.ma)&&(na += r.na);
		si = min(l.si, r.si);
		(l.mi > mi)&&(si = min(si, l.mi));
		(r.mi > mi)&&(si = min(si, r.mi));
		sa = max(l.sa, r.sa);
		(r.ma < ma)&&(sa = max(sa, r.ma));
		(l.ma < ma)&&(sa = max(sa, l.ma));
	}
}t[N<<2];
void build(int l,int r,int rt){
	t[rt].ln = r - l + 1;
	if(l == r) {
		t[rt].pr(a[l]);
		return ;
	}
	int mid = l + r>>1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	t[rt].merge(t[ls], t[rs]);
}
inline void pd(int rt){
	if(t[rt].lz) t[ls].pu(t[rt].lz), t[rs].pu(t[rt].lz), t[rt].lz = 0;
	if(t[rt].ti) {
		if(t[ls].mi <= t[rs].mi) t[ls].pi(t[rt].ti);
		if(t[ls].mi >= t[rs].mi) t[rs].pi(t[rt].ti);
		t[rt].ti = 0;
	}
	if(t[rt].ta){
		if(t[ls].ma >= t[rs].ma) t[ls].pa(t[rt].ta);
		if(t[ls].ma <= t[rs].ma) t[rs].pa(t[rt].ta);
		t[rt].ta = 0;
	}
}
void upd_sum(int L,int R,int x,int l,int r,int rt){
	if(L <= l && r <= R) {
		t[rt].pu(x);
		return ;
	}
	int mid = l + r>>1;
	pd(rt);
	if(L <= mid) upd_sum(L, R, x, l, mid, ls);
	if(R > mid) upd_sum(L, R, x, mid + 1, r, rs);
	t[rt].merge(t[ls], t[rs]);
}
void upd_min(int L,int R,int x,int l,int r,int rt){
	if(x >= t[rt].ma) return ;
	if(L <= l && r <= R && x > t[rt].sa){
		t[rt].pa(x - t[rt].ma);
		return ;
	}
	int mid = l + r>>1;
	pd(rt);
	if(L <= mid) upd_min(L, R, x, l, mid, ls);
	if(R > mid) upd_min(L, R, x, mid + 1, r, rs);
	t[rt].merge(t[ls], t[rs]);
}
void upd_max(int L,int R,int x,int l,int r,int rt){
	if(x <= t[rt].mi) return ;
	if(L <= l && r <= R && x < t[rt].si){
		t[rt].pi(x - t[rt].mi);
		return ;
	}
	int mid = l + r>>1;
	pd(rt);
	if(L <= mid) upd_max(L, R, x, l, mid, ls);
	if(R > mid) upd_max(L, R, x, mid + 1, r, rs);
	t[rt].merge(t[ls], t[rs]); 
}
ll qsum(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R) return t[rt].sm;
	int mid = l + r>>1;
	ll res = 0;
	pd(rt);
	if(L <= mid) res += qsum(L, R, l, mid, ls);
	if(R > mid) res += qsum(L, R, mid + 1, r, rs);
	return res;
}
int qmin(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R) return t[rt].mi;
	int mid = l + r >> 1, res = inf;
	pd(rt);
	if(L <= mid) res = min(res, qmin(L, R, l, mid, ls));
	if(R > mid) res = min(res, qmin(L, R,mid + 1, r, rs));
	return res;
}
int qmax(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R) return t[rt].ma;
	int mid = l + r >> 1, res = -inf;
	pd(rt);
	if(L <= mid) res = max(res, qmax(L, R, l, mid, ls));
	if(R > mid) res = max(res, qmax(L, R,mid + 1, r, rs));
	return res;
}
