int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    unordered_map<int, int>sumMap;
    sumMap[0] = 1;
    int preSum =0, count = 0;
    for(int i = 0 ; i < arr.size(); i++){
        preSum += arr[i];
        int remainder = preSum - k;
        count += sumMap[remainder];
        sumMap[preSum]++;
    }
    return count;
}
