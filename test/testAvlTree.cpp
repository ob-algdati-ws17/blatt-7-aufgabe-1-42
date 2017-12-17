#include "testAvlTree.h"
#include <memory>

using namespace std;

TEST(AvlTreeTest, Insert_Not_Exists) {
    AvlTree tree;
    EXPECT_TRUE(tree.insert(2));
}

TEST(AvlTreeTest, Insert_Exists) {
    AvlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_FALSE(tree.insert(2));
}

TEST(AvlTreeTest, Search_Empty) {
    AvlTree tree;
    EXPECT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, Search_Not_Exists) {
    AvlTree tree;
    tree.insert(1);
    EXPECT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, Search_Exists) {
    AvlTree tree;
    tree.insert(1);
    EXPECT_TRUE(tree.search(1));

}

TEST(AvlTreeTest, Insert_LeftRotateForce){
    AvlTree tree;
    for (int i = 1; i <= 30; i++) {
        tree.insert(i);
    }
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Insert_RightRotateForce){
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Root){
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(15);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_2Childs){
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(11);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_1Childs){
    AvlTree tree;
    for (int i = 26; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(2);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

