#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
int count_lower=0,count_upper=0,count_num=0,count_sp=0, total_count=0;

    for(int i=0;i<n;i++)
    {
        if(password[i]>='a' && password[i]<='z')
            count_lower++;
        
        else 
        
        if(password[i]>='A' && password[i]<='Z')
            count_upper++;
            
        else 
        
        if(isdigit(password[i])) 
            count_num++;
            
        else 
        
        count_sp++;   
    }
    
    if(count_sp==0)
        {total_count++;
            n++;
        }
        
    if(count_lower==0)
        { total_count++;
            n++;
        }
    if(count_num==0)
        { total_count++;
            n++;
        }       
    if(count_upper==0)
        { total_count++;
            n++;
        }       
     if(n<6)   
            total_count+=6-n;
            
    return total_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
