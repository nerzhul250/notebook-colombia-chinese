struct lex_compare {
    bool operator() (const int64_t& lhs, const int64_t& rhs) const {
        stringstream s1, s2;
        s1 << lhs;
        s2 << rhs;
        return s1.str() < s2.str();
    }
};
set<int64_t, lex_compare> s;
