  bool cmp(const int &a,const int& b){ return dfn[a] < dfn[b]; }
  void add(int x,int y){
    fa[y] = x; 
    g[x].pb(y);
  }

  void insert(int u){
    if(tail <= 1) {if(u!=1)st[++tail] = u;return ;}
    int l = lca(u,st[tail]);
    if(l == st[tail]) {st[++tail] = u;return ;}
    while(tail > 1 && dfn[l] <= dfn[st[tail-1]]) {
        add(st[tail-1],st[tail]);
        --tail;
    }
    if(l != st[tail]) add(l,st[tail]), st[tail] = l;
    st[++tail] = u;
  }
  sort(all(a));
  a.erase(unique(all(a)),a.end());
  sort(all(a),cmp);
  st[tail = 1]=1;
  rep(i,0,sz(a))
    insert(a[i]);
  while(tail>1) add(st[tail-1],st[tail]), tail--;
