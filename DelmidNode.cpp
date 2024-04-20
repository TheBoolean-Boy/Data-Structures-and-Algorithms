/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //  ios_base::sync_with_stdio(false);
        // cin.tie(NULL);

    if(head == nullptr || head->next == nullptr)return nullptr;

    ListNode* fast = head; ListNode* slow = head;
    fast = fast->next->next;

    while(fast != NULL && fast->next != nullptr){
        slow = slow ->next;
        fast = fast->next->next;
    }

    ListNode* middleNode = slow ->next;
    slow->next = slow ->next->next;

    delete middleNode;
    return head;
        
    }
};
