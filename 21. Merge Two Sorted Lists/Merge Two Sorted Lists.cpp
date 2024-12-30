#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* ptr;

        if (l1->val > l2->val) {
            ptr = l2;
            l2 = l2->next;
        }
        else {
            ptr = l1;
            l1 = l1->next;
        }

        ListNode* cur = ptr;
        cout << cur << endl;
        cout << ptr << endl;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            }
            else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
            cout << cur << endl;
            cout << ptr << endl;
        }

        if (!l1) {
            cur->next = l2;
        }
        else {
            cur->next = l1;
        }
        return ptr;
    }


int main()
{
    
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(6);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(5);

    ListNode* mergedList = mergeTwoLists(l1, l2);

    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
}
