struct Excrt{
	ll a[maxn], b[maxn]; // a%b
	int n;
	void init(int _n){
		n = _n;
		rep(i,0,n) cin>> b[i] >> a[i];
	}
	ll qmul(ll a,ll b,ll mod){
		ll s=0;
		while(b){
			if(b&1) s=(s+a)%mod;
			a=(a+a)%mod;
			b>>=1;
		}
		return s;
	}
	ll exgcd(ll a,ll b,ll &x,ll &y){
		if(!b) {x=1;y=0; return a;}
		ll g=exgcd(b,a%b,x,y), t=x;
		x=y, y=t-a/b*y;
		return g;
	}
	ll excrt(){
		ll x,y,M=b[0],ans=a[0];
		ans =(ans%M+M)%M;
		rep(i,1,n){
			ll a1 = M,b1 = b[i], c = (a[i]+b1-ans%b1)%b1;
			ll g = exgcd(a1,b1,x,y), bg=b1/g;
			if(c%g!=0) return -1;
			x=qmul(x,c/g,bg);
			ans+=x*M;
			M*=bg;
			ans=(ans%M+M)%M; 
		}
		return ans;
	}
};
