/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> preorder(Node root) {
        LinkedList<Integer> ans=new LinkedList<>();
        return helper(root,ans);  
    }

    public List<Integer> helper(Node root,LinkedList ans){
        if(root==null){
            return ans;
        }

        ans.add(root.val);
       
        for(Node i : root.children){
            helper(i,ans);
        }
        
        return ans;
    }

}