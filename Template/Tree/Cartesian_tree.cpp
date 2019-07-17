struct Cartesian_tree{
  void solve(int a[],int n){   // 0 is Virtual..
    rep(i,1,n+1) l[i] = r[i] = i;
    rep(i,1,n+1){
      int u=0;
      while(sz(s) && a[s.top()]>=a[i]){
        u=s.top();  s.pop();
        if(sz(s)&&a[s.top()]>=a[i]) insert(s.top(),u);
      }
      if(u) insert(i,u);
      s.push(i);
    }
    while(sz(s)>1){
      int u=s.top();
      s.pop();
      insert(s.top(),u);
    }
    rep(i,1,n+1)while (sz(e[i])<2) e[i].pb(0); 
    return s.top();
  } 
}
