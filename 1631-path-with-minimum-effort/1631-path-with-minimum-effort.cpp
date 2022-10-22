class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
       int rows = heights.size();
       int cols = heights[0].size();
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> minDiff(rows,vector<int>(cols,INT_MAX));
        minDiff[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            if(row==rows-1 and col==cols-1){
                return minDiff[row][col];
            }
            int diff = pq.top().first;
            pq.pop();
            //cout<<diff<<":"<<row<<","<<col<<"\n";
            for(vector<int> dir:dirs){
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if(newRow>=0 and newCol>=0 and newRow<rows and newCol<cols and minDiff[newRow][newCol]>max(diff,abs(heights[row][col] - heights[newRow][newCol]))){
                    
                    int newDiff = max(diff,abs(heights[row][col] - heights[newRow][newCol]));
                    pq.push({newDiff,{newRow,newCol}});
                    minDiff[newRow][newCol] = newDiff;
                }
            }
        }
        return -1;
    }
};