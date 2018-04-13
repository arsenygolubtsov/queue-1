#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class queue_t
{
private:
    struct node_t
    {
        node_t* next;
        T value;
    };
private:
    node_t* head;
    node_t* tail

public:
    queue_t()
    {
        head = nullptr;
        tail = nullptr;
    }
    
    ~tree_t()
    {
        if (head != nullptr)
        {
            del(head);
        }
    }

    void del(node_t* run_)
    {
        if (run_ != nullptr)
        {
            if (run_->next != nullptr)
            {
                del(run_->next);
            }
            delete run_;
        }
    }
    
    void push(T val)
    {   
        if (head == nullptr)
        {
            head = new node_t;
            head->value = val;
            head->next = nullptr;
            tail = head;
        }
        else
        {
            tail->next = new node_t
            tail = tail->next;
            tail->value = value;
            tail->next = nullptr;
        }
    }
    
    T pop()
    {
        if(head == nullptr){
            throw Error("Error delete element");
        }
        T a = head->value;
        node_t* node = head;
        head = head->next;
        delete node;
        return a;
    }
    
    queue_t(queue_t const& other)
    {
        node_t* node = other.head;
        head = new node_t;
        head->value = node->value;
        head->next = nullptr;
        tail = head;
        node = node->next;
        while(node != nullptr){
            tail->next = new node_t;
            tail = tail->next;
            tail->value = node->value;
            tail->next = nullptr;
            node = node->next;
        }
        return *this;
    }
    
    auto operator=(queue_t<T> const& other)
    {
        node_t* node = other.head;
        head = new node_t;
        head->value = node->value;
        head->next = nullptr;
        tail = head;
        node = node->next;
        while(node != nullptr){
            tail->next = new node_t;
            tail = tail->next;
            tail->value = node->value;
            tail->next = nullptr;
            node = node->next;
        }
        return *this;
    }
};
