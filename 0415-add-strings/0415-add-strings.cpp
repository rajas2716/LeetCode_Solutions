class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> sum(max(l1,l2) + 1,0);
        int i = l1-1;
        int j = l2-1;
        int ptr = max(l1,l2);
        while(i>=0 || j>=0){
            int digit1 = 0;
            int digit2 = 0;
            if(i>=0)
            digit1 += num1[i] - '0';
            if(j>=0)
            digit2 += num2[j] - '0';
            
            int add = digit1 + digit2;
            sum[ptr] += add;
            sum[ptr-1] += sum[ptr]/10;
            sum[ptr] %= 10;
            i--;
            j--;
            ptr--;
        }
        string result;
        i = 0;
        while(i<sum.size() and sum[i]==0 ){
            i++;
        }
        if(i==sum.size()){
            return "0";
        }
        while(i<sum.size()){
            result += sum[i] + '0';
            i++;
        }
        return result;
    }
};
/*
123
011
*/