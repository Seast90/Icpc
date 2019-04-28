const int unit = 500;
int s[maxn], color[mod],ans;
int now[maxn], be[maxn];
int n,m,t, tim, a[maxn];
int l,r, sum[maxn];
struct query {
	int l,r,t, tim;
}q[maxn];
struct time1{
	int pos,x,y;
}c[maxn];
bool cmp(const query& a,const query& b){
	return be[a.l]==be[b.l] ? (be[a.r]==be[b.r] ? a.tim<b.tim : a.r < b.r) : a.l<b.l;
}
void update(int x,int d){
	color[a[x]]+=d;
	if(d<0) ans-=(color[a[x]]==0);
	else ans+=(color[a[x]]==1);
}
void change(int pos,int x){
	if(l<=pos&pos<=r){
		update(pos,-1);
		a[pos ]=x;
		update(pos,1);
	}else 
	a[pos] = x;
}
int main(){
   	scanf("%d%d",&n,&m);
   	rep(i,1,n+1) scanf("%d",&a[i]), now[i]=a[i];
 	  rep(i,1,n+1) be[i] = i/unit+1;
   	rep(i,0,m){
   		int x,y;
   		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='Q'){
			q[++t].l=x; q[t].r=y, q[t].tim=tim;
			q[t].t=t;
		}else {
			c[++tim].pos=x,c[tim].x=now[x];
			c[tim].y = y;
			now[x] = y;
		}
	}
	sort(q+1,q+t+1,cmp);
	tim=0; l=1,r = 0;
	rep(i,1,t+1){
		while(tim<q[i].tim) change(c[tim+1].pos,c[tim+1].y) , tim++;
		while(tim>q[i].tim) change(c[tim].pos, c[tim].x), tim--;
		while(l<q[i].l) update(l,-1), l++;
		while(l>q[i].l) update(l-1,1) , l--;
		while(r<q[i].r) update(r+1,1), r++;
		while(r>q[i].r) update(r,-1), r--;
		
		sum[q[i].t] = ans;
 	}
 	rep(i,1,t+1) 
 		printf("%d\n", sum[i]);
    return 0;
}
