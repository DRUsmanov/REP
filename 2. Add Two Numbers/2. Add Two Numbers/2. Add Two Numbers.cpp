#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && l2) return l2;
        if (!l2 && l1) return l1;
        if (!l1 && !l2) return 0;
        ListNode* result = new ListNode();
        ListNode* result_complete = result;
        int chek = 0;
        while (l1 && l2 ) {
            int sum = l1->val + l2->val + chek;
            if (sum >= 10) {
                chek = 1;
                sum = sum - 10;
            }
            else {
                chek = 0;
            }
            result->val = sum;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 || l2) {
                result->next = new ListNode();
                result = result->next;
            }
            else if (chek!=0) {
                result->next = new ListNode();
                result = result->next;
                result->val = chek;
            }
        }
        if (l1 && !l2) {
            while (l1) {
                int sum = l1->val + chek;
                if (sum >= 10) {
                    chek = 1;
                    sum = sum - 10;
                }
                else {
                    chek = 0;
                }
                result->val = sum;
                l1 = l1->next;
                if (l1) {
                    result->next = new ListNode();
                    result = result->next;
                }
                else if (chek != 0) {
                    result->next = new ListNode();
                    result = result->next;
                    result->val = chek;
                }
            }
        }
        if (l2 && !l1) {
            while (l2) {
                int sum = l2->val + chek;
                if (sum >= 10) {
                    chek = 1;
                    sum = sum - 10;
                }
                else {
                    chek = 0;
                }
                result->val = sum;
                l2 = l2->next;
                if (l2) {
                    result->next = new ListNode();
                    result = result->next;
                }
                else if (chek != 0) {
                    result->next = new ListNode();
                    result = result->next;
                    result->val = chek;
                }
            }
        }
        return result_complete;
}

int main()
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    ListNode* sumList = addTwoNumbers(l1, l2);

    while (sumList) {
        cout << sumList->val << " ";
        sumList = sumList->next;
    }
}



  