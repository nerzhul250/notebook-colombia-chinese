#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
int N=300005;
gp_hash_table<ll, ll, chash> seg;

ll get(ll x) { return (seg.find(x) == seg.end()) ? 0 : seg[x]; }
void modify(ll p, ll val) {
    for (seg[p += N]+= val; p > 0; p >>= 1) {
        seg[p >> 1] = get(p) + get(p ^ 1);
    }
}

ll query(ll l, ll r) {
    ll res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += get(l++);
        if (r & 1)
            res += get(--r);
    }
    return res;
}

int Q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;
    ll A,V,L=0;
    fore(i,0,Q){
        cin >> A>>V;
        ll firstInteger=A^L;
        ll randomNumber=V^L;
        modify(firstInteger,randomNumber);
        ll secondInteger=query(1,firstInteger+1);
        cout << firstInteger << " "<<secondInteger<<"\n";
        L=secondInteger;
    }
    return 0;
}

