#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ll t; cin >> t;

    while(t--) {
        ll n, c = 0; cin >> n;
        string s; cin >> s;

//        if(n <= 2) {
//            cout <<
//        }

        bool f1 = false;
        for(int i = 0; i < n-2; i++)
            if(s[i] == s[i+2] && s[i] != s[i+1]) {
                s.erase(i+1, 1);
                f1 = true;
                break;
            }

        if(!f1)
            for(int i = 1; i < n-1; i++)
                if(s[i] != s[i+1] && s[i] != s[i-1]) {
                    s.erase(i, 1);
                    break;
                }

        if (!s.empty())
            c = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1])
                c++;
        }

        cout << c << "\n";
    }
}