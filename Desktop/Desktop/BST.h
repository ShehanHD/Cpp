#pragma once
class BST {
private:
    typedef struct self {
        int data;
        int copy = 1;
        self* right;
        self* left;
    }node;

    node* root;
    void addLeafPrivate(int, node*);
    void printInOrderPrivate(node*);
    node* returnNodePrivate(int, node*);
    int findMinPrivate(node*);
    int findMaxPrivate(node*);
    void removeNodePrivate(int, node*);
    void removeRoot();
    void removeMatch(node*, node*, bool);
    node* createLeaf(int);
    node* returnNode(int);
    int sumPrivate(node*);
    int countNodesPrivate(node*);
    int countLeavesPrivate(node*);

public:
    BST();
    void addLeaf(int);
    void printInOrder();
    int rootKey();
    void printChildren(int);
    int findMin();
    int findMax();
    void removeNode(int);
    bool search(int);
    int sum();
    int countNodes();
    int countLeaves();
    float medium();
};
