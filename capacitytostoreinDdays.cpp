class Solution {
public:
    int shipPossible(vector<int>&weights, int capacity){
        int load = 0, dcount = 1; // taking day count 1 means no matter how large the capacity is it will take atleast 1 day to ship
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > capacity){
                dcount ++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        // if(dcount <= days)return true;
        // else return false;
        return dcount;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int sum = 0, maxi = INT_MIN;
        for(int i = 0; i < weights.size(); i++){
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }
        int low = maxi, high = sum;

        while(low <= high){
            int mid = low + (high - low)/2;
            int req = shipPossible(weights, mid);
            if(req <= days){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};
