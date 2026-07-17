#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;

    while (q--) {
        string s, t; cin >> s >> t;
        int ans = 0;

        if (t.size() > s.size()) {
            cout << s.size() * (s.size() + 1) / 2 << "\n";
            continue;
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j <= s.size()-i; j++) {
                string sub = s.substr(i, j);
                if (sub.find(t) == string::npos) ans++;
            }
        }

        cout << ans << "\n";
    }
}