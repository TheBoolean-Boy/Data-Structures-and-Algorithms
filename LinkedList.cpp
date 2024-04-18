#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node * next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp; // equivalent to mover = mover -> next
    }
    return head;
}
int lengthOfLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        // cout << temp -> data << " ";
        temp = temp ->next;
        count++; 
    }
    return count;
}
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    // int count = 0;
    while(temp){
        // cout << temp -> data << " ";
        if(temp->data == val)return 1 ;
        temp = temp ->next;
        // count++; 
    }
    return 0;
}
int main(){
    vector<int>arr = { 2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    cout << checkIfPresent(head, 7);
    // cout << head->data << " "<< head->next ;
}
