#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head);

ListNode* makeList(std::vector<int> v) {
    ListNode* head = NULL;
    if (v.size() > 0) {
        head = new ListNode(v[0]);
        ListNode* tmp = head;
        for (int i = 1; i < v.size(); i++) {
            tmp->next = new ListNode(v[i]);
            tmp = tmp->next;
        }
    }
    
    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
}

int main(int argc, char **argv)
{
	printList(reverseList(makeList(std::vector<int>({1, 2, 3, 4, 5}))));
    std::cin.get();
	return 0;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL)
        return NULL;
        
    ListNode* cur = head;
    ListNode* node = head->next;
    head->next = NULL;
    while (node) {
        ListNode* tmp = node->next;
        node->next = cur;
        cur = node;
        node = tmp;
    }
    
    return cur;
}
