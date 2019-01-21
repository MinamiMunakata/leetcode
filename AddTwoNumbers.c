/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *copy1 = l1;
    int result1[100];
    int i = 0;
    while(copy1)
    {
        result1[i] = copy1->val;
        copy1 = copy1->next;
        i++;
    }

    struct ListNode *copy2 = l2;
    int result2[100];
    int j = 0;
    while (copy2)
    {
        result2[j] = copy2->val;
        copy2 = copy2->next;
        j++;
    }

    int result[100];
    int k = 0;
    int sum = 0;
    while (k < i || k < j)
    {
        if (k < i) sum += result1[k];
        if (k < j) sum += result2[k];
        if (sum < 10)
        {
            result[k] = sum;
            sum = 0;
        }
        else
        {
            result[k] = sum % 10;
            sum = sum / 10;
        }
        k++;
    }
    if (sum > 0)
    {
        result[k] = sum;
        k++;
    }
    struct ListNode *ptr = NULL;
    int l = k - 1;
    while (l >= 0)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = result[l];
        node->next = ptr;
        ptr = node;
        l--;
    }


    return ptr;
    
}
