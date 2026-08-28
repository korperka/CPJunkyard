#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<pair<int, int>, int> m;

    int n; cin >> n;
    for (int i = 1; i < n+1; i++) {
        m[{to_string(i)[0] - '0', i%10}]++;
    }

    ll c = 0;
    for (int i = 1; i < n+1; i++) {
        pair<int, int> p = {i%10, to_string(i)[0] - '0'};

        c += m[p];
    }

    cout << c;
}