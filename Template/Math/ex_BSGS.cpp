unordered_map<int, int > ha;
inline int ex_BSGS(int x,int z,int p){
    if(z == 1) return 0;
	int k = 0, a = 1;
	for(int d=__gcd(x,p);d!=1;d=__gcd(x,p)){
		if(z%d) return -1;
		z/=d; p/=d; ++k;
		a = 1ll*x/d*a%p;
		if(z==a) return k;
	}
	ha.clear();
	int m = sqrt(p) + 1;
	for(int i = 0,t = z;i<m;++i,t = mul(t,x)) ha[t] = i;
	for(int i = 1,tt = qm(x,m),t = mul(a,tt); i<=m; ++i, t = mul(t,tt)){
		if(ha.find(t)==ha.end()) continue;
		return i*m - ha[t] + k;
	}
	return -1;
}
