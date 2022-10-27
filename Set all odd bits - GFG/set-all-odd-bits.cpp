//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int setAllOddBits(long long int n) {
        // code here
        long long mask;
        if(__builtin_clzll(n)%2==0){
            mask=0x5555555555555555>>(__builtin_clzll(n));
        }
        else{
            mask = 0xAAAAAAAAAAAAAAAA>>(__builtin_clzll(n));
        }
        return mask | n;
    }
};
//8421
//1010
//

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.setAllOddBits(n) << endl;
    }
    return 0;
}

// } Driver Code Ends