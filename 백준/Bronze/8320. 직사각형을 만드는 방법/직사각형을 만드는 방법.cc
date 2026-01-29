#include <iostream>
#include <cmath>
using namespace std;
int d[10001];
//정사각형의 개수 : n이라면
//n의 약수들의 곱으로 표현이 가능하다. 이는 직사각형을 몇 곱하기 몇으로 표현한다는 말이다.
 
int cnt(int n)
{
    int count = 0;
    //직사각형을 만들 때 중복을 피해야 하므로 루트 n까지 돈다.
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (!(n % i))
        {
            count++;
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    //d : 만들 수 있는 직사각형의 개수
    d[1] = 1;
    d[2] = 2;
    //정사각형이 한 개가 추가될 때 마다 앞으로 만들 수 있는 직사각형의 개수를 계속 더해주면 된다.
    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i-1] + cnt(i);
    }
    cout << d[n];
}
