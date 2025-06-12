#include<iostream>
#include<algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,n, m;
    cin>>N;
    vector<int> v;

    for(int i=0;i<N;i++){
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        cout<<upper_bound(v.begin(),v.end(), n) - lower_bound(v.begin(),v.end(), n) << " "; 
    } 

}