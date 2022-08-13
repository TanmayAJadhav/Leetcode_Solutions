// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.You should preserve the 
// original relative order of the nodes in each of the two partitions.

// Example 1:
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:
// Input: head = [2,1], x = 2
// Output: [1,2]

// Constraints:
// The number of nodes in the list is in the range [0, 200].
// -100 <= Node.val <= 100
// -200 <= x <= 200

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode();
        ListNode *right = new ListNode();
        ListNode *temp1 = left; 
        ListNode *temp2 = right;
            
        while(head)
        {
            if((head->val) < x)
            {
                temp1->next = head;
                temp1 = temp1->next;
            }
            else
            {
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head ->next;
        }
        temp1->next = right->next;
        temp2->next = NULL;
        return left->next;
        
    }
};