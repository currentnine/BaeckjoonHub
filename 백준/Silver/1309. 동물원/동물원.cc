#include <iostream>
int D[100001]={1,3};
using namespace std;
int main(){
    int N;
    cin>>N;
    for(int i=2;i<=N;i++)
        D[i]=(D[i-1]*2+D[i-2])%9901;
    cout<<D[N];
}