class Solution {
public:

    bool is_ok(vector<vector<int>>& matrix, int target, int mid){
        int m = matrix.size();
        int n = matrix[0].size();
        int row = mid / n;
        int col = mid % n;

        return (matrix[row][col] < target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = n * m - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(is_ok(matrix, target, mid)) l = mid + 1;
            else r = mid;
        }

        int row = l / n;
        int col = l % n;
       return (matrix[row][col] == target);
    }
};
