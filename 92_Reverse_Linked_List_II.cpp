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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL, *curr = head;
        while(left > 1)
        {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* leftnode = prev, *rightnode = curr, *Next = NULL;
        
        while(right > 0)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            right--;
        }
        
        if(leftnode != NULL)
        {
            leftnode->next = prev;
        }
        else
        {
            head = prev;
        }
        
        rightnode->next = curr;
        return head;
    }
};