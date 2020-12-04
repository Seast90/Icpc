void solve(int vl,int vr,int st,int ed){
    if(st > ed) return ;
    if(vl == vr){
        rep(i, st, ed + 1)
            if(q[i].op > 0) ans[q[i].op] = V[vl - 1];
        return ;
    }
    int mid = (vl + vr) >> 1;
    int lt = 0, rt = 0;
    rep(i, st, ed + 1){
        if(q[i].op == 0){
            if(q[i].y <= mid) {  add(q[i].x, q[i].d); lq[++lt] = q[i]; }
            else rq[++rt] = q[i];
        }else {
            int cnt = ask(q[i].y) - ask(q[i].x - 1);
            if(cnt >= q[i].z) lq[++lt] = q[i];
            else q[i].z -= cnt, rq[++rt] = q[i];
        }
    }
    rep(i, st, ed + 1)
        if(q[i].op == 0 && q[i].y <= mid) 
            add(q[i].x, -q[i].d);
    rep(i, 1, lt + 1) 
        q[st + i - 1] = lq[i];
    rep(i, 1, rt + 1)
        q[st + lt + i - 1] = rq[i];
    solve(vl, mid, st, st + lt - 1);
    solve(mid + 1, vr, st + lt, ed);
}
