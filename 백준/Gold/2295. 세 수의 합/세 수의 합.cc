#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[1005];
vector<int> two;

int main(){

    cin>>n;
    for(int i = 0; i<n;i++) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i< n; i++){
        for(int j = i; j <n; j++) two.push_back(a[i]+ a[j]);
    }
    sort(two.begin(), two.end());
    for(int i = n-1; i>0; i--){
        for(int j =0 ; j<n; j++){
            if(binary_search(two.begin(), two.end(), a[i] - a[j])){ 
                cout << a[i];
                return 0;
            }
        }
    }

}