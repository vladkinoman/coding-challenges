#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode * head)
{
    for(;head != NULL; head = head->next)
        cout << head->val << " ";
    cout << endl;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        for(ListNode *single_node = head, *curr_node = head; 
            single_node != NULL && single_node->next != NULL;
            single_node->next = curr_node, single_node = single_node->next)
            while(curr_node != NULL && single_node->val == curr_node->val)
	        curr_node = curr_node->next;
        return head;
    }
};



int main()
{   
    // 1st example: 1 1 2
    ListNode * head1 = new ListNode(1);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);
    
    // 2nd example: 1 1 2 3 3
    ListNode * head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);

    Solution newSolution;
    int choice = 0;
    cout << "Choose example: 1 - 1st, 2 - 2nd." << endl;
    cin >> choice;
    
    ListNode * solutionHead;
    switch(choice)
    {
    case 1:
        solutionHead = newSolution.deleteDuplicates(head1);  
        break;
    case 2:
        solutionHead = newSolution.deleteDuplicates(head2);  
        break;
    default:
        break;
    }    
    print_list(solutionHead);

    return 0;
}
