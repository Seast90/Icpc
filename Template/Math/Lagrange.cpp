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
