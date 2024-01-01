#ifndef _search_tree_h_
#define _search_tree_h_

#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // 递归实现插入操作
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // 公有接口：查找元素，如果找不到则插入
    void searchAndInsert(int value) {
        root = searchAndInsertRecursive(root, value);
    }

    // 递归实现查找和插入操作
    TreeNode* searchAndInsertRecursive(TreeNode* node, int value) {
        // 如果节点为空，说明找到了插入的位置，插入新节点
        if (node == nullptr) {
            return new TreeNode(value);
        }

        // 如果值小于当前节点的值，继续在左子树中查找
        if (value < node->data) {
            node->left = searchAndInsertRecursive(node->left, value);
        }
        // 如果值大于当前节点的值，继续在右子树中查找
        else if (value > node->data) {
            node->right = searchAndInsertRecursive(node->right, value);
        }
        // 如果值等于当前节点的值，不进行插入操作，直接返回当前节点
        else {
            std::cout << "元素 " << value << " 已存在，不进行插入操作。" << std::endl;
            return node;
        }

        return node;
    }

    // 中序遍历二叉搜索树，用于验证操作结果
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // 公有接口：中序遍历二叉搜索树
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};


#endif