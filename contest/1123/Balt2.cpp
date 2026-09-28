#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        unordered_map<ll, ll> cnt;
        multiset<ll, greater<>> p, q;

        ll mxc = 0; // Ищем глобальный максимум частоты
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            p.insert(a);
            cnt[a]++;
            mxc = max(mxc, cnt[a]); // Теперь mxc равен максимальной частоте в массиве
        }

        // Очищаем cnt, чтобы использовать его для подсчета при выводе
        cnt.clear();

        for (const ll& c : p) {
            if (cnt[c] >= mxc) {
                q.insert(c);
                continue;
            }

            cout << c << " ";
            cnt[c]++;
        }

        for (const ll& c : q) cout << c << " ";
        cout << "\n";
    }
}
