#ifndef DATASTRUCTURE_TREENODE_H
#define DATASTRUCTURE_TREENODE_H

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): left(nullptr), right(nullptr) {}
    TreeNode(const T& val_): T(val_), left(nullptr), right(nullptr) {}
};

#endif //DATASTRUCTURE_TREENODE_H



