struct dsu{
    inline void build(int &rt,int l,int r){
        rt=++cnt;
        if(l==r){fa[rt]=l;return ;}
        int mid = l +r >> 1;
        build(ls[rt],l,mid);build(rs[rt],mid+1,r);
    }
    inline void merge(int pre,int &rt,int l,int r,int pos,int Fa){
        rt=++cnt;ls[rt]=ls[pre],rs[rt]=rs[pre];
        if(l==r)
        {
            fa[rt]=Fa;
            dep[rt]=dep[pre];
            return ;
        }
        int mid = l +r >>1;
        if(pos<=mid)merge(ls[pre],ls[rt],l,mid,pos,Fa);
        else merge(rs[pre],rs[rt],mid+1,r,pos,Fa);
    }
    inline void update(int rt,int l,int r,int pos){
        if(l==r){dep[rt]++;return ;}
        int mid = l+r>>1;
        if(pos<=mid)update(ls[rt],l,mid,pos);
        else update(rs[rt],mid+1,r,pos);
    }
    inline int query(int rt,int l,int r,int pos) {
        if(l==r)return rt;
        int mid = l +r >>1;
        if(pos<=mid)return query(ls[rt],l,mid,pos);
        else return query(rs[rt],mid+1,r,pos);
    }
    inline int find(int rt,int pos) {
        int now=query(rt,1,n,pos);
        if(fa[now]==pos)return now;
        return find(rt,fa[now]);
    }
    inline void uion(int t,int x,int y){
        T[t] = T[t-1];
        int X=find(T[t],x) ,Y=find(T[t],y);
        if(fa[X]!=fa[Y]){
            if(dep[X]>dep[Y])swap(X,Y);
            merge(T[t-1],T[t],1,n,fa[X],fa[Y]);
            if(dep[X]==dep[Y])update(T[t],1,n,fa[Y]);
        }
    }
    inline bool qr(int t,int x,int y){
        T[t] = T[t-1];
        int X=find(T[t],x) ,Y=find(T[t],y);
        if(fa[X]==fa[Y]) return 1;
        return 0;
    }
}d;
