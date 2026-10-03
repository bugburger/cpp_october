#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // 1. 两边都为空：对称
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // 2. 只有一边为空：不对称
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // 3. 两个节点值不同：不对称
        if (left->val != right->val) {
            return false;
        }

        // 4. 比较外侧
        bool outside =
            compare(left->left, right->right);

        // 5. 比较内侧
        bool inside =
            compare(left->right, right->left);

        // 外侧和内侧都对称，才是真正对称
        return outside && inside;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return compare(root->left, root->right);
    }
};

int main() {
    /*
              1
             / \
            2   2
           / \ / \
          3  4 4  3

        这是一个对称二叉树
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;

    if (solution.isSymmetric(root)) {
        std::cout << "The tree is symmetric."
                  << std::endl;
    } else {
        std::cout << "The tree is not symmetric."
                  << std::endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;

    delete root->left;
    delete root->right;

    delete root;

    return 0;
}
