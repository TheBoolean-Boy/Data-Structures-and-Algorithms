#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &a, int n) {
    // Write your code here.
    vector<int> ans;
    // int n = a.size();

    int maxi = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(a[i] > maxi){
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
