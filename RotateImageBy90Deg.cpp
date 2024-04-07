class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = mat.size();
//   vector<vector<int>> ans(n, vector<int>(n));
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       ans[j][n - 1 - i] = mat[i][j];
//     }
//   }
//   // return ans;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       mat[i][j] = ans[i][j];
//     }
//   }
//     }
    

    //Step 1 find the transpose of the matrix
    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    //Step 2 find the reverse of each row
    for (int i = 0; i < n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
    }

};
