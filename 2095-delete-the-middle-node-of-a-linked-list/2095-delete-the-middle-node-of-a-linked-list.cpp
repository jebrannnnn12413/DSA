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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        if (head == NULL || head->next == NULL)
        return NULL;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int newcount = count / 2;
        temp=head;
        while (newcount > 1) {
            temp = temp->next;
            newcount--;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete (del);
        return head;
    }
};