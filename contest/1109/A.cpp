#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while (t--) {
        int n, c = 0, max_c = 0; cin >>n;
        string s; cin>>s;

        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                c++;
                max_c = max(max_c, c);
            }
            else {
                c = 0;
            }
        }

        cout<<(max_c + 1)/2<<endl;
    }
}