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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* temp = head;
        stack<ListNode*>st;
        int size = 0;
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp->next;
            size++;
        }
        temp = head;
        if(size == n)
        {
            head = head->next;
            delete temp;
            return head;
        }
        
        if(n > size/2)
        {
            for(int i = 0; i < size-n-1; ++i)
            {
                temp = temp->next;
            }
            ListNode* targeted = temp->next;
            temp->next = temp->next->next;
            delete targeted;
        }
        else
        {
            int i = 0;
            while(i < n-1)
            {
                st.pop();
                i++;
            }
            ListNode* nodetodelete = st.top();
            st.pop();
            st.top()->next = nodetodelete->next;
            delete nodetodelete;
        }
        return head;
        
        
    }
};