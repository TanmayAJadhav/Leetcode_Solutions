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
    int size;
    void getsize(ListNode* head)
    {
        size = 0;
        while(head)
        {
            size++;
            head = head->next;
        }
    }
    
    ListNode* helper(ListNode* head, int &k, int size)
    {
        if(size < k)
        {
            return head;
        }
        ListNode* currptr = head, *prevptr = NULL, *nextptr = NULL;
        int count = 0;
        while(currptr != NULL && count < k)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }     
        
        if(nextptr)
        {
            head->next = helper(nextptr,k,size-k);
        }
        return prevptr;
    } 

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        getsize(head);
        return helper(head,k,size);
    }
};