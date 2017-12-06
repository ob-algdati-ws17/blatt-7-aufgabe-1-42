#include "library.h"

#include <iostream>

AvlTree::Node::Node(int const val) : key(val) {

}

AvlTree::Node::Node(int const val, Node *left, Node *right) : key(val), left(left), right(right) {

}

AvlTree::Node::~Node() {
    if (left != nullptr) {
        delete(left);
    }
    if (right != nullptr) {
        delete(right);
    }
}

AvlTree::~AvlTree() {
    if (root != nullptr) {
        delete root;
    }
}

bool AvlTree::search(int const key) const {
    Node *element = root;

    while (element != nullptr) {
        if (element->key == key)
            return true;
        if (key > element->key)
            element = element->right;
        else
            element = element->left;
    }
    return false;

}

bool AvlTree::remove(int const key) {

}

bool AvlTree::insert(int const key) {

    Node *toInsert = new Node(key);

    if (root == nullptr) {
        root = toInsert;
        return true;
    }

    Node *element = root;

    while (true) {
        if (element->key == key) {
            //New node is not needed anymore!
            delete toInsert;

            return false;
        }
        if (key > element->key && element->right) {
            element = element->right;
        } else if (key < element->key && element->left) {
            element = element->left;
        } else {
            break;
        }
    }

    if (key > element->key) {
        element->right = toInsert;
    } else {
        element->left = toInsert;
    }

    return true;
}

AvlTree::Node* AvlTree::rotateLeft(AvlTree::Node* input) {
    return input;
};

AvlTree::Node* AvlTree::rotateRight(AvlTree::Node* input) {
    return input;
};

AvlTree::Node* AvlTree::rotateLeftRight(AvlTree::Node* input) {
    return input;
};

AvlTree::Node* AvlTree::rotateRightLeft(AvlTree::Node* input) {
    return input;
};

AvlTree &operator+=(AvlTree &tree, int const param) {
    tree.insert(param);
    return tree;
};

AvlTree &operator-=(AvlTree &tree, int const param) {
    tree.remove(param);
    return tree;
};