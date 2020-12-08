void pre(){   // O(n*sqrt(n))
    P[0] = 1;
    rep(i, 1, N>>1){
        five[(i-1)<<1] = i*(3*i-1)/2;
        five[(i-1)<<1|1] = i*(3*i+1)/2;
    }
    rep(i, 1, N){
        rep(j, 0, N){
            if(five[j] > i) break;
            if(j & 2) P[i] -= P[i - five[j]];
            else P[i] += P[i - five[j]];
            P[i] %= mod;
        }
        if(P[i] < 0) P[i] += mod;
    }
}
