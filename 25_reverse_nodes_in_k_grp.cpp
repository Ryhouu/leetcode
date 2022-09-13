#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    init(vector<int>& nums) {
        ListNode* curr = this;
        for (auto x : nums) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        if (this->next != nullptr) {
            this->val = this->next->val;
            this->next = this->next->next;
        }
    }

    display() {
        cout << this->val;
        ListNode* curr = this->next;
        while (curr != nullptr) {
            cout << "->" << curr->val;
            curr = curr->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> sta;
        head = new ListNode(0, head);
        ListNode* curr = head;

        while (true) {
            ListNode* tmp = curr->next;
            for (int i = 0; i < k && tmp != nullptr; i ++) {
                sta.push(tmp);
                tmp = tmp->next;
            }
            if (sta.size() < k) break;
            while (!sta.empty()) {
                curr->next = sta.top();
                sta.pop();
                curr = curr->next;
            }
            curr->next = tmp;
        }

        return head->next;
    }
};

int main(){
    vector<int> l1_nums{1, 2, 3, 4, 5};
    ListNode* l1 = new ListNode;
    l1->init(l1_nums);

    Solution sol;
    // ListNode* ans1 = sol.reverseKGroup(l1, 2);
    // ans1->display();
    ListNode* ans2 = sol.reverseKGroup(l1, 3);
    ans2->display();

    return 0;
}