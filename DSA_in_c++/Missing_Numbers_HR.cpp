#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */


void outputint(vector<int> s,int n)
{
      for(int i=0;i<n;i++)
      cout<<s[i]<<'\n';
}

void outputstring(vector<string> s,int n)
{
      for(int i=0;i<n;i++)
      cout<<s[i]<<'\n';
}

/*long posint(vector<int>s,int key,n)
{
    long i;
                for(i=0;i<n;i++)
                {
                    if(s[i]==key)
                    return i;
                }
}
*/
long posstring(vector<string>s,string key,n)
{
    long i;
                for(i=0;i<n;i++)
                {
                    if(s[i]==key)
                    return i;
                }
}


vector<string> maximum(vector<string> s,int n)
{    int i=0;
    
    for(i=0;i<n;i++)
    {
        if()
    }
}

void bigSorting(vector<string> unsorted) {

long int n=unsorted.size();
vector<int> dupe(n);
   long int i;
        vector<string> ans(n);

        for(i=n-1;i>=0;i--)
        {
            ans[i]=maximum(dupe,n);
            dupe[posstring(dupe,ans[i],n)]=-1;
        }
     outputstring(ans,n);
}

int main()
{
    vector<string> unsorted(6);
    unsorted={"31415926535897932384626433832795","1","3","10","3","5"};


        bigSorting(unsorted);
}