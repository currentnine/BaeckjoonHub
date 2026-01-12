#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans;
    cin >> n;
    while (n--) {
        cin >> k;
        ans = 1;
        for (int i = 1; i < k; i++)
            ans = ans * 2 + 1;
        cout << ans << '\n';
    }
}
