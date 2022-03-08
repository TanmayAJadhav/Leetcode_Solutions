// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the 
// binary representation of a number.Return the decimal value of the number in the linked list.

// Example 1:
// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10

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
    int getDecimalValue(ListNode* head)
    {
        long long int deci = 0;
        int cnt = 0;
        ListNode* head2 = head;
        while(head->next != NULL)
        {
            head = head->next;
            cnt++;
        }
        
        for(int i = cnt; i >= 0; i--)
        {
           deci = deci + (head2->val)*(1<<i);
            head2 = head2->next;
        }
        return deci;
    }
};