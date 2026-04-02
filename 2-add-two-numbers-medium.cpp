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
        bool carry = false;
        ListNode* last = nullptr;
        ListNode* first = l1;

        while (true) {
            int result = 0;
            
            if (l1 && l2)
                result = l1->val + l2->val;
            else if (l1)
                result = l1->val;
            else if (l2)
                result = l2->val;
            else {
                if (carry) {
                    ListNode* finalnode = new ListNode(1);
                    last->next = finalnode;
                }
                
                break;
            }

            if (carry) {
                ++result;
                carry = false;
            }

            if (result >= 10) {
                carry = true;
                result %= 10;
            }

            if (l1)
                l1->val = result;
            else {
                l1 = new ListNode(result);
                last->next = l1;
            }

            last = l1;            
            l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return first;
    }
};