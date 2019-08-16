int legander(int x){  // 判定是否二次剩余
	int a=qpow(x,(p-1)/2);
	if(a+1==p) return -1;
	return a;
}
ll qpow(ll a,ll b,ll p){
    ll ret=1;
    while(b) {
        if(b&1)ret=ret*a%p;
        a=a*a%p;b>>=1;
    }
    return ret;
}
ll QR(ll a,ll p){ // x^2 == a (mod p)
    if(p==2)return 1;
    ll p2=p/2,tmp=qpow(a,p2,p);
    if(tmp==p-1)return 0;
    if((p+1)%4==0)return qpow(a,(p+1)/4,p);
    ll t=0,h=p-1,b,pb;
    for(; h%2==0;h/=2)t++;
    if(t>=2){
        do{ 
            b=rand()%(p-2)+1;
        }while(qpow(b,p/2,p)!=p-1);
        pb=qpow(b,h,p);
    }
    ll s=qpow(a,h/2,p);
    for(int i=2;i<=t;i++){
        ll ss=(s*s)%p*a%p;
        for(int j=0;i+j<t;j++)ss=ss*ss%p;
        if(ss+1==p)s=s*pb%p;pb=pb*pb%p;
    }
    return s*a%p;
}
