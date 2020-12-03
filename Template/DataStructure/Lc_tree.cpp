void build(int l,int r,int rt){
    s[rt] = mp(0, linf);
    mn[rt] = linf;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(l, mid, rt<<1);
    build(mid + 1, r, rt<<1|1);
}
inline ll calc(const line &a,int x){
    // ll y = S[x];
    return a.fi * y + a.se;
}
void update(int L,int R,line k,int l,int r,int rt){
    if(L <= l && r <= R){
        int mid = l + r >> 1;
        if(calc(s[rt], l) >= calc(k, l) && calc(s[rt], r) >= calc(k, r)){
            s[rt] = k;
            mn[rt] = min(mn[rt], min(calc(k, l), calc(k, r)));
            if(l < r){
                mn[rt] = min(mn[rt], min(mn[rt<<1], mn[rt<<1|1]));
            }
        }else if(calc(s[rt], l) > calc(k, l) || calc(s[rt], r) > calc(k, r)){
            if(calc(s[rt], mid) > calc(k, mid)) swap(s[rt], k);
            if(calc(s[rt], l) > calc(k, l))
                update(L, R, k, l, mid, rt << 1);
            else update(L, R, k, mid + 1, r, rt<<1|1);
            if(l < r){
                mn[rt] = min(mn[rt], min(mn[rt<<1], mn[rt<<1|1]));
            }
            mn[rt] = min(mn[rt], min(calc(s[rt], l), calc(s[rt], r)));
        }
        return ;
    }
    int mid = l + r >> 1;
    if(L <= mid) update(L, R, k, l, mid, rt<<1);
    if(R > mid) update(L, R, k, mid + 1, r, rt<<1|1);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
    mn[rt] = min(mn[rt], min(calc(s[rt], l), calc(s[rt], r)));
}
ll qry(int L,int R,int l,int r,int rt){
    //dd(0), dd(l), de(r);
    if(L <= l && r <= R) return mn[rt];
    int mid = l + r >> 1;
    ll res = min(calc(s[rt], max(L, l)), calc(s[rt], min(R, r)));
    if(L <= mid) res = min(res, qry(L, R, l, mid, rt<<1));
    if(R > mid) res = min(res, qry(L, R, mid + 1, r, rt<<1|1));
    return res;
}
