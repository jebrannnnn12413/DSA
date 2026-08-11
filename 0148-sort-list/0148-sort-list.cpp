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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        if (arr.empty()) {
            return NULL;
        }
        temp = new ListNode(arr[0]);
        ListNode* newHead = temp;
        ListNode* prev = temp;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i], nullptr);
            prev->next = temp;
            prev = temp;
        }
        return newHead;
    }
};