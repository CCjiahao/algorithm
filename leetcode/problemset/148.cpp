#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<vector<T>> make_2_vector(initializer_list<initializer_list<T>> lists) {
    vector<vector<T>> ans;
    for(auto& list : lists) ans.push_back(vector<int>(list));
    return ans;
}

template <typename T>
void print_vector(vector<T> list, bool endline=true) {
    for(int i = 0; i < list.size(); i++) {
        if(i == 0) cout << '[';
        cout << list[i];
        if(i == list.size() - 1) cout << ']';
        else cout << ',';
    }
    if(endline) cout << endl;
}

template <typename T>
void print_2_vector(vector<T> list) {
    for(int i = 0; i < list.size(); i++) {
        if(i == 0) cout << '[';
        print_vector(list[i], false);
        if(i == list.size() - 1) cout << ']';
        else cout << ',';
    }
}

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void print_ListNode(ListNode* head) {
    if(!head) return;
    cout << head->val << endl;
    print_ListNode(head->next);
}

class Solution {
public:
    ListNode* find_mid(ListNode* begin, ListNode* end) {
        ListNode* slow = begin, *fast = begin;
        while(fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge_sort(ListNode* begin, ListNode* end) {
        if(begin == end || begin->next == end) return begin;

        auto mid = find_mid(begin, end);
        ListNode* left = merge_sort(begin, mid);
        ListNode* right = merge_sort(mid, end);

        // add a pre node
        ListNode left_head(0, begin), right_head(0, right);
        left = &left_head, right = &right_head;

        while(left->next != mid && right->next != end) {
            while(left->next != mid && left->next->val <= right->next->val) left = left->next;
            auto right_next = right->next;
            right->next = right->next->next;
            auto left_next = left->next;
            left->next = right_next;
            right_next->next = left_next;
            left = left->next;
        }
        while(left->next != mid) left = left->next;
        left->next = right->next;
        return left_head.next;
    }

    ListNode* sortList(ListNode* head) {
        head = merge_sort(head, nullptr); 
        return head;
    }
};

int main() {
    Solution solution;
    ListNode head;
    ListNode *now = &head;
    auto a = {-1,5,3,4,0};
    for(auto c: a){
        now->next = new ListNode(c);
        now = now->next;
    }
    solution.sortList(head.next);
    return 0;
}