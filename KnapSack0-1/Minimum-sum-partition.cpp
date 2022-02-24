//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int range = 0;
	    for(int i = 0;i < n; i++) 
	        range += arr[i];
	        
        int sum = range/2; //
        
        bool dp[n+1][sum+1]; // creating a dp of range half sum of the array's total sum
        //because the second subset sum can be found through range - 2*s1
        
        for(int i = 0; i < n+1; i++) 
            dp[i][0] = true; // all subsets true when sum is 0;
            
        for(int j = 0; j < sum+1; j++)
            dp[0][j] = false; // when subset is empty then any sum is false
            
        dp[0][0] = true; // 0 subset and 0 sum always true;
        
        for(int i = 1; i < n+1; i++) {
            
            for(int j = 1; j < sum+1; j++) {
                
                if(arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                
            }
        }
        vector<int> subset;
        
        for(int j = 0; j < sum+1; j++) {
            // considering only those sum that can be made throug the array given
            if(dp[n][j]) {
                subset.push_back(j); 
            }
        }
        
        int mn = INT_MAX;
        
        for(int i = 0; i < subset.size(); i++) {
            // finding minimum by getting the s1 we caan easily get s2 as below
            mn = min(mn, range - 2*subset[i]);
        }
        
        return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
