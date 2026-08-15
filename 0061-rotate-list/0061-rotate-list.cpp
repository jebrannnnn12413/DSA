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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        int count = 1;
        while (temp->next != NULL) {
            count++;
            temp = temp->next;
        }
        k = k % count;

        if (k == 0)
            return head;
        temp->next = head;

        int move = count - k;
        temp = head;
        for (int i = 1; i < move; i++) {
            temp = temp->next;
        }
        ListNode* newhead = temp->next;
        temp->next = NULL;

        return newhead;
    }
};