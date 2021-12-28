#include <iostream>
#include <vector>

template <typename T>
struct ListNode
{
    ListNode* next;
    T key;

    ListNode() {}
    ListNode(T key) : key(key) {}
};

template <typename T>
struct List {
    ListNode<T>* head;
    ListNode<T>* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int val)
    {
        ListNode<T>* tmp = new ListNode<T>(val);
        if (head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void display(std::ostream& os)
    {
        ListNode<T>* node = head;
        while (node != nullptr)
        {
            os << node->key << " ";
            node = node->next;
        }
        os << std::endl;
    }
};



int main()
{
    List<int> list = List<int>();
    list.insert(5);
    list.display(std::cout);

    list.insert(12);
    list.insert(34);
    list.insert(3);
    list.insert(22);
    list.insert(5);
    list.insert(4);

    list.display(std::cout);

}