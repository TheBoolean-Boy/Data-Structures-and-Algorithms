#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n ){
     for(int i =0; i < n ; i++){
        int mini = i;
        for (int j = i+1; j < n; j++){
            if(arr[mini] > arr[j]){
                mini =j;
            }
        }
        swap(arr[i], arr[mini]);
     }
}

int main(){
    int n;
    cin >> n;
     
    int arr[n];
    for(int i =0; i <n; i++){
        cin >> arr[i];
    }

    selection_sort(arr,n);

    for(int i =0; i <n; i++){
      cout << arr[i] << " ";
    }
    
   return 0;


}
