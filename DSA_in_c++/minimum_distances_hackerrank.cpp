#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumDistances' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
int pos(vector<int> a,int key,int n)
{
    int i;
      for(i=0;i<n;i++)
      {
          if(a[i]==key)
            return i;
      }
    return 0;
}
int minimumDistances(vector<int> a) {
int n=a.size();
vector<int>dupe(n);
    dupe=a;
    int mini=INT_MAX;
    int i=0,diff=0;
    int p,q,flag=0;

      sort(dupe.begin(),dupe.end());
                for(i=0;i<(n-1);i++)
                {
                    if(dupe[i]==dupe[i+1])
                    {   flag=1;
                        p=pos(a,dupe[i],n);
                        a[p]=-1;
                        q=pos(a,dupe[i],n);
                        a[q]=-1;
                        
                        diff=abs(p-q);
                        mini=min(mini,diff);
                        i++;
                        if(mini==1)
                         return 1;
                    }
                }
 if(flag==1)
    return mini;
else
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
