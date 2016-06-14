#include <iostream>
#include <stdlib.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *res, *p;
    p = res = (struct ListNode *)malloc(sizeof(struct ListNode));
    int flag = 0, sum;
    while (l1 != NULL && l2 != NULL) {
        sum = l1->val + l2->val + flag;
        flag = 0;
        if (sum > 9) {
            flag = 1;
            sum -= 10;
        }
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = sum;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 == NULL) {
        while (l2 != NULL) {
            sum = l2->val + flag;
            flag = 0;
            if (sum > 9) {
                flag = 1;
                sum -= 10;
            }
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = sum;
            l2 = l2->next;
        }
    } else {
        while (l1 != NULL) {
            sum = l1->val + flag;
            flag = 0;
            if (sum > 9) {
                flag = 1;
                sum -= 10;
            }
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = sum;
            l1 = l1->next;
        }
    }
    if (flag) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 1;
    }
    p->next = NULL;
    return res->next;
}

int main()
{
    struct ListNode *l1, *l2, *p, *res;
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    p = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = p;
    p->val = 4;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 3;
    p->next = NULL;

    p = (struct ListNode *)malloc(sizeof(struct ListNode));

    l2->val = 5;
    l2->next = p;
    p->val = 6;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 4;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 4;
    p->next = NULL;

    res = addTwoNumbers(l1, l2);
    while (res != NULL) {
        cout << res->val<<endl;
        res = res->next;
    }

    return 0;
}
