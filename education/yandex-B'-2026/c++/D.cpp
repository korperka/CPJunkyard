#include <unordered_map>
#include <string>
#include <iostream>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, ll> p;

    ll q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            string name;
            cin >> name;
            ll n;
            cin >> n;

            bool f = false;
            unordered_map<string, ll> usd;
            for (int i = 0; i < n; i++) {
                ll k;
                cin >> k;
                string s;
                cin >> s;

                if (p[s] < k) {
                    f = true;
                    continue;
                }

                usd[s] = k;
            }

            if (f) {
                cout << ":(\n";
                continue;
            }

            for (const auto& kv : usd) {
                p[kv.first] -= kv.second;
            }

            cout << "Milkshake " << name << " is ready\n";

            continue;
        }

        ll k;
        cin >> k;
        string s;
        cin >> s;

        p[s] += k;
        cout << s << ": " << p[s] << "\n";
    }
}
