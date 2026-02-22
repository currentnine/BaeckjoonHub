#include <iostream>

using namespace std;

typedef long long ll;

ll a[1000003], n, temp;

int main() {
  cin >> n;
  temp = n;
  n = abs(n);
  a[0] = 0;
  a[1] = 1;
  for(int i = 2; i < n + 1; i++) a[i] = (a[i - 1] + a[i - 2])%1000000000;
  if(temp < 0) {
    if(n%2 == 1) {
      cout << 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  } else if(temp == 0) {
    cout << 0 << '\n';
  } else if(temp > 0) {
    cout << 1 << '\n';
  }
  cout << a[n] << '\n';
  return 0;
}