//所有跟节点有关的信息都要开两倍空间
struct NODE{
	int ch[26];
	int len,fa,cnt;
	void clear() {
		memset(ch,0,sizeof(ch));len = 0; 
	}
}dian[maxn<<1];
struct Sam{
	int last,tot;// tot 节点数量
	void init(){
		last = 1;tot = 1;
		dian[1].clear();
	}
	void add(int c) {
		int p = last, now = dian[p].ch[c];
		if(now){
			if(dian[now].len == dian[p].len+1) dian[now].cnt++, last = now;
			else {
				int nq = ++tot; dian[nq].clear();
				dian[nq] = dian[now];
				dian[nq].len = dian[p].len + 1;
				dian[nq].cnt = 1;
				dian[now].fa = nq;
				for(;p&&dian[p].ch[c] == now;p = dian[p].fa) dian[p].ch[c] = nq;
				last = nq;
			}
		}else {
			int np = last = ++tot;
			dian[np].clear();
			dian[np].cnt = 1;
			dian[np].len = dian[p].len+1;
			for(;p&&!dian[p].ch[c];p = dian[p].fa) dian[p].ch[c] = np;
			if(!p) dian[np].fa = 1;
			else {
				int q = dian[p].ch[c];
				if(dian[q].len == dian[p].len+1) dian[np].fa = q;
				else {
					int nq = ++tot;dian[nq].clear();
					dian[nq] = dian[q]; dian[nq].cnt = 0;
					dian[nq].len = dian[p].len+1;
					dian[q].fa = dian[np].fa = nq;
					for(;p&&dian[p].ch[c] == q;p = dian[p].fa) dian[p].ch[c] = nq;
				}
			}
		}
	}
	void insert(char *s,int n){
		last = 1;
		rep(i,0,n) add(s[i]-'a');
	}
	//id[i]： 按 len 排序后，排在第 i 位的结点编号
	int cnt[maxn<<1],id[maxn<<1];
	void bucketsort() {
		memset(cnt,0,sizeof(cnt));
		rep(i,1,tot+1) ++cnt[dian[i].len];
		rep(i,1,tot+1) cnt[i] += cnt[i-1];
		rep(i,1,tot+1) id[cnt[dian[i].len]--] = i;
	}
	void topogao() {
		bucketsort();
		per(i,1,tot+1) {
			int u = id[i],fa = dian[u].fa;
			dian[fa].cnt += dian[u].cnt;
		}
	}
	char s[maxn<<1], str[maxn<<1];
	void run(char *s,int n) {
		int u = 1,len = 0;
		rep(i,0,n) {
			int c = s[i] - 'a';
			while(u && !dian[u].ch[c]) u = dian[u].fa,len = dian[u].len;
			if(u) {
				u = dian[u].ch[c];
				len++;
			}else u = 1,len = 0;
		}
	}
}sam;
/* 
 后缀自动机可以在线创建，依次加入末尾的字符。 
 值得注意的是，对于同一个子串，可以代表这个子串的节点，在整棵自动机逐渐创建的过程中，会不断变化， 
 若需要在建自动机的过程中，一直维护某个子串的节点位置，则在每次更新自动机之后， 
 都需要通过检查原本子串节点的父节点的长度是否大于等
