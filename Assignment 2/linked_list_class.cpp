#include "linked_list_class.h"
#include <iostream>



///// function to check if the lsit is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;  // returns true if no elements
}


///// the constructor and destructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() {
    head = nullptr;
    tail = nullptr;
    num_items = 0; // start with an empty list
}
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front(); // clean up memory so no leaks happen
    }
}


///// push front and back
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item, head);
    head = new_node;
    if (tail == nullptr) {
        tail = head;
    }
    num_items++;
}
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;  // attach new node to end of list, to make things easier later
        tail = new_node;
    }
    num_items++;
}


///// front and back 
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->data; // returns first element 
}
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return tail->data; // last element in the list
}


///// pop functions
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
if (empty()) {
    throw std::out_of_range("This List is empty");
}
Node<Item_Type>* temp = head;
head = head->next;
delete temp; // free memory for removed node
num_items--;
if (head == nullptr) {
    tail = nullptr;  
}
}
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw std::out_of_range("There's nothing in your list");
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<Item_Type>* curr = head;
        while (curr->next != tail) {
            curr = curr->next; // move until before the tail (little tricky loop)
        }
        delete tail;
        tail = curr;
        tail->next = nullptr;
    }
    num_items--; // decrement after removal
}

///// insert at given index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
        return;
    }
    if (index >= num_items) {
        push_back(item); // add to end if index is too big
        return;
    }
    Node<Item_Type>* curr = head;
    for (size_t i = 0; i < index - 1; i++) {
        curr = curr->next;  // walk to the right spot in the list
    }

    Node<Item_Type>* new_node = new Node<Item_Type>(item, curr->next);
    curr->next = new_node;
    num_items++;
}


///// find the index of first occurrence
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* curr = head;
    size_t index = 0;
    while (curr != nullptr) {
        if (curr->data == item) {
            return index; // found match yay!
        }
        curr = curr->next;
        index++; // move foward through the list
    }
    return num_items;  // item not found
}


///// remove item at index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false; // index out of range
    }
    if (index == 0) {
        pop_front();
        return true;
    }
    Node<Item_Type>* curr = head;
    for (size_t i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    Node<Item_Type>* to_delete = curr->next;
    curr->next = curr->next->next;

    if (to_delete == tail) {
        tail = curr; // update tail if needed, otherwise tail gets left behind
    }
    delete to_delete;
    num_items--;
    return true; // return true if deleted successfully
}
