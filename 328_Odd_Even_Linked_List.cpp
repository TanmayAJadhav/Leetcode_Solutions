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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *oddhead = head->next;
        ListNode *temp = head;
        ListNode* save1 = NULL, *save2 = NULL;
        while(temp->next != NULL)
        {
            save1 = temp->next;
            temp->next = save1->next;
            if(temp->next == NULL)
            {
                break;
            }
            save2 = temp->next;
            save1->next = save2->next;
            temp = temp->next;
        }

        temp->next = oddhead;
        return head;
        
    }
};