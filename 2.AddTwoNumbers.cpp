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
        int carry = 0, sum = 0;
        ListNode* l3 = NULL;
        ListNode** curr = &l3;

        while(l1!=nullptr || l2!=nullptr){
            //Get values from both lists
            int x = (l1 != nullptr) ? l1->val:0;
            int y = (l2 != nullptr) ? l2->val:0;
            //Sum and add the carry if there was one from the last iteration
            sum = x + y + carry;
            //Calculate the value to carry over to the next iteration
            carry = sum / 10;
            //Add the digit to the new list
            (*curr) = new ListNode(sum % 10);
            //Move the head to the next item in the list
            curr = &((*curr)->next);
            //Check to see if there items in the other lists before moving their heads
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        //Add the final carry digit if there is one
        if (carry > 0){
            (*curr) = new ListNode(carry);
        }
        return l3;
    }
};
