#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *deleteHead(Node *head)
{
    if (head == NULL || head == nullptr)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    free(prev);
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL || head == nullptr)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    temp->back = nullptr;
    prev->next = nullptr;
    return head;
}
Node *removeK(Node *head, int k)
{
    if (head == nullptr)
    {
        return NULL;
    }
    Node *temp = head;
    int counter = 0;
    while (temp != nullptr)
    {
        counter++;
        if (counter == k)
            break;
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* prev = temp->back;
    if(front ==nullptr && prev == nullptr){
        delete temp;
        return NULL;
    }
    else if(prev == nullptr){
        return deleteHead(head);
        // return head;
    }
    else if(front == nullptr){
        return deleteTail(head);
        // return head;
    }
    else{
        prev->next = temp->next;
        front->back = temp->back;
        temp ->back = nullptr;
        temp ->next = nullptr;
        delete temp;
        return head;
    }
    return head;
}
void deleteNode(Node* temp){
    Node* prev = temp ->back;
    Node* front = temp ->next;

    //given node is the last node
    if(front == nullptr){
        prev->next = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
}
Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode;
    return newNode;
}
Node* insertBeforeTail(Node* head, int val){
    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }
    Node* prev = tail->back;
    if( prev == nullptr){
        return insertBeforeHead(head, val);
    }
    Node* newNode = new Node(val, tail, prev);

    tail->back = newNode;
    prev->next = newNode;

    return head;
}
Node* insertBeforeKthElement(Node* head, int val, int k){

    Node* temp = head;
    int counter = 0;
    while(temp != nullptr){
        counter++;
        if(counter == k)break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    if(prev == nullptr || k==1){
        return insertBeforeHead(head, val);
    }
    Node* newNode = new Node(val, temp, prev);
    temp->back = newNode;
    prev->next = newNode;
    
    return head;
}
void insertBeforeNode(Node* node, int val){
    Node* prev = node -> back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back= newNode;
}
int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2DLL(arr);
    insertBeforeNode(head->next, 9);
    print(head);
    return 0;
}
