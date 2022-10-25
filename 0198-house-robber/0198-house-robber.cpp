class Solution {
public:
    int rob(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        long long prev = 0;
        long long prevprev = 0;
        while(left<=right){
            long long newValue = max(prev,arr[left]+prevprev);
            prevprev = prev;
            prev = newValue;
            left++;
        }
        return prev;
    }
};
//10
//6 4 7  8  4  7  1  7  3  6
//6 6 13 14 17 21 18 28 21 34