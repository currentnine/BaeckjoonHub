#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

string s1, s2;
vector <vector<int>> dp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    cin >> s1 >> s2;

    s1 = "0" + s1;
    s2 = "0" + s2;

    int n = s1.size(), m = s2.size();
    dp.resize(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s2[i] == s1[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[m - 1][n - 1] << "\n";

    string lcs = "";
    int i = m - 1, j = n - 1;
    while (i > 0 && j > 0) {
        if (s2[i] == s1[j]) {
            lcs += s2[i]; 
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    if (!lcs.empty()) cout << lcs << "\n";
}