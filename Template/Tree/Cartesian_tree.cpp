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
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mes(p) memset(p,0,sizeof(p))
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(x) x.begin(),x.end()
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define lson l,mid,rt<<1
#define pb push_back
#define mp make_pair
//#define ls (rt<<1)
#define se second
//#define rs (ls|1)
#define fi first
typedef pair <int ,int > pi;
typedef vector <int > vi;
typedef long long ll;
const int maxn=200005;
const ll mod = 998244353;
int a[maxn], sum[maxn], ls[maxn], rs[maxn];
int st[maxn], ed[maxn], n;
int ct(int a[], int n) {
    a[n] = INT_MAX;
    vi v(1, n);
    fill_n(ls, n, -1), fill_n(rs, n, -1);
    rep(i, 0, n) {
        while(a[v.back()] < a[i]) ls[i] = v.back(), v.pop_back();
        v.pb(rs[v.back()] = i);
    }
    return v[1];
}
  
void dfs(int u) {
    st[u] = ed[u] = u;
    if(ls[u]) dfs(ls[u]), st[u] = st[ls[u]];
    if(rs[u]) dfs(rs[u]), ed[u] = ed[rs[u]];
}

int main(){	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    int rt = ct(a + 1, n) + 1;
    rep(i, 0, n) ls[i]++, rs[i]++;
    per(i, 1, n + 1) ls[i] = ls[i - 1], rs[i] = rs[i - 1];
    dfs(rt);
	return 0;
}
/*
7
1 2 3 4 3 2 1
*/
