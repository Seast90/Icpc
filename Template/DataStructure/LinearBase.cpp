struct LB{
    ll f[65];
    int pos[65];
    void insert(ll x,int y){
        for(int i=64;~i;--i)
        if(x>>i&1){
            if(!f[i]){
                f[i] = x;   pos[i] = y;
                break;
            }
            if(pos[i] < y){
                swap(pos[i], y);
                swap(f[i],x);
            }
            x^=f[i];
        }
    }
    ll qmax(int x){
        ll s= 0;
        for(int i=31;~i;--i){
            if(f[i] && pos[i]>=x)
                s = max(s,s^f[i]);
        }
        return s;
    }
    ll& operator [](int x){
        return a[x];
    }   
};    
void merge(const LB &a,LB &b,LB &ans){
    tmp  =v = a;
    rep(i,0,65)if(b[i]){
        ll x = b[i], now = 0;
        int g = 0;
        for(int j=64;j>=0;j--) if(x>>j&1){
            if(!tmp[j]){
                g = 1; tmp[j] = x; v[j] = now;
                break;
            }
            x ^= tmp[j]; now^=v[j];
        }
        if(!g) ans.insert(now);
    }
}
