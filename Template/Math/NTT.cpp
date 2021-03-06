const int M = 1 << 17 << 1;
int a[M], b[M];

struct NTT{
	static const int G = 3, P = 1004535809; //P = C*2^k + 1
	int N, na, nb, w[2][M], rev[M];
	ll kpow(ll a, int b){
		ll c = 1;
		for (; b; b >>= 1,a = a * a % P) if (b & 1) c = c * a %P;
		return c;
	}
	void FFT(int *a, int f){
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
				for (int k = 0, l = 0, x, y; k < i; k++, l += t)
					x = (ll) w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
		if (f) for (int i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (ll)a[i] * x % P;
	}
	void work(){
		int d = __builtin_ctz(N);
		w[0][0] = w[1][0] = 1;
		for (int i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++) {
			rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
			w[0][i] = (ll)x * w[0][i-1] % P, w[1][i] = (ll) y * w[1][i-1] % P;
		}
	}
	void doit(int *a, int *b, int na, int nb){ // [0, na)
		for (N = 1; N < na + nb - 1; N <<= 1);
		rep(i, na, N) a[i] = 0;
		rep(i, nb, N) b[i] = 0;
		work(), FFT(a,0), FFT(b,0);
		rep(i, 0, N) a[i] = (ll)a[i] * b[i] % P;
		FFT(a, 1);
		//rep(i, 0, N) cout << a[i] << endl;
	}
} ntt;
void solve(int l,int r){
	if(l==r) return ;
	int mid = l+r>>1, len = r-l+1;
	solve(l,mid);
	rep(i, l, mid+1) a[i-l] = f[i];
	rep(i, l, r+1) b[i-l] = g[i-l];
	T.doit(a, b, mid-l+1, len);
	rep(i, mid+1, r+1) f[i] = add(f[i],a[i-l]);
	solve(mid+1, r);
}
