#include "bst.h"

// ---------------------------------------
// Node class
// Default constructor
Node::Node() {
    this->key = 0;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    
}
// Constructor
Node::Node(int in) {
   this->key = in;
   this->parent = nullptr;
   this->left = nullptr;
   this->right = nullptr;
}
// Destructor
Node::~Node() {}

// Add parent 
void Node::add_parent(Node* in) {
    this->parent = in;
}
// Add to left of current node
void Node::add_left(Node* in) {
    this->left = in;
}
// Add to right of current node
void Node::add_right(Node* in) {
    this->right = in;
}

// Get key
int Node::get_key()
{
    return this->key;
}
// Get parent node
Node* Node::get_parent()
{
    return this->parent;
}
// Get left node
Node* Node::get_left()
{
   return this->left;
}
// Get right node
Node* Node::get_right()
{
    return this->right;
}
// Print the key to ostream to
// Do not change this
void Node::print_info(ostream& to)
{
    to << key << endl;
}
// ---------------------------------------


// ---------------------------------------
// BST class
// Walk the subtree from the given node
void BST::inorder_walk(Node* in, ostream& to)
{
    if (in != nullptr){
        inorder_walk(in->get_left(), to);
        in->print_info(to);
        inorder_walk(in->get_right(), to);
    }
}
// Constructor
BST::BST()
{   root = nullptr;

}

//helper function

void free(Node* in){
    if(in == nullptr){
        return;
    } else{
        free(in->get_left());
        free(in->get_right());
        delete in;
    }

}
// Destructor
BST::~BST()
{
    free(root);
    
}
// Insert a node to the subtree
void BST::insert_node(Node* in)
{
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr){
        y = x;
        if (in->get_key() < x->get_key()){
            x = x->get_left();
        }
        else{
            x = x->get_right();
        }
    }

    in->add_parent(y);
    if (y == nullptr){
        root = in;
    } else if (in->get_key() < y->get_key()){
        y->add_left(in);
    }else{
        y->add_right(in);
    }
    
}
// Delete a node to the subtree
void BST::delete_node(Node* out)
{
    Node* y;
    Node* x;
    // Determine node y to splice out
    //(1) y = the given node has 0/1 child 
    //(2) y = successor of the given node if has 2 children
    if (out->get_left() == nullptr || out->get_right() == nullptr){
        y = out;
    }
    else{
        y = get_succ(out);
    }
    // x is set to child of y or NIL if no child
    if (y->get_left() != nullptr){
        x = y->get_left();
    }else{
        x = y->get_right();
    }
    // Splice out y
    if (x!= nullptr){
        x->add_parent(y->get_parent());
    }

    if (y->get_parent() == nullptr){
        root = x;
    }else if (y == y->get_parent()->get_left()){
        y->get_parent()->add_left(x);
    }else{
        y->get_parent()->add_right(x);
    }
    // If we spliced the successor than put its content into z
    if (y != out){
        y->add_parent(out->get_parent());
        if(y->get_parent() == nullptr) {
            root = y;
        } else {
            if(out == out->get_parent()->get_left()) {
                y->get_parent()->add_left(y);
            } else {
                y->get_parent()->add_right(y);
            }
        }
        y->add_left(out->get_left());
        y->add_right(out->get_right());

        if(y->get_left() != nullptr) {
            y->get_left()->add_parent(y);
        }
        if(y->get_right() != nullptr) {
            y->get_right()->add_parent(y);
        }
    }

    delete out;
}
// minimum key in the BST
Node* BST::tree_min()
{
    Node* cur = root;
    while (cur->get_left() != nullptr){
        cur = cur->get_left();       
    }
    return cur;
}
// maximum key in the BST
Node* BST::tree_max()
{
    Node* cur = root;
    while (cur->get_right() != nullptr){
        cur = cur->get_right();       
    }
    return cur;
}
// Get the minimum node from the subtree of given node
Node* BST::get_min(Node* in)
{
    Node* cur = in;
    while (cur->get_left() != nullptr){
        cur = cur->get_left();       
    }
    return cur;
}
// Get the maximum node from the subtree of given node
Node* BST::get_max(Node* in)
{
    Node* cur = in;
    while (cur->get_right() != nullptr){
        cur = cur->get_right();       
    }
    return cur;
}

// Get successor of the given node
Node* BST::get_succ(Node* in)
{
    if (in == tree_max()){
        return nullptr;
    }
    
    if ((in->get_right()) != nullptr){
        return get_min(in->get_right());
    }

    Node* y = in->get_parent();
    while ((y != nullptr) && (in == y->get_right())){
        in = y;
        y = y->get_parent();
    }
    return y;
}
// Get predecessor of the given node
Node* BST::get_pred(Node* in)
{
    if (in == tree_min()){
        return nullptr;
    }
    if (in->get_left() != nullptr){
        return get_max(in->get_left());
    }
    Node* y = in->get_parent();
    while ((y != nullptr) && (in == y->get_left())){
        in = y;
        y = y->get_parent();
    }
    return y;

}
// Walk the BST from min to max
void BST::walk(ostream& to)
{
    inorder_walk(root, to);
}
// Search the tree for a given key
Node* BST::tree_search(int search_key)
{
    Node* cur = root;
    while ((cur != nullptr) && (search_key != cur->get_key())){
        if (search_key < cur->get_key()){
            cur = cur->get_left();
        }
        else{
            cur = cur->get_right();
        }
    }

    return cur;
    
}
// ---------------------------------------
