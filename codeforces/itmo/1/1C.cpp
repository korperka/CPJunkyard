#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;

    while (q--) {
        string t, p; cin >> t >> p;
        vector<int> v;

        if (p.size() > t.size()) {
            cout << 0 << "\n\n";
            continue;
        }

        for (int i = 0; i <= t.size() - p.size(); i++) {
            string sub = t.substr(i, p.size());

            bool flag = true;
            for (int j = 0; j < sub.size(); j++) {
                if (sub[j] != p[j] && p[j] != '?') flag = false;
            }

            if (flag) v.push_back(i);
        }

        cout << v.size() << "\n";
        for (int i : v) cout << i << " ";
        cout << "\n";
    }
}