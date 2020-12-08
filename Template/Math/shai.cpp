struct Math{
	int s[maxn], phi[maxn],cnt, p[maxn], u[maxn], f[maxn];
	int inv2 = 500000004, inv6 = 166666668, N, n;
	const int maxn=3000005;
	const ll mod = 1e9+ 7;
	void pre(){
		inv[1]=1;
		for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	inline int add(int a,int b){
		if ((a+=b)>=mod) a-=mod;
		return a;
	}
	inline int mul(int a,int b){
		return 1ll*a*b%mod;
	}
	void shai(int N){
		u[1] = phi[1] = 1;
		rep(i,2,N+1){
			if(!f[i]){
				p[++cnt] = i;
				f[i] =i;
				phi[i] = i-1;
				u[i] =  -1;
			}
			for(int j=1,k;j<=cnt&&p[j]<=f[i]&&i*p[j] <=N;j++){
				f[k=i*p[j]] = p[j];
				if(p[j] < f[i]){
					phi[k] =mul(phi[i],phi[p[j]]);
					u[k] = u[i]*u[p[j]];
				}else {
					phi[k] =mul(phi[i], p[j]);
					u[k] = 0;
				}
			}
		}
		rep(i,1,N+1)
			s[i] = add(s[i-1], mul(phi[i],i));
	}
	unordered_map < int ,int > w;
	int du(int n){ // maybe long long 
		if(n<=N) return s[n];
		if(w[n]) return w[n];
		int ans = mul(mul(n+1,n),mul(mul(2,n)+1,inv6));
		for(int l=2,r;l<=n;l=r+1){
			r=n/(n/l);
			int  s=mul(mul(add(l,r),add(r+1,mod-l)),inv2);
			s= mul(s, du(n/l));
			ans = add(ans,mod-s);
		}
		return w[n] = ans;
	}
};
