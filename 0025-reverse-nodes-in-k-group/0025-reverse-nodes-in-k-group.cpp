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
    ListNode* reversell(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* newhead = reversell(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    ListNode* getKnode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* kThNode = getKnode(temp, k);
            if (kThNode == NULL) {

                if (prev)
                    prev->next = temp;
                break;
            }
            ListNode* nextnode = kThNode->next;
            kThNode->next = NULL;
            reversell(temp);
            if (temp == head) {
                head = kThNode;
            } else {
                prev->next = kThNode;
            }
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};