#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

struct setset {
    vector<set<ll>> sets;
    map<ll, set<ll>> nums;

    setset(ll m) {
        sets = vector<set<ll>>(m);
    }

    void add(ll e, ll s) {
        sets[s].insert(e);
        nums[e].insert(s);
    }

    void del(ll e, ll s) {
        sets[s].erase(e);
        nums[e].erase(s);
    }

    void clear(ll s) {
        for (const ll &c : sets[s]) nums[c].erase(s);
        sets[s].clear();
    }

    void listset(ll s) {
        if (sets[s].empty()) cout << -1;
        else for (const ll &c : sets[s]) cout << c << " ";

        cout << "\n";
    }

    void listsetsof(ll e) {
        if (nums[e].empty()) cout << -1;
        else for (const ll &c : nums[e]) cout << c << " ";

        cout << "\n";
    }
};

int main() {
    ll n, m, k; cin >> n >> m >> k;
    setset p(m+1);

    while (k--) {
        string t; cin >> t;

        if (t == "ADD") {
            ll e, s; cin >> e >> s;
            p.add(e, s);
        } else if (t == "DELETE") {
            ll e, s; cin >> e >> s;
            p.del(e, s);
        } else if (t == "CLEAR") {
            ll s; cin >> s;
            p.clear(s);
        } else if (t == "LISTSET") {
            ll s; cin >> s;
            p.listset(s);
        } else if (t == "LISTSETSOF") {
            ll e; cin >> e;
            p.listsetsof(e);
        }
    }
}

//placeholder for edjudge
