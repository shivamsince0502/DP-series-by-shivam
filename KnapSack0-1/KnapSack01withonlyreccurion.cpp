// knapsack 0/1 quesiton without dp or memoziztion

//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // base case 
       //if the we reached the end of the array with 0 elements in it
       //or thae capacity became 0;
       if(n == 0 || W <= 0) {
           return 0;
       }
       
       // now choices to whether to take the next element into consideration or not
       // and also if the element weight is less than equal to the capacity
       if(wt[n-1] <= W) {// here two choices are being made whether this elegible thing should be taken intosoncideration or not
            return max( (val[n-1] + knapSack(W-wt[n-1], wt, val, n-1)), knapSack(W, wt, val, n-1));   
       }
       else if(wt[n-1] > W) // here it is not taken into consideration
            return knapSack(W, wt, val, n-1);
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
