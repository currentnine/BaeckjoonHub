#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
 
using namespace std;
 
int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for (int j = 0; j < 3; j++) {
            cin >> a;
            vec.push_back(a);
        }
 
        // 피타고라스 정리를 사용하기 위해 오름차순 정렬
        sort(vec.begin(), vec.end());
 
        cout << "Scenario #" << i + 1 << ":\n";
        
        // 코드량을 조금 줄이기 위해 math.h의 pow() 메소드 사용 (제곱)
        if (pow(vec[0], 2) + pow(vec[1], 2) == pow(vec[2], 2)) {
            cout << "yes\n\n";
        }
        else {
            cout << "no\n\n";
        }
    }
 
    return 0;
}