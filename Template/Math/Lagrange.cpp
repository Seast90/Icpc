ll ans = 0;
rep(i,0,n){
	ll s=y[i];
	rep(j,0,n)
	if(i!=j){ 
		ll xx = (k-x[j]+mod)%mod;
		ll yy = qm((x[i]-x[j]+mod)%mod,mod-2);
		s=s*xx%mod*yy%mod;
	}
	ans+=s;
	ans%=mod;
}

cin >> n >> k; // fac[k] 
f[0] = 0;
rep(i,1,k+2){
	f[i]=add(f[i-1],qm(i,k));
}
if(n<k+2){
	cout << f[n];
	return 0;
}
fac[0]=1;
rep(i,1,k+3) fac[i] = mul(fac[i-1],i);
inv[k+2]=qm(fac[k+2],mod-2);
for(int i=k+1;i>=0;i--) inv[i] = mul(inv[i+1],i+1);

int sum = 1, ans = 0;
for(int i=n;i>=n-k-1;i--) sum = mul(sum,i); // sum = mul(fac[n],inv[n-k-2])
rep(i,0,k+2){
	int s = mul(sum,qm(n-i,mod-2));
	s= mul(s,mul(inv[k+1-i],inv[i]));
	if((k+1-i)%2==0)ans = add(ans,mul(f[i],s));
	else ans = (ans-mul(f[i],s)+mod)%mod;
}
cout << ans ;
