#include <bits/stdc++.h>
using namespace std;
 
// A function to implement bubble sort
void bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
 
// Function to print an array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    
     int n,arr[10];
    cout<<"Enter number of elements ";
    cin>>n;
    cout<<"\nEnter the elements:\n";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
     bubblesort(arr,n);
    cout<<"\nSorted array\n";
    for(int i = 0; i < n; i++)
      cout<<arr[i]<<"\t";
    return 0;
}
