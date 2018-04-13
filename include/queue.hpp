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
    node_t* tail;

public:
    queue_t()
    {
        head = nullptr;
        tail = nullptr;
    }
    
    ~queue_t()
    {
        while(head != nullptr){
            node_t* node = head;
            head = head->next;
            delete node;
        }
    }
    
    node_t * head_() {
		return head;
	}
	node_t * tail_() {
		return tail;
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
            tail->next = new node_t;
            tail = tail->next;
            tail->value = val;
            tail->next = nullptr;
        }
    }
    
    T pop()
    {
        if(head == nullptr){
            throw std::logic_error("Error delete element");
        }
        T a = head->value;
        node_t* node = head;
        head = head->next;
        delete node;
        return a;
    }
    
    queue_t<T> & operator=(queue_t<T> const & other)
    {
        ~queue_t();
        node_t* node = other.head_;
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
