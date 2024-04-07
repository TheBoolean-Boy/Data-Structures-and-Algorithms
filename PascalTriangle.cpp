class Solution {
private:
    vector<int>generateRow(int N){
        
      vector<int>temp;
      temp.push_back(1);
      long long ans = 1 ;
      for(int i = 1; i < N; i++){
         ans = ans * (N -i);
         ans = ans /i;
         temp.push_back(ans);
    }
    return temp;
}
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
