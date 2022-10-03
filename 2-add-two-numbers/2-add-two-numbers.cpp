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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode addition = ListNode(0);
        ListNode * current = &addition;
        int digit = 0;
        
        while (l1 != nullptr || l2 != nullptr || digit != 0) {
            if (l1 != nullptr) {
                digit += l1->val;
            }
            
            if (l2 != nullptr) {
                digit += l2->val;
            } 
            
            current->next = new ListNode(digit % 10);
            digit /= 10;
            current = current->next;
            
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        
        return addition.next;
    }
};