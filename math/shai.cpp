void shai(int N){
	u[1] = phi[1] = 1;
	rep(i,2,N+1){
		if(!f[i]){
			p[++cnt] = i;
			f[i] =i;
			phi[i] = i-1;
			u[i] =-1;
		}
		for (int j=1,k;j<=cnt &&p[j]<=f[i]&&i*p[j]<=N;j++){
			f[k=i*p[j]] = p[j];
			if(p[j] < f[i]){
				phi[k] = phi[i]*phi[p[j]];
				u[k] = u[i]*u[p[j]];
			}else { //  k = p^x;
				phi[k]=phi[i]*p[j];
				u[k] = 0;
			}
		}
	}
}
