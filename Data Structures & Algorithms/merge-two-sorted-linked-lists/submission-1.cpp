// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
// #include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // the base case is 
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode dummy(-1);
        ListNode *tmp = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }
        if (!list1) tmp->next = list2;
        if (!list2) tmp->next = list1;
        return dummy.next;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();