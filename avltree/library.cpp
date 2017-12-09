#include "library.h"

#include <iostream>
#include <iomanip>

AvlTree::Node::Node(int const val) : key(val) {

}

AvlTree::Node::Node(int const val, Node *left, Node *right) : key(val), left(left), right(right) {

}

AvlTree::Node::~Node() {
    if (left != nullptr) {
        delete (left);
    }
    if (right != nullptr) {
        delete (right);
    }
}

int AvlTree::Node::childs() const {
    if (left == nullptr && right == nullptr)
        return 0;
    if (left == nullptr || right == nullptr)
        return 1;
    return 2;
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

/**
 *
 * @param key the key of the node to remove.
 * @return
 */
bool AvlTree::remove(int const key) {

    if (root == nullptr)
        return false;
    Node *element = root;
    while (true) {
        if (element->key == key) {
            break;
        }
        if (key > element->key && element->right) {
            element = element->right;
        } else if (key < element->key && element->left) {
            element = element->left;
        } else {
            return false;
        }
    }
    //Maybe the rool shall be deleted.
    if (element->previous) {
        bool isLeft = element->previous->left == element;
        switch (element->childs()) {
            case 0:
                //No childs delete node and go upwords to root.
                isLeft ? element->previous->left : element->previous->right = nullptr;
                delete element;
                break;
            case 1:
                //Only one child attach node to previous and delete.
                Node *child = element->left ? element->left : element->right;
                isLeft ? element->previous->left : element->previous->right = child;
                //Otherwise we destroy the child by removing the node.
                element->left ? element->left : element->right = nullptr;
                child->previous = element->previous;
                delete element;
                break;
            case 2:
                break;
        }
    } else {
        //Root node shal be deleted!
        switch (element->childs()) {
            case 0:
                delete root;
                root = nullptr;
                break;
            case 1:
                Node *child = element->left ? element->left : element->right;
                Node *tmpRoot = root;
                root = child;
                element->left ? element->left : element->right = nullptr;
                child->previous = nullptr;
                delete tmpRoot;
                break;
        }
    }

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
    toInsert->previous = element;
    if (key > element->key) {
        element->right = toInsert;
        element->balance += 1;
    } else {
        element->left = toInsert;
        element->balance -= 1;
    }
    upin(element);

    return true;
}


void AvlTree::upin(AvlTree::Node *input) {
    if (input != nullptr && input->previous != nullptr) {
        Node *previous = input->previous;
        if (input == previous->left) {
            if (previous->balance == -1 && input->balance == -1) {
                rotateRight(previous);
            } else if (previous->balance == -1 && input->balance == 1) {
                rotateLeftRight(previous);
            } else if (previous->balance == 1) {
                previous->balance = 0;
            } else if (previous->balance == 0) {
                previous->balance = -1;
                upin(previous);
            }
            return;
        } else if (input == previous->right) {
            if (previous->balance == 1 && input->balance == 1) {
                rotateLeft(previous);
            } else if (previous->balance == 1 && input->balance == -1) {
                rotateRightLeft(previous);
            } else if (previous->balance == -1) {
                previous->balance = 0;
            } else if (previous->balance == 0) {
                previous->balance = 1;
                upin(previous);
            }
            return;
        }
    }
}

//input old root get new root
AvlTree::Node *AvlTree::rotateLeft(AvlTree::Node *input) {
    Node *inputRightLeft = input->right->left;
    Node *inputPrevious = input->previous;
    Node *inputRight = input->right;

    if (inputPrevious != nullptr) {
        if (inputPrevious->left == input) {
            inputPrevious->left = inputRight;
        } else {
            inputPrevious->right = inputRight;
        }
        inputRight->previous = inputPrevious;
    } else {
        root = inputRight;
        inputRight->previous = nullptr;
    }
    inputRight->left = input;
    input->previous = inputRight;
    input->right = inputRightLeft;
    if (inputRightLeft)
        inputRightLeft->previous = input;

    input->balance = 0;
    inputRight->balance = 0;

    return inputRight;
};

//input old root get new root
AvlTree::Node *AvlTree::rotateRight(AvlTree::Node *input) {
    Node *inputLeftRight = input->left->right;
    Node *inputPrevious = input->previous;
    Node *inputLeft = input->left;

    if (inputPrevious != nullptr) {

        if (inputPrevious->left == input) {
            inputPrevious->left = inputLeft;
        } else {
            inputPrevious->right = inputLeft;
        }
        inputLeft->previous = inputPrevious;
    } else {
        root = inputLeft;
        inputLeft->previous = nullptr;
    }
    inputLeft->right = input;
    input->previous = inputLeft;
    input->left = inputLeftRight;
    if (inputLeftRight)
        inputLeftRight->previous = input;

    input->balance = 0;
    inputLeft->balance = 0;
    return inputLeft;
};

//input old root get new root
AvlTree::Node *AvlTree::rotateLeftRight(AvlTree::Node *input) {
    Node *tmp = input->left->right;
    bool leftSmaller = true;
    if (tmp->balance = -1) {
        leftSmaller = false;
    }
    rotateLeft(input->left);
    Node *toReturn = rotateRight(input);
    if (leftSmaller) {
        toReturn->left->balance = -1;
    } else {
        toReturn->right->balance = 1;
    }
    return toReturn;
};

//input old root get new root
AvlTree::Node *AvlTree::rotateRightLeft(AvlTree::Node *input) {
    Node *tmp = input->right->left;
    bool leftSmaller = true;
    if (tmp->balance = -1) {
        leftSmaller = false;
    }
    rotateRight(input->right);
    Node *toReturn = rotateLeft(input);
    if (leftSmaller) {
        toReturn->left->balance = -1;
    } else {
        toReturn->right->balance = 1;
    }
    return toReturn;
};

ostream &operator<<(ostream &stream, AvlTree &tree) {
    tree.display();
    return cout;
};

void AvlTree::display() {
    cout << "Tree" << endl;
    display(root, 0);
}

void AvlTree::display(AvlTree::Node *current, int indent) {
    if (current != nullptr) {
        display(current->right, indent + 10);
        if (indent > 0)
            cout << setw(indent) << " ";
        cout << current->key << endl;
        display(current->left, indent + 10);
    }
}

AvlTree &operator+=(AvlTree &tree, int const param) {
    tree.insert(param);
    return tree;
};

AvlTree &operator-=(AvlTree &tree, int const param) {
    tree.remove(param);
    return tree;
};

bool AvlTree::isBalanced() {
    isBalanced(root);
}

/* Returns true if binary tree with root as root is height-balanced */
bool AvlTree::isBalanced(AvlTree::Node *root) {
    int lh;
    int rh;

    if (root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
        return 1;

    return 0;
}

int AvlTree::height(AvlTree::Node *node) {
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}