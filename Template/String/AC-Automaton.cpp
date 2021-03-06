// [0,L) , N-1 is virtual , 0 is rt , init!!
struct Trie{
	static const int N =101010, M=26;
	int ne[N][M], fail[N], fa[N], rt, L, sum[N];
	void ini(){
		fill_n(ne[fail[0]=N-1],M,0); 
		fill_n(sum,N,0); 
		L = 0,rt=newnode();
	}
	int newnode(){fill_n(ne[L],M,0);return L++;}
	void add(char *s,int v){
		int p = rt;
		for(int i=0;s[i];++i){
			int c= s[i] -'a';
			if(!ne[p][c]) ne[p][c] =newnode(), fa[L-1] = p;
			p = ne[p][c];
		}
		sum[p] += v;
	}
	void build(){
		vi v;v.pb(rt);
		rep(i,0,sz(v)){
			int c= v[i];
			rep(i,0,M) ne[c][i] ?
			 v.pb(ne[c][i]), fail[ne[c][i]] = ne[fail[c]][i]:
			 	ne[c][i] = ne[fail[c]][i];
		}
		rep(i,1,sz(v))
			sum[v[i]] += sum[fail[v[i]]];
	}
};
