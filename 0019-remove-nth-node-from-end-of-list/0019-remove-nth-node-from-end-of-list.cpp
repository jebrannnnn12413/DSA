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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* temp = head;
        ListNode* dlt = nullptr;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (n == count) {
            ListNode* dlt = head;
            head = head->next;
            delete dlt;
            return head;
        }
        int newcount = count - n;
        temp = head;

        while (newcount > 1) {
            temp = temp->next;
            newcount--;
        }
        dlt = temp->next;
        temp->next = temp->next->next;
        delete (dlt);
        return head;
    }
};