#include <iostream>
using namespace std;
 
int main(){
    int num;
    cin >> num;
 
    if(num == 1){
        for(int i=2; i<9; i++){
            cin >> num;
            if(i != num){
                cout << "mixed";
                break;
            }
            if(num == 8) cout << "ascending";
        }
    } else if(num == 8){
        for(int i=7; i>0; i--){
            cin >> num;
            if(i != num){
                cout << "mixed";
                break;
            }
            if(num == 1) cout << "descending";
        }
    } else cout << "mixed";
    return 0;
}
