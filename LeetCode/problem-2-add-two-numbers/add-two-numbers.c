/*Running time ~ 32 ms and this runtime beats 56.55 % of c submissions.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int computeResultOfAddition(struct ListNode* l1, struct ListNode* l2, int carryover)
{
    int res_value = 0;
    if      (l1!=NULL && l2!=NULL) res_value = l1->val + l2->val + carryover;
    else if (l1!=NULL && l2==NULL) res_value = l1->val + carryover;
    else if (l1==NULL && l2!=NULL) res_value = l2->val + carryover;
    return res_value;
}

struct ListNode* createNode()
{
    return (struct ListNode *)malloc(sizeof(struct ListNode));
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * result = createNode();
    struct ListNode * first = result;
    int carryover = 0;
    
    while(l1!=NULL || l2!=NULL)
    {
        int res_value;
        
        if(carryover)
        {
            res_value = computeResultOfAddition(l1, l2, carryover);
            carryover = 0;
        }
        else
            res_value = computeResultOfAddition(l1, l2, carryover);

        if(res_value >= 10)
        {
            carryover = 1;
            res_value = res_value - 10;
        }
        result->val = res_value;
        
        if((l1!=NULL && l2!=NULL && l1->next!=NULL && l2->next!=NULL) 
           || (l1!=NULL && l2!=NULL && l1->next == NULL && l2->next!=NULL)
            || (l1!=NULL && l2!=NULL && l1->next != NULL && l2->next==NULL)
            || (l1!=NULL && l1->next!=NULL) // When l2 is NULL in the first three statements
            || (l2!=NULL && l2->next!=NULL) // When l1 is NULL in the first four statements
          )
        {
            result->next = createNode();
            result=result->next;
        }
        else result->next = NULL;
        
        if(l1!=NULL) l1 = l1->next;
        if(l2!=NULL) l2 = l2->next;
    }
    
    if(carryover)
    {
        result->next = createNode();
        result->next->val = carryover;
        result->next->next = NULL;
    }
    
    return first;
}