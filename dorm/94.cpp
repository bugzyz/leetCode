#include "header.hpp"
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include <queue>
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    std::queue<TreeNode*> q;
    vector<int> result;
    q.push(root);
    while (!q.empty()) {
      TreeNode* tn = q.front();
      if (tn == NULL) {
        return result;
      }

      if (tn->left != NULL) {
        TreeNode* left = tn->left;
        if (left) {
          q.push(left);
          cout << "push:" << left->val;
          continue;
        }
      }
      result.push_back(tn->val);
      if (tn->right != NULL) {
        TreeNode* right = tn->right;
        if (right) {
          q.push(right);
          cout << "push:" << right->val;
        }
      }
      q.pop();
    }
    return result;
  }
};

int main() {
  TreeNode c(3);
  TreeNode b(2);
  TreeNode a(1);
  a.left = &b;
  a.right = &c;
  vector<int> res = Solution().inorderTraversal(&a);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}