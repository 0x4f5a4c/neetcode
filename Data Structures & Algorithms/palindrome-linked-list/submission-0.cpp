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
    bool isPalindrome(ListNode* head) {
        // my intitail approach, by using extra space 
        vector<int> nums;
        ListNode *temp = head;
        while (temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0, j = nums.size()-1;
        while (i <= j) {
            if (nums[i] != nums[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // this is time consuming as well as space 
};