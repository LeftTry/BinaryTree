#include <iostream>
#include <vector>

using namespace std;

class Node{
    int val;
    int height = 0;
    Node* left_child;
    Node* right_child;
    Node* parent;
public:
    Node(int);
    void set_parent(Node*);
    void set_left_child(Node*);
    void set_right_child(Node*);
    void set_val(int);
    int get_val();
    int get_height();
    void set_height(int);
    Node* get_parent();
    Node* get_left_child();
    Node* get_right_child();
};

void Node::set_parent(Node * node) {
    parent = node;
}

void Node::set_left_child(Node * node) {
    left_child = node;
}

void Node::set_right_child(Node * node) {
    right_child = node;
}

void Node::set_val(int Val) {
    val = Val;
}

int Node::get_val() {
    return val;
}

Node *Node::get_parent() {
    return parent;
}

Node *Node::get_left_child() {
    return left_child;
}

Node *Node::get_right_child() {
    return right_child;
}

Node::Node(int i) {
    val = i;
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
}

int Node::get_height() {
    return height;
}

void Node::set_height(int h) {
    height = h;
}

class BinaryTree{
    Node* start;
    int height;
public:
    BinaryTree(int);
    int get_height();
    Node* get_start();
    void create(int&, vector<int>&, Node*);
};

BinaryTree::BinaryTree(int v) {
    Node start_(v);
    start = &start_;
    start->set_parent(nullptr);
    start->set_height(1);
}

void BinaryTree::create(int & i, vector<int> & v, Node* parent) {
    Node node(v[i]);
    if(parent->get_val() > node.get_val()){
        parent->set_left_child(&node);
        node.set_parent(parent);
        i++;
        node.set_height(parent->get_height());
        if(node.get_height() > height) height = node.get_height();
        create(i, v, &node);
    }
    else if(parent->get_val() < node.get_val()){
        create(i, v, parent->get_parent());
    }
}

int BinaryTree::get_height() {
    return height;
}

Node *BinaryTree::get_start() {
    return start;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++) cin >> v[i];
    BinaryTree tree(v[0]);
    int i = 1;
    tree.create(i, v, tree.get_start());
    cout << tree.get_height() << endl;
    return 0;
}
