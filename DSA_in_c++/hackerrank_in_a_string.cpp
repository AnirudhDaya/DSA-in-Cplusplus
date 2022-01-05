#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'hackerrankInString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string hackerrankInString(string s) {
int h,a,c,k,e,r,r1,a1,n,k1;
h=s.find('h');
    if(h==-1)
        return "NO";
a=s.find('a',h);
    if(a==-1)
        return "NO";
c=s.find('c',a+1);
    if(c==-1)
        return "NO";
k=s.find('k',c);
    if(k==-1)
        return "NO";
//s[k]='2';
e=s.find('e',k);
    if(e==-1)
        return "NO";
r=s.find('r',e);
    if(r==-1)
        return "NO";
//s[r]='1';
r1=s.find('r',r+1);
    if(r1==-1)
        return "NO";
a1=s.find('a',r1);
    if(a1==-1)
        return "NO";
n=s.find('n',a1);
    if(n==-1)
        return "NO";
k1=s.find('k',n);
    if(k1==-1)
        return "NO";
//cout<<h<<" "<<a<<" "<<c<<" "<<k<<" "<<e<<" "<<r<<" "<<r1<<" "<<a1<<" "<<n<<" "<<k1<<endl;

/*if(h<a && a<c && c<k && k<e && e<r && r<r1 && r1<a1 && a1<<n && n<k)
{
    
}*/
    return "YES";}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

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
