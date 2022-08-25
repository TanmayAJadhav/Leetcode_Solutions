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
        stack<ListNode*>st;
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp->next;
            size++;
        }
        
        for(int i = 0; i < size/2; ++i)
        {
            if((head->val) != st.top()->val)
            {
                return false;
            }
            head = head->next;
            st.pop();
        }
        return true;
        
    }
};