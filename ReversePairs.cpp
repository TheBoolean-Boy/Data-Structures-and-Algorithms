class Solution {
public:

void merge(vector<int> &arr, int low, int mid, int high, int& reversePairsCount) {
     ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int j = mid +1;
    for(int i = low; i <=mid; i++){
      while(j <=high && arr[i] > 2 *(long long)arr[j]){
        j++;
      }
      reversePairsCount += j - (mid + 1);
    }
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    // int cnt = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else { // left element is greater thsn right arr[left] > arr[right]
            temp.push_back(arr[right]);
            // cnt += (mid - left +1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    // return cnt;
}

void mergeSort(vector<int> &arr, int low, int high, int& reversePairsCount) {
     ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    // int cnt = 0;
    if (low == high) return;
    int mid = (low + high) / 2 ;
     mergeSort(arr, low, mid, reversePairsCount);  // left half
     mergeSort(arr, mid + 1, high, reversePairsCount); // right half
      merge(arr, low, mid, high, reversePairsCount);  // merging sorted halves

    // return cnt;
}
    int reversePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int reversePairsCount = 0;

        mergeSort(nums, 0, n-1, reversePairsCount);
        return reversePairsCount;

    }
};
