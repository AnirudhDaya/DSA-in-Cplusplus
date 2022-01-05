#include <bits/stdc++.h>
using namespace std;

int main()
{
int i,k=31;
   
  int A[]={2,4,7,11,14,16,20,21};  

        int low=0,high=7,t=1;
        while(low<high)
        {
            if(A[low]+A[high]==k)
            {t=0;
              
            }
            else
            if(A[low]+A[high]>k)
             high--;
             else
             {
                 low++;
             }
             
        }
        if(t==0)
        cout<<"present";
        cout<<"absent";
}