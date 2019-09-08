// O(len^2)
vi BM(vi s) {
	vi C(1, 1), B(1, 1);
	int L = 0, m = 1, b = 1;
	rep(n, 0, sz(s)) {
		ll d = 0;
		rep(i, 0, L+1) (d += 1ll * C[i] * s[n-i]) %= P;
		if(d == 0) ++m;
		else {
			vi T = C;
			ll c = P - d * kpow(b, P - 2) % P;
			while(sz(C) < sz(B) + m) C.pb(0);
			rep(i, 0, sz(B)) C[i + m] = add(C[i + m], mul(c, B[i]));
			if(2 * L <= n) L = n + 1 - L, B = T, b = d, m = 1;
			else ++m;
		}
	}
	reverse(all(C));
	rep(i, 0, sz(C)) C[i] = P - C[i];
	return vi(C.begin(), C.end() - 1);
}
// a_{m} = \sum_{j=0}^{m−1}a_{j}*c_{j} O(m^2lgn)
int linear_recurrence(ll n, int m, vi a, vi c) {
	if (n<m) return (a[n]+P)%P;
	vector<ll> v(m, 0), u(m<<1, 0);
	v[0] = 1;
	for(ll x = 0, W = n ? 1ll<<(63 - __builtin_clzll(n)) : 0; W; W >>= 1, x <<= 1) {
		fill(all(u), 0);
		int b = !!(n & W); if(b) x++;
		if(x < m) u[x] = 1;
		else {
			rep(i, 0, m) rep(j, 0, m) (u[i + b + j] += v[i] * v[j]) %= P;
			per(i, m, 2*m) rep(j, 0, m) (u[i - m + j] += c[j] * u[i]) %= P;
		}
		copy(u.begin(), u.begin() + m, v.begin());
	}
	ll ans = 0;
	rep(i, 0, m) (ans += v[i] * a[i]) %= P;
	return (ans+P)%P;
}
