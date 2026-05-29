#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    vector<int> b(4), a(4), ans(3, 0);
    cin >> b[0] >> a[0] >> b[1] >> a[1] >> b[2] >> a[2] >> b[3] >> a[3];

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j <= i-1; j++) {
            if (a[i] >= b[i]) ans[j] += a[i]-b[i];
            else ans[j] += 
        }
    }

    for (int n : ans) cout << n << "\n";
}