struct node{
    ll mx,mn,sum;
    node(){}
    node(ll mx, ll mn, ll sum):mx(mx),mn(mn),sum(sum){}
};
 
node merge(node l, node r){
    node ans;
    ans.mx=max(l.mx,l.sum+r.mx);
    ans.mn=min(l.mn,l.sum+r.mn);
    ans.sum=l.sum+r.sum;
    return ans;
}
 
ll n,up,dw;
node NEUT(-1e18,1e18,0);
struct STree {
    vector<node> st;int n;
    STree(){}
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, int v){
        if(s+1==e){st[k]=node(v,v,v);return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=merge(st[2*k],st[2*k+1]);
    }
    ii query(int k, int s, int e, int pos, int x){
        if(e<=pos)return {n,x};
        if(s>=pos){
            ll mn=x+st[k].mn,mx=x+st[k].mx;
            if(dw<mn&&mx<up) return {n,x+st[k].sum};
            if(s+1==e) return {s,min(up,max(dw,mx))};
        }
        int m=(s+e)/2;
        ii myl=query(2*k,s,m,pos,x);
        if(myl.fst<n) return myl;
        return query(2*k+1,m,e,pos,myl.snd);
    }
    void upd(int p, int v){upd(1,0,n,p,v);}
    ii query(int a, int b){return query(1,0,n,a,b);}
};

