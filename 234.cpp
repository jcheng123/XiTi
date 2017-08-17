#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* build_list()
{
	ListNode* head = new ListNode(10);
    head -> next   = new ListNode(107);
    // head -> next -> next = new ListNode(123);
    // head -> next -> next -> next = new ListNode(169);
    //head -> next -> next -> next -> next = new ListNode(281);
    return head;
}

bool isPalindrome(ListNode* head)
{
	if(!head) return false;
	if(head -> next == NULL) return false;

	ListNode* fast = head;
	ListNode* slow = head;

	while(fast != NULL && fast -> next != NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;
	} 
    
    ListNode* ptr = head;
	while(fast == NULL && ptr -> next != slow)
	{
		ptr = ptr -> next;
	}
    if(fast == NULL && ptr -> next == slow) ptr -> next = NULL;

	while(fast != NULL && ptr != slow)
	{
        ptr = ptr -> next;
	}
	// now, ptr = slow
	ptr = slow;
	ListNode* tmp;
    while(ptr != NULL)
    {
    	tmp = ptr -> next;

    	if(ptr == slow) ptr -> next = NULL;
    	else ptr -> next = slow;

    	slow = ptr;
    	ptr = tmp;
    }

    while(slow != NULL && head != NULL)
    {
          if(slow -> val != head -> val) return false;
          slow = slow -> next;
          head = head -> next;
    }

    return true;
}

int main()
{
	ListNode* head = build_list();
    cout << isPalindrome(head) << endl;
    return 0;
}