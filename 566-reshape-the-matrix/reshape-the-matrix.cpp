class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size();
        int n = mat[0].size();

        // Total number of elements must be same
        if (m * n != r * c)
            return mat;

        vector<vector<int>> ans(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            // Original matrix position
            int oldRow = i / n;
            int oldCol = i % n;

            // New matrix position
            int newRow = i / c;
            int newCol = i % c;

            ans[newRow][newCol] = mat[oldRow][oldCol];
        }

        return ans;
    }
};