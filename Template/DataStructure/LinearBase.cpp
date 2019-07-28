struct LinearBase{
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
