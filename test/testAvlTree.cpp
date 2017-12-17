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


//fails 48, 93, 69, 101, 104, 70, 73, 85, 50, 112, 108, 71
TEST(AvlTreeTest, isFailing){
    AvlTree tree;
    tree += 48;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());
    tree += 93;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 69;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 101;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 104;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 70;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 73;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 85;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 50;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 112;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 108;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());

    tree += 71;
    cout << tree;
    ASSERT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Insert_Multible) {
    int random_integer;
    for (int i = 10; i <= 5000; i++) {
        AvlTree tree;
        for (int j = i; j > 0; j--) {
            random_integer = rand()%(i*10) + 1;
            tree.insert(random_integer);
        }
        cout << "Tree with " << i << " Nodes" << endl;
        ASSERT_TRUE(tree.isBalanced());
    };
}

TEST(AvlTreeTest, Remove_Multible) {
    int random_integer;
    for (int i = 10; i <= 5000; i++) {
        AvlTree tree;
        for (int j = i; j > 0; j--) {
            tree.insert(j);
        }
        cout << "Tree with " << i << " Nodes" << endl;
        for (int k = i / 2; k > 0; k--) {
            random_integer = rand() % i + 1;
            tree.remove(random_integer);
        }
        ASSERT_TRUE(tree.isBalanced());
    };
}