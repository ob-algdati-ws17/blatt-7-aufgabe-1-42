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

void AvlTree::Node::calcBalance() {
    //Fehler !!
    if (left == nullptr && right == nullptr) {
        balance = 0;
    } else if (left == nullptr) {
        balance = right->balance + 1;
    } else if (right == nullptr ){
        balance = left->balance - 1;
    } else {
        balance = abs(right->balance) - abs(left->balance);
    }
}
/*
void AvlTree::Node::calcBalance() {
    int leftBalance = -1;
    int rightBalance = -1;
    if (left) {
        leftBalance = left->balance;
    }
    if (right) {
        rightBalance = right->balance;
    }
    balance = rightBalance - leftBalance;
}
*/

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
                previous->balance == 0;
            } else if (previous->balance == 0) {
                previous->balance == 1;
                upin(previous);
            }
            return;
        }
    }
}

/*
 * old
void AvlTree::upin(AvlTree::Node *input) {
    if (input != nullptr) {
        int left = -1;
        int right = -1;

        int newBalance = 0;
        if (input->left && !input->right) {
            left = input->left->balance;
            newBalance = left - 1;
        } else if (input->right && !input->left) {
            right = input->right->balance;
            newBalance =  right +1;
        } else{
            left = input->left->balance;
            right = input->right->balance;
            newBalance = right - left;
        }

        if (newBalance == 0) {
            input->balance = newBalance;
            return;
        } else if (abs(newBalance) == 1) {
            input->balance = newBalance;
            upin(input->previous);
        } else {
            if (input->balance == -1 && left == -1) {
                rotateRight(input);
            } else if (input->balance == -1 && left == 1) {
                rotateLeftRight(input);
            } else if (input->balance == 1 && right == 1) {
                rotateLeft(input);
            } else if (input->balance == 1 && right == -1) {
                rotateRightLeft(input);
            }
            return;
        }
    }
}
*/
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
    inputRight->calcBalance();
    input->calcBalance();
    if (inputPrevious)
        inputPrevious->calcBalance();
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
    inputLeft->calcBalance();
    input->calcBalance();
    if(inputPrevious)
        inputPrevious->calcBalance();
    return inputLeft;
};

//input old root get new root
AvlTree::Node *AvlTree::rotateLeftRight(AvlTree::Node *input) {
    rotateLeft(input->left);
    return rotateRight(input);
};

//input old root get new root
AvlTree::Node *AvlTree::rotateRightLeft(AvlTree::Node *input) {
    rotateRight(input->right);
    return rotateLeft(input);
}

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
        display(current->right, indent + 4);
        if (indent > 0)
            cout << setw(indent) << " ";
        cout << current->key << endl;
        display(current->left, indent + 4);
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