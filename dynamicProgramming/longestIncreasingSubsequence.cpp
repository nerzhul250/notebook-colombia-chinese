typedef long long int ll;
int P[1000000];
const ll INF = 1e18;
vector<ll> d;
vector<int> M;
int lis(vector<ll> const& a) {
    int n = a.size();
    d=vector<ll>(n+1, INF);
	M=vector<int>(n+1,-1);
    d[0] = -INF;
    fore(i,0,n){
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j]){
			d[j] = a[i];
			M[j] = i;
			P[i] = M[j-1];
		}
    }
    int ans = 0;
    fore(i,0,n+1){
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
vector<ll> lisFull(vector<ll> const& a){
	vector<ll> S;
	int k=M[lis(a)];
	while(k!=-1){
		S.pb(a[k]);
		k=P[k];
	}
	reverse(ALL(S));
	return S;
}
