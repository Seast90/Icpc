for(int i=2;i<=n;i++) lg[i]= lg[i>>1]+1;
rep(t,1,lg[n]+1){
		for(int j=1;j+(1<<t)-1<=n;j++)
			st[j][t] = max(st[j][t-1],st[j+(1<<(t-1))][t-1]);
	}
