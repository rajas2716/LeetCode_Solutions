class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> precomputed(rows,vector<int>(cols,0));
        for(int row = 0; row < rows ; row++){
            int colSum = 0;
            for(int col = 0; col < cols ; col++){
                colSum += matrix[row][col];
                precomputed[row][col] = colSum + (row-1>=0?precomputed[row-1][col]:0);
                //cout<<precomputed[row][col]<<" ";
            }
            //cout<<"\n";
        }
        int result = 0;
        
        for(int y1=0;y1<rows;y1++){
        for(int y2 = y1;y2<rows;y2++){
            unordered_map<int,int> mp;
            int col = 0;
            mp[0]++;
            while(col<cols){
                int sum = precomputed[y2][col] - (y1-1>=0?precomputed[y1-1][col]:0);
                if(mp.count(sum-target)>0){
                    result+= mp[sum-target];
                }
                mp[sum]++;
                col++;
            }
        }
    }
        return result;
    }
};