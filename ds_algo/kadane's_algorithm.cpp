#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
   // unordered_set<int> s;
    int max=0;
    
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
     int i,current=0;
     for(i=0;i<n;i++){
         current+= arr[i];
         
         if(current>max)
         max=current;
         
         if(current<0)
         current=0;
     }
        // Your code here
       return max; 
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends