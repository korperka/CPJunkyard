#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int ans = 0;
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++) {
            string p = s.substr(0, i+1);
            if (p == string(p.rbegin(), p.rend()) && ans < p.size()) ans = p.size();
        }

        cout << ans << "\n";
    }
}