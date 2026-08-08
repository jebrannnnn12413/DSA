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
    bool isPalindrome(ListNode* head) {
        vector<int> sve;
        ListNode* temp = head;

        while (temp != NULL) {
            sve.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = sve.size() - 1;

        while (i < j) {
            if (sve[i] != sve[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};