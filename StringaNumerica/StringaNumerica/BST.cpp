#include "BST.h"
#include <iostream>

BST::BST() {
    root = NULL;
}

BST::node* BST::createLeaf(int data) {
    node* n = new node;

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::addLeaf(int data) {
    addLeafPrivate(data, this->root);
}

void BST::addLeafPrivate(int data, node* pointer) {
    if (this->root == NULL) {
        this->root = createLeaf(data);
    }
    else if (data < pointer->data) {
        if (pointer->left != NULL) {
            addLeafPrivate(data, pointer->left);
        }
        else {
            pointer->left = createLeaf(data);
        }
    }
    else if (data > pointer->data) {
        if (pointer->right != NULL) {
            addLeafPrivate(data, pointer->right);
        }
        else {
            pointer->right = createLeaf(data);
        }
    }
    else {
        //TODO Count same numbers
        pointer->copy += 1;
    }
}

void BST::printInOrder() {
    printInOrderPrivate(this->root);
}

void BST::printInOrderPrivate(node* pointer) {
    if (this->root != NULL) {
        if (pointer->left != NULL) {
            printInOrderPrivate(pointer->left);
        }
        if (pointer->copy != 1) {
            for (int i = 0; i < pointer->copy; i++)
            {
                std::cout << pointer->data << " ";
            }
        }
        else {
            std::cout << pointer->data << " ";
        }
        if (pointer->right != NULL) {
            printInOrderPrivate(pointer->right);
        }
    }
    else {
        std::cout << "Empty Tree" << std::endl;
    }
}

BST::node* BST::returnNode(int data) {
    return returnNodePrivate(data, this->root);
}

BST::node* BST::returnNodePrivate(int data, node* pointer) {
    if (pointer != NULL) {
        if (pointer->data == data) {
            return pointer;
        }
        else {
            if (data < pointer->data) {
                return returnNodePrivate(data, pointer->left);
            }
            else {
                return returnNodePrivate(data, pointer->right);
            }
        }
    }
    else {
        return NULL;
    }
}

int BST::rootKey() {
    if (this->root != NULL) {
        return this->root->data;
    }
    else {
        return -100000;
    }
}

void BST::printChildren(int data) {
    node* pointer = returnNode(data);

    if (pointer != NULL) {
        std::cout << "\n\nParent> " << pointer->data;

        pointer->left == NULL ? std::cout << "\nLeft child> NULL" : std::cout << "\nLeft child> " << pointer->left->data;

        pointer->right == NULL ? std::cout << "\nRight child> NULL" : std::cout << "\nRight child> " << pointer->right->data;
    }
    else {
        std::cout << "this number is not in the tree\n";
    }
}

int BST::findMin() {
    return findMinPrivate(this->root);
}

int BST::findMinPrivate(node* pointer) {
    if (this->root == NULL) {
        std::cout << "The tree is empty";
        return -100000;
    }
    else {
        return pointer->left != NULL ? findMinPrivate(pointer->left) : pointer->data;
    }
}

int BST::findMax() {
    return findMaxPrivate(this->root);
}

int BST::findMaxPrivate(node* pointer) {
    if (this->root == NULL) {
        std::cout << "The tree is empty";
        return -100000;
    }
    else {
        return pointer->right != NULL ? findMaxPrivate(pointer->right) : pointer->data;
    }
}

void BST::removeNode(int data) {
    removeNodePrivate(data, this->root);
}

void BST::removeNodePrivate(int data, node* parent) {
    if (this->root != NULL) {
        if (this->root->data == data) {
            removeRoot();
        }
        else {
            if (parent->data > data&& parent->left != NULL) {
                if (parent->left->copy != 1 && parent->left->data == data) {
                    parent->left->copy -= 1;
                }
                else {
                    parent->left->data == data ? removeMatch(parent, parent->left, true) : removeNodePrivate(data, parent->left);
                }
            }
            else if (parent->data < data && parent->right != NULL) {
                if (parent->right->copy != 1 && parent->right->data == data) {
                    parent->right->copy -= 1;
                }
                else {
                    parent->right->data == data ? removeMatch(parent, parent->right, false) : removeNodePrivate(data, parent->right);
                }
            }
            else {
                std::cout << "\nThe data you search for is not in this tree!\n";
            }
        }
    }
    else {
        std::cout << "The tree is empty\n";
    }
}

void BST::removeRoot() {
    node* delPointer = this->root;
    int rootData = this->root->data;
    int smallest;

    if (this->root != NULL) {
        //se root non ha figli
        if (this->root->left == NULL && this->root->right == NULL) {
            this->root = NULL;
            delete delPointer;
        }
        else if (this->root->copy != 1) {
            this->root->copy -= 1;
        }
        //se root ha figlio destra
        else if (this->root->left == NULL && this->root->right != NULL) {
            this->root = this->root->right;
            delPointer->right = NULL;
            delete delPointer;
        }
        //se root ha figlio sinistra
        else if (this->root->left != NULL && this->root->right == NULL) {
            this->root = this->root->left;
            delPointer->left = NULL;
            delete delPointer;
        }
        //se root ha tutti i due figli
        else {
            smallest = findMinPrivate(this->root->right);
            removeNodePrivate(smallest, this->root);
            this->root->data = smallest;
        }
    }
    else {
        std::cout << "Tree is empty\n";
    }
}

void BST::removeMatch(node* parent, node* match, bool isLeft) {
    node* delPointer;
    int matchData = match->data;
    int smallest;

    if (root != NULL) {
        //se il nodo uguale alla nodo ricerca non ha figli
        if (match->left == NULL && match->right == NULL) {
            delPointer = match;

            isLeft == true ? parent->left = NULL : parent->right = NULL;

            delete delPointer;
        }
        //se il nodo uguale alla nodo ricerca ha figlio destra
        else if (match->left == NULL && match->right != NULL) {
            delPointer = match;

            isLeft == true ? parent->left = match->right : parent->right = match->right;

            match->right = NULL;
            delPointer = match;
            delete delPointer;
        }
        //se il nodo uguale alla nodo ricerca ha figlio sinistra
        else if (match->left != NULL && match->right == NULL) {
            delPointer = match;

            isLeft == true ? parent->left = match->left : parent->right = match->left;

            match->left = NULL;
            delPointer = match;
            delete delPointer;
        }
        //se il nodo uguale alla nodo ricerca ha tutti i due figli
        else {
            smallest = findMinPrivate(match->right);
            removeNodePrivate(smallest, match);
            match->data = smallest;
        }
    }
    else {
        std::cout << "tree is empty\n";
    }
}

bool BST::search(int data) {
    node* pointer = returnNode(data);

    if (pointer) {
        return true;
    }
    else {
        return false;
    }

}

int BST::sum() {
    return sumPrivate(this->root);
}

int BST::sumPrivate(node* pointer) {
    if (root != NULL) {
        if (pointer == NULL) {
            return 0;
        }
        else {
            return ((pointer->data * pointer->copy) + sumPrivate(pointer->left) + sumPrivate(pointer->right));
        }
    }
    else {
        return -100000;
    }
}

int BST::countNodes() {
    return countNodesPrivate(this->root);
}

int BST::countNodesPrivate(node* pointer) {
    if (root != NULL) {
        if (pointer == NULL) {
            return 0;
        }
        else {
            return (1 + countNodesPrivate(pointer->left) + countNodesPrivate(pointer->right));
        }
    }
    else {
        return -100000;
    }
}

int BST::countLeaves() {
    return countLeavesPrivate(this->root);
}

int BST::countLeavesPrivate(node* pointer) {
    if (root != NULL) {
        if (pointer == NULL) {
            return 0;
        }
        if (pointer->left == NULL && pointer->right == NULL) {
            return 1;
        }
        else {
            return (countLeavesPrivate(pointer->left) + countLeavesPrivate(pointer->right));
        }
    }
    else {
        return -100000;
    }
}

float BST::medium() {
    return root != NULL ? ((float)sum() / (float)countNodes()) : -100000;
}