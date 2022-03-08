// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* Previous = NULL;
        ListNode* Current = head;
        ListNode* Next = NULL;
        
        while(Current != NULL)
        {
            Next = Current->next;
            Current->next = Previous;
            Previous = Current;
            Current =  Next;
        }
        return Previous;
    }
};