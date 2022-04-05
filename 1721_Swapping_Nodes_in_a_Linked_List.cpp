// You are given the head of a linked list, and an integer k. Return the head of the linked list after swapping the values of the 
// kth node from the beginning and the kth node from the end (the list is 1-indexed).

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

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
    ListNode* swapNodes(ListNode* head, int k) {
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
        ListNode *temp = head;
        int cnt = 1;

        map<int,ListNode*> mp;
        while(temp->next != NULL)
        {
            mp.insert(pair<int,ListNode*>(cnt,temp));
            temp = temp->next;
            cnt++;
        }
        mp.insert(pair<int,ListNode*>(cnt,temp));
        // cout<<mp[k]->val<<" "<<cnt-k+1;
            int tempval = mp[k]->val;
            mp[k]->val = mp[cnt-k+1]->val;
            mp[cnt-k+1]->val = tempval;
            return head;
        
        
    }
};