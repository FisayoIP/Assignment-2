#ifndef NODE_H_
#define NODE_H_

//Struct for the node taken from class
template <typename Item_Type>
struct Node {

    Item_Type data;
    Node* next;

    Node(const Item_Type& data_item, Node* next_ptr = nullptr)
        : data(data_item), next(next_ptr) {}
};

#endif
