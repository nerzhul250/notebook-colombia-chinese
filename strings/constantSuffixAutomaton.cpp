struct state {
    int len, link, numOfTransitions=0;
    int next[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
};

const int MAXLEN = 100000;
state st[MAXLEN * 2];
int dp[MAXLEN * 2+5];
int sz, last;

void sa_init() {
    for(int i=0;i<MAXLEN*2;i++){
        st[i]=state();
        dp[i]=0;
    }
    sz=0;

    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && st[p].next[c]==-1) {
        st[p].next[c] = cur;
        st[p].numOfTransitions++;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            copy(begin(st[q].next), end(st[q].next),begin(st[clone].next));
            st[clone].link = st[q].link;
            st[clone].numOfTransitions=st[q].numOfTransitions;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

