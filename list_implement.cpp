#include <iostream>


struct ListNode
{
    ListNode* next;
    int key;

    ListNode(int key) : key(key) {};
};

int main()
{
    auto head = ListNode(5);  
    head.next = new ListNode(6);

    std::cout << head.key << std::endl;
}