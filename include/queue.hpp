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
	
	T head__(node_t* head_){
		return head_->value;
	}
	
	T tail__(node_t* tail_){
		return tail_->value;
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
	if(head == nullptr){
		tail = nullptr;
	}
        delete node;
        return a;
    }
    
	queue_t(queue_t<T> const & other)
	{
		node_t* node = other.head_();
        	while(node != nullptr){
			push(node->value);
			node = node->next;
		}
        	return *this;
	}
	
    queue_t<T> & operator=(queue_t<T> & other)
    {
	    if(other.head_()! = nullptr){
		    ~queue_t();
             }

        node_t* node = other.head_();
        while(node != nullptr){
		push(node->value);
		node = node->next;
	}
        return *this;
    }
};
