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

/**
 * better approach with constant space and O(N) time complexity
 */

class Solution {
   public:
    ListNode* _reverse_list(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* new_head = _reverse_list(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return new_head;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        // finding the middle element
        while (fast->next && fast->next->next) {  // O(N/2)
            slow = slow->next;
            fast = fast->next->next;
        }

        // now reverse the second half and get the new head after reversing it
        ListNode* new_head = _reverse_list(slow->next);  // O(N/2)
        ListNode *first = head, *second = new_head;

        while (second) {  // O(N/2)
            if (first->val != second->val) {
                _reverse_list(new_head);  // O(N/2)
                return false;
            }

            first = first->next;
            second = second->next;
        }

        _reverse_list(new_head);
        return true;
    }
};