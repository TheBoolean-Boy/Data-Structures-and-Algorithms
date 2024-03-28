#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    cout <<" enter the elements of the array " << endl;
    int arr[n];
    map<int ,int > mpp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mpp[i]++;
    }

    for(auto i: mpp){
        cout << i.first << " -->" << i.second << endl;
    }
     
     int q ;
     cin >> q;
     while(q--){
        int k;
        cin >> k;
        cout << mpp[k] << " times appeared " << endl;
     }
    // cout << mpp[1]<< " times";
    
    }
