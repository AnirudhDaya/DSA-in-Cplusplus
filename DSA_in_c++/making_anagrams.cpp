#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
int i,j,flag=0;
int n=s1.size(),m=s2.size();

    if(n>m)
        swap(s1,s2);
        
n=s1.size();
m=s2.size();

int count =0;

    for(i=0;i<n;i++)
    {  flag=0;
        for(j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {   
                flag=1;
                s2[j]='1';
                break;
            }
        }

        if(flag==0)
            count++;
    }
    for(i=0;i<m;i++)
    {
        if(s2[i] != '1')
            count++;
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
