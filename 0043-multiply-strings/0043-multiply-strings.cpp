class Solution {
public:
    vector<int> digits;
    void func(){
        int index = 0;
        int carry = 0;
        while(carry>0 || index<digits.size()){
            //cout<<digits[index]<<" ";
            carry += digits[index];
            digits[index] = carry%10;
            index++;
            if(carry>0 and index==digits.size()){
                digits.push_back(0);
            }
            carry/=10;
        }
        //cout<<"\n";
    }
    string multiply(string num1, string num2) {
        int len2 = num2.length();
        int len1 = num1.length();
        if(num1=="0" || num2 =="0"){
            return "0";
        }
        if(len2>len1){
            swap(num1,num2);
            swap(len2,len1);
        }
        for(int i = len2 - 1;i>=0;i--){
            for(int j = len1 - 1;j>=0;j--){
                int newIndex = (len2-1 - (i)) + (len1-1 -(j));
                int digit1 = num1[j] - '0';
                int digit2 = num2[i] - '0';
                int multiplied = digit1 * digit2;
                while(newIndex>=digits.size()){
                    digits.push_back(0);
                }
                digits[newIndex] += multiplied;
            }
            func();
        }
        string result;
        for(int i=digits.size() - 2;i>=0;i--){
            result += digits[i] + '0';
        }
        return result;
    }
};
//2 9 9
//  3 9