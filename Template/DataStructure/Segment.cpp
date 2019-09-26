struct Segment(){
	ll sum[maxn<<2], mn[maxn<<2], la[maxn<<2], h[maxn];
	int cnt[maxn<<2], n, q;
	inline void pu(int rt){
		sum[rt] = sum[rt<<1|1] + sum[rt<<1];
		mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
		cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
	}
	inline void build(int l,int r,int rt){
		if(l==r){
			sum[rt] = mn[rt] = h[l];
			cnt[rt] = 1;
			return ;
		}
		int mid = l+r>>1;
		build(l, mid, rt<<1);
		build(mid+1, r,rt<<1|1);
		pu(rt);
	}
	inline void pd1(int rt,int s){
		sum[s] -= cnt[s] * la[rt];
		if(cnt[s]) mn[s] -= la[rt];
		la[s] += la[rt];
	}
	inline void pd(int rt){
		if(la[rt]){
			pd1(rt, rt<<1);
			pd1(rt, rt<<1|1);
			la[rt] = 0;
		}
	}
	inline void update(int L,int R,ll w,int l,int r,int rt){
		if(L <= l && r <= R && mn[rt] > w){
			if(!cnt[rt]) return ;
			sum[rt] -= w * cnt[rt];
			mn[rt] -= w;
			la[rt] += w;
			return ;
		}else if(l==r){
			sum[rt] = 0;
			mn[rt] = 0x3f3f3f3f;
			cnt[rt] --;
			return ;
		}
		int mid = l+r>>1;
		pd(rt);
		if(L<= mid) update(L, R, w, l, mid, rt<<1);
		if(R > mid) update(L, R, w, mid+1, r, rt<<1|1);
		pu(rt);
	}
	
	inline ll qrymn(int L,int R,int l,int r,int rt){
		if(L <= l && r <= R) return mn[rt];
		int mid = l+r>>1;
		ll s = 0x3f3f3f3f;
		pd(rt);
		if(L <= mid) s = min(qrymn(L, R, l, mid, rt<<1), s);
		if(R > mid ) s= min(qrymn(L, R, mid+1, r, rt<<1|1), s);
		return s;	
	}
	inline ll qry(int L,int R,int l,int r,int rt){
		if(L <= l && r <= R) return sum[rt];
		int mid = l+r>>1;
		ll s =0;
		pd(rt);
		if(L <= mid) s += qry(L, R, l, mid, rt<<1);
		if(R > mid) s+= qry(L ,R, mid+1 ,r, rt<<1|1);
		return s;
	}
	inline void upd(int x,int y,ll w){
		ll m = qrymn(x, y, 1, n, 1);
		if(m == 0x3f3f3f3f) return ;
		update(x, y, w, 1, n,1);
	}
}
