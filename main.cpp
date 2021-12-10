#include <iostream>
#include <vector>
#include "set"

using namespace std;

class Node{
public:
    int val;
    int height = 0;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    Node* parent = nullptr;
public:
    Node();
    Node(int, int);
};

Node::Node(int i, int h) {
    val = i;
    height = h;
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
}

Node::Node() {
    val = 0;
    height = 0;
    left_child = nullptr;
    right_child = nullptr;
    parent = nullptr;
}

void show(Node *&Tree){
    if (Tree != nullptr){
        show(Tree->left_child);
        cout << Tree->val;
        show(Tree->right_child);
    }
}

void Insert(int x, Node *&tree, int& h) {
    if (nullptr == tree){
        tree = new Node;
        tree->val = x;
        tree->height = 1;
        tree->left_child = tree->right_child = nullptr;
    }
    if (x < tree->val){
        if (tree->left_child != nullptr) Insert(x,tree->left_child, h);
        else{
            tree->left_child = new Node;
            tree->left_child->left_child = tree->left_child->right_child = nullptr;
            tree->left_child->val = x;
            tree->left_child->height = tree->height + 1;
            if(h < tree->left_child->height) h = tree->left_child->height;
        }
    }
    if (x > tree->val){
        if (tree->right_child != nullptr) Insert(x, tree->right_child, h);
        else{
            tree->right_child = new Node;
            tree->right_child->left_child = tree->right_child->right_child = nullptr;
            tree->right_child->val = x;
            tree->right_child->height = tree->height + 1;
            if(h < tree->right_child->height) h = tree->right_child->height;
        }
    }
}

int main() {
    vector<int> v;
    set<int> s;
    while(true){
        int a;
        cin >> a;
        if(a == 0) break;
        if(s.count(a) == 0){
            v.push_back(a);
            s.insert(a);
        }
    }
    Node *Tree = nullptr;
    int h = 1;
    for(int i = 0; i< v.size();i++)
        Insert(v[i],Tree, h);
    cout << h << endl;
    return 0;
}
