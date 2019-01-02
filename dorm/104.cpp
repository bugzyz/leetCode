/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <queue>
using namespace std;

int ret_depth(TreeNode *tn, int depth) {
  if (tn == nullptr) {
    return depth;
  }
  depth++;
  int left_depth = ret_depth(tn->left, depth);
  int right_depth = ret_depth(tn->right, depth);
  return left_depth > right_depth ? left_depth : right_depth;
}
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    int depth = 0;
    if (root == nullptr) {
      return depth;
    } else
      return ret_depth(root, 0);
  }
};