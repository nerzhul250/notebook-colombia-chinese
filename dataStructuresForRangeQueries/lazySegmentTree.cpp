void build_tree(int node, int a, int b) {
      if(a > b) return;

      if(a == b) {
            tree[node] = arr[a];
        return;
    }

    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);

    tree[node] = tree[node*2]+tree[node*2+1];
}


void update_tree(int node, int a, int b, int i, int j, ll value) {

    if(a>b)return;

      if(lazy[node] != 0) {
           tree[node] += (b-a+1)*lazy[node];

        if(a != b) {
            lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
        }

           lazy[node] = 0;
      }

    if(a > j || b < i)
        return;

      if(a >= i && b <= j) {
            tree[node] += (b-a+1)*value;

        if(a != b) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

            return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

    tree[node] = tree[node*2]+tree[node*2+1];
}


int query_tree(int node, int a, int b, int i, int j) {

    if(a > b || a > j || b < i) return 0;

    if(lazy[node] != 0) {
        tree[node] += (b-a+1)*lazy[node];

        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a >= i && b <= j)
        return tree[node];

    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

    int res = q1+q2;

    return res;
}

