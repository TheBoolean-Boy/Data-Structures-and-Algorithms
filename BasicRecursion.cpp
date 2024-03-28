
#include<bits/stdc++.h>
using namespace std;

vector<int> printNos(int x) {
    if(x==0){
        cout << " This was executed " << endl;
      return {};

    }
    // cout << " The value of X is " << x << endl;
    vector<int>res ;
    // cout <<res[0] << " What is actually changing " << endl;
    // cout << " The value of X is " << x << endl;
    res.push_back(x);
     printNos(x-1);
    // cout << " Now retured" << endl;
    // for(int i = 0; i < res.size(); i++){
    //     cout << res[i] << " " ;
    // }
    // cout << endl;
    return res;
}
int main(){
    vector<int> v(printNos(5));
    // v=printNos(5);
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout << v[i] << " ";
    }
    
}
