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

class ListCmp {
    public:
    bool operator() (ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListCmp> pq;
        for (auto lst: lists) { 
            if (lst != nullptr) pq.push(lst); 
        }

        ListNode* root = new ListNode;
        ListNode* curr = root;

        while(!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            curr->next = tmp;
            curr = tmp;
            tmp = tmp->next;
            if (tmp != nullptr) { pq.push(tmp); }
        }

        return root->next;
    }
};

int main(){
    vector<vector<int> > lists1_nums{{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists1;
    for (auto v: lists1_nums) {
        ListNode* node = new ListNode;
        node->init(v);
        lists1.push_back(node);
    }

    Solution sol;
    ListNode* ans = sol.mergeKLists(lists1);
    ans->display();

    return 0;
}