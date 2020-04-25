typedef long long int ll;
typedef pair<ll,int> lli;
const int K=19;
lli st[K][200005][2];
lli INF=lli(-1e18,-1); //NEUT
int n;
void upd(lli tar[],lli v){//upd according to oper
	if(v.ss==tar[0].ss || v.ss==tar[1].ss)return;
	if(v.ff>tar[0].ff){
		tar[1]=tar[0];
		tar[0]=v;
	}else if(v.ff>tar[1].ff){
		tar[1]=v;
	}
}
void init(vector<ll> &arr){
	n=arr.size();
	fore(i,0,n){
		st[0][i][0]=lli(arr[i],i);
		st[0][i][1]=INF;
	}
	fore(k,1,K){
		fore(j,0,2*n-(1<<k)+1){
			fore(l,0,2)st[k][j][l]=st[k-1][j][l];
			fore(l,0,2)upd(st[k][j],st[k-1][j+(1<<(k-1))][l]);
		}
	}
}
vector<lli> query(int s, int e){//two maximums, [s,e)
	int k=31-__builtin_clz(e-s);
	lli res[2];
	fore(l,0,2)res[l]=st[k][s][l];
	fore(l,0,2)upd(res,st[k][e-(1<<k)][l]);
	vector<lli> ans(2,INF);
	fore(i,0,2)ans[i]=res[i];
	return ans;
}
