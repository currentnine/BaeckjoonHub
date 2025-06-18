#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;


    set<string> people;

    for(int i=0;i<n;i++) 
    {
        string name, action;
        cin >> name >> action;
        
        if(action == "enter") people.insert(name);
        else if (action == "leave") people.erase(name);
    }
    for(auto it = people.rbegin(); it!= people.rend();it++) cout << *it << "\n";
}