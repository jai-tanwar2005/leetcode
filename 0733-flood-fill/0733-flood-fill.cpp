class Solution {
private:

    void dfs(int row, int col,
             vector<vector<int>>& image,
             vector<vector<int>>& ans,
             int newcolor,
             int ini,
             int delRow[],
             int delCol[]) {

        ans[row][col] = newcolor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == ini &&
                ans[nrow][ncol] != newcolor) {

                dfs(nrow, ncol, image, ans,
                    newcolor, ini, delRow, delCol);
            }
        }
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int newcolor) {

        int ini = image[sr][sc];

        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        if (ini == newcolor) {
            return ans;
        }

        dfs(sr, sc, image, ans,
            newcolor, ini, delRow, delCol);

        return ans;
    }
};