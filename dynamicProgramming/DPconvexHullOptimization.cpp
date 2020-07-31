struct Point {
    ld x, y;
};
struct Line {
    ll a, b;
    static Point intersect(const Line& l1, const Line& l2) {
        ld x, y;

        x = 1.0L * (l2.b - l1.b) / (l1.a - l2.a);
        y = l1.a * x + l1.b;

        return { x, y };
    }

    ll eval(ll x) {
        return a * x + b;
    }
};


struct CHT {
    vector<Line> lines;

    void addLine(const Line& l) {//Lines must be added in order of decreasing slope
        while (lines.size() >= 2 && Line::intersect(l, lines.end()[-1]).x > Line::intersect(l, lines.end()[-2]).x) {
            lines.pop_back();
        }
        lines.pb(l);
    }

    ll query(ll x) {
        int l = 0, r = lines.size() - 1;

        while (l != r) {
            int mid = (l + r) / 2;
            if (lines[mid].eval(x) < lines[mid + 1].eval(x)) l = mid + 1;
            else r = mid;
        }

        return lines[l].eval(x);
    }
};

