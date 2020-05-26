typedef long long int ll;
typedef pair<ll,ll> ii;
struct hash_pair { // works for any pair
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
unordered_map<ii,int,hash_pair> mp;
