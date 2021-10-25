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
    void append(int val, ListNode* &head){
        ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = NULL;
        if(!head){
            head = newNode;
        }else{
            ListNode *curr = head;        
            while(curr->next){            
                curr = curr->next;
            }        
            curr->next = newNode;
        }
    }
    
    void split(ListNode* head, ListNode* &a, ListNode* &b){
        //Get the size of the stack
        int stackLength = 0;
        ListNode *curr = head;
        while(curr){
            stackLength++;
            curr = curr->next;
        }
        //Split the stack
        curr = head;
        int midPoint = stackLength / 2;
        //Insert values for stack a
        for(int i=0; i<midPoint; i++){
            append(curr->val, a);
            curr = curr->next;
        }
        //Insert values for stack b
        for(int i=midPoint; i<stackLength; i++){
            append(curr->val, b);
            curr = curr->next;
        }
    }

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode *merged = NULL;
        //Find where b is less than a
        ListNode *curr_a = a, *curr_b = b;
        while(curr_a && curr_b){
            if(curr_a->val < curr_b->val){
                append(curr_a->val, merged);
                curr_a = curr_a->next;
            }else{
                append(curr_b->val, merged);
                curr_b = curr_b->next;
            }
        }
        if(curr_a){
            while(curr_a){
                append(curr_a->val, merged);
                curr_a = curr_a->next;
            }
        }
        if(curr_b){
            while(curr_b){
                append(curr_b->val, merged);
                curr_b = curr_b->next;
            }
        }

        return merged;
    }

    ListNode* mergeSort(ListNode* head){
        //Node a will point to the left partition
        ListNode *a = NULL,
        //Node b will point to the right partition
        *b  = NULL,
        //Node c will point to the newly merged stack
        *c  = NULL;

        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }

        split(head, a, b);

        a=mergeSort(a);
        b=mergeSort(b);
        c=merge(a,b);
        return c;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *sortedList = NULL;
        for(ListNode *i : lists){
            while(i){
                append(i->val, sortedList);
                i = i->next;
            }
        }
        return mergeSort(sortedList);
    }
};