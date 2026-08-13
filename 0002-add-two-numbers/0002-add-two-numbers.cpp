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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        vector<int> s1;
        vector<int> s2;

        while (t1 != NULL) {
            s1.push_back(t1->val);
            t1 = t1->next;
        }
        while (t2 != NULL) {
            s2.push_back(t2->val);
            t2 = t2->next;
        }
        vector<int> result;

        int carry = 0;
        int n = max(s1.size(), s2.size());

        for (int i = 0; i < n; i++) {
            int a = (i < s1.size()) ? s1[i] : 0;
            int b = (i < s2.size()) ? s2[i] : 0;

            int sum = a + b + carry;

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry)
            result.push_back(carry);

        ListNode* head = new ListNode(result[0]);
        ListNode* prev = head;
        for (int i = 1; i < result.size(); i++) {
            ListNode* temp = new ListNode(result[i], nullptr);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
};