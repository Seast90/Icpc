for(int i=2;i<=n;i++) lg[i]= lg[i>>1]+1;
rep(t,1,lg[n]+1){
		for(int j=1;j+(1<<t)-1<=n;j++)
			st[j][t] = max(st[j][t-1],st[j+(1<<(t-1))][t-1]);
	}
// [0,n)
// 实现不同功能请谨慎复用
// 求下标最好用 pair 存
struct ST{
	static const int N = 101010;
	int a[20][N], lg[N];
	void build(int *v, int n){
		rep(i, 2, n + 1) lg[i] = lg[i >> 1] + 1;
		rep(i, 0, n) a[0][i] = v[i];
		rep(i, 1, lg[n] + 1) rep(j, 0, n - (1 << i) + 1) {
			a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << i >> 1)]);
		}
	}
	int qry(int l, int r){
		if(l > r) swap(l, r);
		int i = lg[r - l + 1];
		return max(a[i][l] , a[i][r + 1 - (1 << i)]);
	}
};
