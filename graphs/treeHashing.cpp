auto rnd=bind(uniform_int_distribution<long long>(1,1e13), mt19937(time(0)));//random range 1->1e13
map<ll,ll> mp;
vector<int> g[300010];//change size and random range accordingly
ll subt[300010];// same
 
ll f(ll x){
	if(!mp.count(x)){
		mp[x]=rnd();
	}
	return mp[x];
}
 
ll dfs(int v, int par=-1){
	ll sum=0;
	for(int c:g[v]) if(c!=par){
		sum+=dfs(c,v);
	}
	subt[v]=f(sum);
	return subt[v];
}

set<ll> ans;//data structure to save/accumulate distinct hashes
 
void go(int v, int par=-1, ll hashpar=0){
	ll sum=hashpar;
	for(int c:g[v]) if(c!=par) sum+=subt[c];	//sumando los de mis hijos
	ans.insert(f(sum));//save, or accumulate
	for(int c:g[v]) if(c!=par){
		go(c,v,f(sum-subt[c]));
	}
}
