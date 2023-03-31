#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    // {
    //     ListNode *temp = new ListNode();
    //     ListNode *head = temp;
    //     int first = 0, second = 0;
    //     int num1 = 0, num2 = 0;
    //     string sum;
    //     while (l1 != nullptr)
    //     {
    //         num1 += l1->val * pow(10, first);
    //         l1 = l1->next;
    //         first++;
    //     }
    //     while (l2 != nullptr)
    //     {
    //         num1 += l2->val * pow(10, second);
    //         l2 = l2->next;
    //         second++;
    //     }

    //     sum = to_string(num1 + num2);
    //     for (int i = sum.length() - 1; i >= 0; i--)
    //     {
    //         string s(1, sum[i]);
    //         temp->val = stoi(s);
    //         if (i != 0)
    //         {
    //             temp->next = new ListNode();
    //             temp = temp->next;
    //         }
    //     }
    //     temp = head;
    //     return temp;
    // }
    {
        ListNode *temp = new ListNode();
        ListNode *head = temp;
        while (!(l1 == nullptr && l2 == nullptr))

            if (l1 != nullptr && l2 != nullptr)
            {
                temp->val = l1->val + l2->val;
                if ((l1->next || l2->next))
                    temp->next = new ListNode();
                temp = temp->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != nullptr && l2 == nullptr)
            {
                temp->val = l1->val;
                if ((l1->next || l2->next))
                    temp->next = new ListNode();
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->val = l2->val;
                if ((l1->next || l2->next))
                    temp->next = new ListNode();
                temp = temp->next;
                l2 = l2->next;
            }

        temp = head;
        int i;
        while (temp != nullptr)
        {
            if ((i = temp->val / 10) == 1)
            {
                temp->next->val++;
                temp->val = temp->val % 10;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    Solution a;
    ListNode *l1, *l2;
    int i;
    for (i = 0; i < 3; i++)
    {
        l1->val = i + 1;
        l1->next = new ListNode();
        l1 = l1->next;
    }
    for (i = 0; i < 3; i++)
    {
        l2->val = i + 2;
        l2->next = new ListNode();
        l2 = l2->next;
    }

    a.addTwoNumbers(l1, l2);

    // int *a, *b;
    // int c = 0, d = 1;
    // a = &c;
    // b = &d;
    // int *temp;
    // temp = a;
    // cout << temp << " " << a << endl;
    // a = b;
    // cout << *a << *temp << endl;
    // cout << temp << " " << a << endl;
}
