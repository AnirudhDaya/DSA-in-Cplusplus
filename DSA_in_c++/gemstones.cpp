#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

int gemstones(vector<string> arr) {
int i,j,count=0,flag=0;

int n=arr[0].size();
vector<int> a(26,0);
    for(i=0;i<n;i++)
    {    j=1;
        flag=0;
        int m=arr.size();

            for(j=1;j<m;j++)
            {    
                flag=0;
               if(std::find(arr[j].begin(), arr[j].end(), arr[0][i]) != arr[j].end())
               {    flag=1;
                   int pos= find(arr[j].begin(),arr[j].end(), arr[0][i]) - arr[j].begin();
                   arr[j][pos]= '0';
               }
               else 
                break;
            }

        if(flag==1)
            count++;

    }    
   // cout<<count<<endl;   
return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
