/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st; // see below for explaination. 
        while(root || !st.empty()){
            while(root){
                st.push({root,false});
                root = root->left;
            }
            /*//I'm at the node with no left elements
            //Now the problem becomes when should 
            we push eleemnt to ans and 
            when should we pop from stack?

            // i believe i need to stop where 
            there aint any left or right, 
            then push it to the ans the go back. to prev node.

            //Now considering this current node we came to has a right
            then we'll go to that then, now when we come back 
            from the right to our current,
             we need to push this specific node.
            how will i make sure that i have visited the right of it?

            //this is where that boolean comes
             where i mark if 
            i have visited the right of it or not.*/
            root = st.top().first;
            while(st.top().second){
                //this while condition would be helpful when we are
                // are at the right most node, i dont want to right more
                //think about it.
                ans.push_back(root->val);
                st.pop();
                if(st.empty()) break;
                root=st.top().first;
            }
            if(st.empty()) break; 
            st.pop();
            st.push({root,true});
            root = root->right;
            
            
           
            

        }
        return ans;
    }
};