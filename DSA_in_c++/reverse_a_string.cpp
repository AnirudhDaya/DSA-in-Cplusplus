#include <bits/stdc++.h>

using namespace std;

void stringrev(string str)

{  if(str.length()==0)

return ;

string ros= str.substr(1);

stringrev(ros);

cout<<str[0];

}

int main()

{

stringrev("binod");

}
