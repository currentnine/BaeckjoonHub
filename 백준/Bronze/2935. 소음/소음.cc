#include <iostream>
using namespace std;

int main(){
    string A, B;
    char op;
    
    cin >> A >> op >> B;
    
    int lenA = A.length(), lenB = B.length();
   
    string maxnum = A>B? A : B;
    int maxlen = lenA > lenB ? lenA : lenB;
    int minlen = lenA > lenB ? lenB : lenA;
    
    if(op == '+'){
        if(A==B){
            maxnum[0] = '2';
        }
        else{
            maxnum[maxlen-minlen] = '1';
        }
        cout << maxnum;
    }
    else{
        cout << '1';
        for(int i=0; i<lenA+lenB-2 ;i++)
            cout << '0';
    }
   
    return 0;
}