typedef long long ll;
typedef pair<ll, ll> Line;
typedef pair<ll,ll> ii;

const ll inf = 2e18;

ll f(Line l, ll x){
    return l.first * x + l.second;
}

struct Node{
    int left, right;
    ll xl, xr;
    Line l;
};
vector<Node> nodes;

void init(ll xmin, ll xmax){
    nodes.push_back({-1,-1,xmin,xmax,{0,-inf}});
}

void insert(int n, Line newline){
    ll xl = nodes[n].xl, xr = nodes[n].xr;
    ll xm = (xl + xr) >> 1;

    Line llow = nodes[n].l, lhigh = newline;
    if( f(llow, xl) > f(lhigh,xl) ) swap(llow, lhigh);

    if( f(llow, xr) <= f(lhigh, xr) ){
        nodes[n].l = lhigh;
        return;
    }
    else if( f(llow, xm) < f(lhigh, xm) ){
        nodes[n].l = lhigh;
        if( nodes[n].right == -1 ){
            nodes[n].right = nodes.size();
            nodes.push_back({-1,-1,xm+1,xr,{0,-inf}});
        }
        insert(nodes[n].right, llow);
    }
    else{
        nodes[n].l = llow;
        if( nodes[n].left == -1 ){
            nodes[n].left = nodes.size();
            nodes.push_back({-1,-1,xl,xm,{0,-inf}});
        }
        insert(nodes[n].left, lhigh);
    }
}

ll get(int n, ll xq){
    if( n == -1 ) return -inf;
    ll xl = nodes[n].xl, xr = nodes[n].xr;
    ll xm = (xl + xr) >> 1;

    if( xq <= xm ) return max(f(nodes[n].l, xq), get(nodes[n].left, xq));
    else return max(f(nodes[n].l, xq), get(nodes[n].right, xq));
}

