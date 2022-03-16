/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, int> mp;
        while(headA != NULL)
        {
                mp.insert(pair<ListNode *, int>(headA,1));
            headA = headA -> next;
        }
        while(headB != NULL)
        {
            if(mp[headB]==1)
            {
                return headB;
            }
            headB = headB->next;
        }
                    return NULL;
    }
};