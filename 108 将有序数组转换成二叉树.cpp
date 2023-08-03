题目：给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
     高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

解题思路：首先二叉搜索树需要根值大于左子树的值，小于右子树的值，然后还要保持高度差一致
        这样就可以用分置的思路，从排好序的数组中取出中间的值作为根的值，然后左边作为左子树，右边作为右子树

class Solution {
public:
    TreeNode* myinsert(vector<int>& nums,int l,int r){
        if(l>r)return nullptr;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=myinsert(nums,l,mid-1);
        root->right=myinsert(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return myinsert(nums,0,nums.size()-1);
    }
};
