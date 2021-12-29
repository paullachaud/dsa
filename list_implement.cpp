#include <iostream>
#include <vector>
#include <memory>

template <typename T>
struct ListNode
{
    std::shared_ptr<ListNode<T>> next;
    T key;

    ListNode() {}
    ListNode(T key) : key(key) {}
};

/* Unique ptrs cannot be copied because they are used to define unique ownership of the memory.
Therefore the copy constructor cannot be generated properly.

Many of list operations require the use of a dummy/temporary node to point to an object, therefore that ListNode is no longer "uniquely ownded".
*/
template <typename T>
struct List {
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(T val)
    {
        auto tmp = std::make_shared<ListNode<T>>(val);
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
        std::shared_ptr<ListNode<T>> node = head;
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