#ifndef AVLTREE_LIB_H
#define AVLTREE_LIB_H

#include <ostream>

using namespace std;

class AvlTree {
private:
    enum Child{
        left, right
    };
    struct Node {
        ~Node();

        Node(int const);

        Node(int const, Node *, Node *);
        int childs() const;
        Node *getChild(Child) const;
        int key;
        int balance = 0;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *previous = nullptr;


    };

    Node *root = nullptr;

    Node* rotateLeft(Node*);

    Node* rotateRight(Node*);

    Node* rotateLeftRight(Node*);

    Node* rotateRightLeft(Node*);

    void upin(Node*);

    void upout(Node*);

    void display(Node*, int);

    int height(Node*);

    bool isBalanced(Node*);

    void deleteWithoutChild(Node*);

    void deleteWithOneChild(Node*);

    void fixBalancesDelete(Node*);

    void fixBalancesChild(const Node*, Child) const;

public:

    /// Destructor for the tree. Deletes also all nodes
    ~AvlTree();

    /// Searches for a node in the tree.
    /// \return true if found, false if not.
    bool search(int const) const;

    /// Inserts a new node into the tree.
    /// \return true if node was inserted, false if not (Already exists)
    bool insert(int const);

    /// Removes a node in the tree.
    /// \return true if it was removed, false if not (not found)
    bool remove(int const);

    /// Add operator
    /// \return a tree with the new key inserted.
    friend AvlTree &operator+=(AvlTree &, int const);

    /// Remove operator
    /// \return a tree without the key to delete.
    friend AvlTree &operator-=(AvlTree &, int const);

    /// Outputs the tree.
    /// \return the stream containing the output information.
    friend ostream &operator<<(ostream &, AvlTree &);

    /// Displays the tree on the console. Only for testing and debug purpose. Performance is aweful!
    void display();

    /// Tests whether the tree is balanced (or not). Only for testing and debug purpose. Performance is aweful!
    /// \return true if balanced, otherwise false.
    bool isBalanced();

};

#endif