struct Ex_lucas{
	ll mod;
	inline ll qpow(ll a,ll b,ll p){
		ll s = 1;
		while(b){
			if(b&1) s = s * a % p;
			a = a * a %p;
			b >>= 1;
		}
		return s;
	}
	inline ll exgcd(ll a,ll b,ll &x,ll &y){
		if(!b) { x = 1; y = 0; return a;}
		ll res = exgcd(b, a%b, x, y), t;
		t = x; x = y; y = t - a/b * y;
		return res;
	}
	inline ll inv(ll n,ll p){
		ll x, y;
		exgcd(n , p, x, y);
		return (x += p) > p ? x - p : x;
	}
	inline ll crt(ll a,ll p) {
		ll x = mod/p;
		return a * inv(x, p) %mod * x %mod;
	}
	inline ll cal(ll n,ll p){
		ll s = 0;
		for(ll i = n;i;i/=p) s += i/p;
		return s;
	}
	inline ll fac(ll n,ll p,ll pk){
		if(!n) return 1;
		ll res = 1;
		for(ll i = 2;i <= pk;++i)
			if(i%p) (res *= i) %= pk;
		res = qpow(res, n/pk, pk);
		for(ll i = 2;i <= n%pk;++i)
			if(i%p) (res *= i) %= pk;
		return res*fac(n/p, p, pk)%pk;
	}
	inline ll C(ll n,ll m,ll p,ll pk){
		ll a = fac(n, p, pk), b = fac(m ,p, pk), c = fac(n-m, p, pk);
		ll k = 0;
		k += cal(n, p) - cal(m, p) - cal(n-m, p);
		return a * inv(b, pk)%pk * inv(c, pk) %pk * qpow(p, k, pk) % pk;
	}
	inline ll lucas(ll n,ll m,ll p){
		mod = p;
		ll res = 0;
		for(ll i = 2;i * i <= p;i++)
		if(p % i == 0){
			ll pk = 1;
			while(p%i==0) pk *= i, p /= i;
			(res += crt(C(n, m, i, pk), pk)) %= mod;
		} 
		if(p > 1) (res += crt(C(n, m, p, p), p)) %= mod;
		return res;
	}
}
