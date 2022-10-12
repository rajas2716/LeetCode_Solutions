//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(int start,int mid,int end,long long arr[]){
        int ptr1 = start;
        int ptr2 = mid + 1;
        long long int countInv = 0;
        vector<long long int> merged;
        while(ptr1<=mid || ptr2<=end){
            if(ptr1>mid){
                merged.push_back(arr[ptr2]);
                ptr2++;
            }
            else if(ptr2>end){
                merged.push_back(arr[ptr1]);
                ptr1++;
            }
            else if(arr[ptr1]<=arr[ptr2]){
                merged.push_back(arr[ptr1]);
                ptr1++;
            }
            else{
                int elements = mid - ptr1 + 1;
                countInv += elements;
                merged.push_back(arr[ptr2]);
                ptr2++;
            }
        }
        
        for(int i=0;i<merged.size();i++){
            arr[i+start] = merged[i];
            //cout<<arr[i+start]<<" ";
        }
        // cout<<":";
        // cout<<countInv<<"\n";
        return countInv;
    }
    long long int mergeSort(int start,long long arr[],int end){
        if(start>=end){
            return 0;
        }
        int mid = start + (end-start)/2;
        long long int c1 = mergeSort(start,arr,mid);
        long long int c2 = mergeSort(mid+1,arr,end);
        return c1 + c2 + merge(start,mid,end,arr);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(0,arr,N-1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends