struct LPSTree{
	vector<bool> hasflag; // if node has a flag (sometimes, you can omit this)
	vector<int> flag;     // the actual value of the flag
	vector<int> st,l,r;
	vector<int> treeVersion;
	int n;
	int newparent(int lson,int rson){
		int p=st.size();
		l.pb(lson);
		r.pb(rson);
		flag.pb(0);
		hasflag.pb(false);
		st.pb(st[lson]+st[rson]);
		return p;
	}
	int new_node(int v){
		int p=st.size();
		l.pb(-1);
		r.pb(-1);
		flag.pb(0);
		hasflag.pb(false);
		st.pb(v);
		return p;
	}
	int init(int L, int R, vector<int> &a){
		if(L==R)return new_node(a[L]);
		int M=(L+R)/2,lson=init(L,M,a),rson=init(M+1,R,a);
		return newparent(lson,rson);
	}
	LPSTree(vector<int> &a){
		n=a.size();
		int root=init(0,n-1,a);
		treeVersion.pb(root);
	}
	// returns a new node with a lazy flag
	int newlazykid(int node, int delta, int L, int R) {
		int p = st.size();
		l.pb(l[node]);
		r.pb(r[node]);
		flag.pb(flag[node]); // need this since lazy kid might be lazy before
		hasflag.pb(true);
		/* range increase */
		flag[p] += delta;
		st.pb(st[node] + (R - L + 1) * delta);
		/* edit depending on the problem */
		return p;
	}
	void propagate(int p, int L, int R) {
		if (hasflag[p]) {
			if (L != R) { // spread the laziness
				int M=(L+R)/2;
				l[p] = newlazykid(l[p], flag[p], L, M);//does not work in c++11
				r[p] = newlazykid(r[p], flag[p], M + 1, R);
			}
			// reset flag
			hasflag[p] = false;
			flag[p]=0;
		}
	}
	// range update on [a:b] with value x, on the tree rooted at p
	int update(int a, int b, int x, int p, int L, int R) {
		if (b < L || R < a) return p;
		if (a <= L && R <= b) return newlazykid(p, x, L, R); 
		propagate(p, L, R); // always do this before going down
		int M=(R+L)/2;
		return newparent(update(a, b, x, l[p] , L, M),
						 update(a, b, x, r[p] , M + 1, R));
	}
	// range query on [a:b], on the tree rooted at p
	int query(int a, int b, int p, int L, int R) {
		if (b < L || R < a)   return 0;
		if (a <= L && R <= b) return st[p];
		propagate(p, L, R); // always do this before going down
		int M=(R+L)/2;
		return query(a, b, l[p], L, M) + query(a, b, r[p], M + 1, R);
	}
	int update(int a,int b,int x,int version){
		int newRoot=update(a,b,x,treeVersion[version],0,n-1);
		treeVersion.pb(newRoot);
		return newRoot;
	}
	int query(int a,int b, int version){
		return query(a,b,treeVersion[version],0,n-1);
	}
};
