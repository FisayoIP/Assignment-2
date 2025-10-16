#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

#include <cstddef>    // for size_t
#include <stdexcept>  // for exceptions
#include "node.h"     // your existing Node struct

template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

public:
    // Constructor and destructor
    Single_Linked_List();
    ~Single_Linked_List();
    
    // Core member functions
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;

    // Utility
    size_t size() const { return num_items; }
};

#include "linked_list_class.cpp"  // include implementation
#endif
