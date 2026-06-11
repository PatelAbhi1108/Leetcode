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
    void reorderList(ListNode* head) {
        vector<int> listVal;
        ListNode* temp = head;
        
        while(temp != NULL){
            listVal.push_back(temp -> val);
            temp = temp ->next;
        }

        int left = 0;
        int right = listVal.size()-1;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while(left <= right){
            if (left == right) {
                cur->next = new ListNode(listVal[left]);
                cur = cur->next;
            } else {
                cur->next = new ListNode(listVal[left]);
                cur = cur->next;
                cur->next = new ListNode(listVal[right]);
                cur = cur->next;
            }
            left++;
            right--;
        } 
        temp = head;
        cur = dummy->next;
        while (temp != NULL) {
            temp->val = cur->val;
            temp = temp->next;
            cur = cur->next;
        }
        
        
    }
};
