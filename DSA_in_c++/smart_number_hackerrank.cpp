#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_smart_number(int num) {
    int val = (int) sqrt(num);
    cout<<(int) sqrt(num)<<'\n';
    cout<<val<<'\n';
    if(num ==val*val)
        return true;
    return false;
}



int main()
{
    int s;
        cout<<"\n Enter string:\n";
        cin>>s;

        cout<<'\n'<<is_smart_number(s)<<'\n';
}
