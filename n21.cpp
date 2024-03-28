#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    if(n < i){
        return;
    }
    cout << n << " ";
    print(i, n-1);

}
int main(){
    print(1,3);
}