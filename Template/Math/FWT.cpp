void fwt(int a[],int n,int t){
	for(int d=1;d<n;d<<=1)
	for(int m=d<<1,i=0;i<n;i+=m)
	for(int j=0;j<d;j++){
		int x=a[i+j], y=a[i+j+d];
		if(t==1){
			// xor: a[i+j]=add(x,y), a[i+j+d]=add(x,mod-y);
			// ans: a[i+j]=add(x,y);
			// or:  a[i+j+d]=add(x,y);
		}else {
			//xor: a[i+j]=mul(add(x,y),inv2), a[i+j+d]=mul(add(x,mod-y),inv2);
			//ans: a[i+j]=add(x,mod-y);
			//or: a[i+j+d] = add(y,mod-x);
		}
	}
}

void fst(int a[],int n, int N){ // j|k == i , j&k == 0; O((2^m)*m*m)
    rep(i,0,N) cnt[i] = __builtin_popcount(i);
	int m = cnt[N-1];
	rep(i,0,n)	d[cnt[a[i]]][a[i]]++;
	rep(i,0,m)	fwt(d[i], N, 3); // or
	rep(i,0,m) rep(j,0,i+1)
		rep(k,0,N)
			e[i][k] = add(e[i][k], mul(d[i-j][k], d[j][k]));
	rep(i,0,m) fwt(e[i], N, -3);
	rep(i,0,N) c[i] = e[cnt[i]][i];
}
