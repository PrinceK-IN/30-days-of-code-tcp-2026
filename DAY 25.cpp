#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void getTraversals(BinaryTreeNode<int> *root, vector<int> &in, vector<int> &pre, vector<int> &post) {
    if (root == NULL) {
        return;
    }

    pre.push_back(root->data);
    
    getTraversals(root->left, in, pre, post);

    in.push_back(root->data);
    
    getTraversals(root->right, in, pre, post);
    
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    vector<int> inorder, preorder, postorder;
    getTraversals(root, inorder, preorder, postorder);
    return {inorder, preorder, postorder};
}