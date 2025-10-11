#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1'000'005], list[1'000'005];

int binary_search(int left, int right, int target){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(list[mid] < target) left = mid + 1;
        else right = mid;
    }

    return right;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> arr[i];
    int a = 0;
    list[a] = arr[0];
    for(int i = 0 ; i < n; i++){
        if(list[a] < arr[i]){
            list[a + 1] = arr[i]; a++;
        }
        else{
            int idx = binary_search(0, a, arr[i]);
            list[idx] = arr[i];
        }
    }
    cout << a + 1;
}

