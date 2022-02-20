//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// here i have used memoziztion technique to reduce time complexity

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// now creating a global array to add memorisation to our code 


class Solution
{
    public:
    int dp[1005][1005];
    int knapSackMemo(int W, int wt[], int val[], int n){
        
        // base case 
       //if the we reached the end of the array with 0 elements in it
       //or thae capacity became 0;
       if(n == 0 || W <= 0) {
           return 0;
       }
       
       if(dp[n][W] != -1)
            return dp[n][W];
       
       // now choices to whether to take the next element into consideration or not
       // and also if the element weight is less than equal to the capacity
       // here two choices are being made whether this elegible thing should be taken intosoncideration or not
       if(wt[n-1] <= W) 
            return dp[n][W] = max( (val[n-1] + knapSackMemo(W-wt[n-1], wt, val, n-1)), knapSackMemo(W, wt, val, n-1));
            
       else if(wt[n-1] > W) 
            return dp[n][W] = knapSackMemo(W, wt, val, n-1);
    }
        
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp, -1, sizeof(dp)); 
        return knapSackMemo(W, wt, val, n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
