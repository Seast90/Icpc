struct PD{	
	void get_dis(int x,int p,int d){
		dis[++cnt] = d;
		for(auto u:v[x])
			if(!vis[u] && u!=p) get_dis(u,x,d+1);
	}
	void dfssz(int x,int p,int Sz,int &rt){
		sz[x] = 1;
		for(auto u: v[x]) if(!vis[u]&&u!=p) dfssz(u,x,Sz,rt) , sz[x]+=sz[u];
		if(!rt && sz[x]*2>Sz) rt=x;
	}
	ll cal(int x,int d){
		//cal
	}
	ll work(int x){
		int rt=0;dfssz(x,0,0,rt);dfssz(x,0,sz[x],rt=0);
		vis[rt] = 1;
		ll sum = cal(rt, 0);
		for(auto u:v[rt])if(!vis[u])sum -=cal(u,1); // 1 = u.se 
		for(auto u:v[rt])if(!vis[u])sum +=work(u);
		return sum;
	}
};
