class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        // Step 1: Copy values into vector
        vector<int> listVal;
        ListNode* temp = head;
        while (temp != nullptr) {
            listVal.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Use two pointers to rebuild ANS list
        int left = 0, right = listVal.size() - 1;
        ListNode* dummy = new ListNode(0);  // new head
        ListNode* cur = dummy;

        while (left <= right) {
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

        // Step 3: copy back into original list (optional if problem demands in-place)
        temp = head;
        cur = dummy->next;
        while (temp != nullptr) {
            temp->val = cur->val;
            temp = temp->next;
            cur = cur->next;
        }
    }
};
