#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */
string time(int hr)
{    string s;
    switch(hr)
    {
        case 1: s="one";
                    break;
                    
        case 2:   s="two";
                    break;   
 
        case 3:  s="three";
                    break; 

        case 4: s="four";
                    break;

        case 5: s="five";
                    break;

        case 6: s="six";
                    break;

        case 7: s="seven";
                    break;

        case 8: s="eight";
                    break;

        case 9: s="nine";
                    break;    
    
        case 10: s="ten";
                    break; 

        case 11: s="eleven";
                    break;

        case 12: s="twelve";
                    break;   
  
        case 13: s="thirteen";
                    break;
                    
        case 14: s="fourteen";
                    break;
                    
        case 15: s="fifteen";
                    break;
                    
        case 16: s="sixteen";
                    break;
                    
        case 17: s="seventeen";
                    break;
                    
        case 18: s="eighteen";
                    break;                                                                       
        case 19: s="nineteen";
                    break;               
        
        case 20: s="twenty";
                    break;
                    
        case 21: s="twenty one";
                    break;
                    
        case 22: s="twenty two";
                    break;
                    
        case 23: s="twenty three";
                    break;
                    
        case 24: s="twenty four";
                    break;
                    
        case 25: s="twenty five";
                    break;
                    
        case 26: s="twenty six";
                    break;
                    
        case 27: s="twenty seven";
                    break;
                    
        case 28: s="twenty eight";
                    break;
                    
        case 29: s="twenty nine";
                    break;
    }
    return s;
}
string timeInWords(int h, int m)
 {

 string s="NULL";
        if(m==0)
        {
            s=time(h);
            s+=" o' clock";
              return s;
        }
        
         if(m==1)
        {
            s=time(m);
            s+=" minute past ";
            s+=time(h);
              return s;
        }
        
        if(m<30 && m!=15 && m!=1)
        {
            s=time(m);
            s+=" minutes past ";
            s+=time(h);
              return s;
        }
        
        if(m==30)
        {
            s="half past ";
            s+=time(h);
              return s;
        }
        
        if(m>30 && m!=45 && h!=12)
        {
            s=time(60-m);
            s+=" minutes to ";
            h++;
            s+=time(h);
              return s;
        }
        
        if(m>30 && m!=45 && h==12)
        {
            s=time(60-m);
            s+=" minutes to one";  
              return s;          
        }
        
        if(m==45 && h!=12)
        {
            s="quarter to ";
            s+=time(h+1);
              return s;
        }
        
        if(m==45 && h==12)
        {
            s="quarter to one ";
              return s;
        }
        
        if(m==15)
        {
            s="quarter past ";
            s+=time(h);
              return s;
        }
      return s ;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
