#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int price;
        cin >> price;
 
        int option;
        cin >> option;
 
        for (int j = 0; j < option; j++) {
            int q, p;
            cin >> q >> p;
 
            price += q * p;
        }
 
        cout << price << "\n";
    }
 
    return 0;
}