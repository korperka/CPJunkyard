#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

ll cid = 0;

struct Passenger {
    ll a, b, c, d, prof, id;

    Passenger() {
        cin >> a >> b >> c >> d;
        prof = a - b;
        id = cid;
        cid++;
    }

    bool operator<(const Passenger& snd) const {
        if (prof != snd.prof)
            return prof < snd.prof;
        return id < snd.id;
    }
};

int main() {
    ll n, m, h;
    cin >> n >> m >> h;
    vector<multiset<Passenger>> vh(h), vih(h);

    for (int i = 0; i < n; i++) {
        auto p = Passenger();
        vh[p.c - 1].insert(p);
        vih[p.d - 1].insert(p);
    }

    ll k = 0, ans = 0;

    multiset<Passenger> sit;
    multiset<Passenger> stand;
    for (int i = 0; i < h; i++) {
        for (const auto& p : vih[i]) {
            k -= (sit.contains(p) ? p.a : p.b);

            sit.erase(p);
            stand.erase(p);
        }

        if (sit.size() < m) {
            while (sit.size() < m && !stand.empty()) {
                auto p = *--stand.end();

                if (p.prof < 0) break;

                sit.insert(p);
                stand.erase(--stand.end());

                k -= p.b - p.a;
            }
        }

        for (const auto& p : vh[i]) {
            ll minprof = sit.empty() ? -1e9 - 1 : (*sit.begin()).prof;

            if (p.prof > 0 && (minprof < p.prof || sit.size() < m)) {
                if (sit.size() >= m) {
                    auto pmin = *sit.begin();
                    stand.insert(pmin);
                    sit.erase(sit.begin());

                    k -= pmin.a - pmin.b;
                }

                sit.insert(p);
                k += p.a;
            } else {
                stand.insert(p);

                k += p.b;
            }
        }

        ans += k;
    }

    cout << ans << "\n";
}
