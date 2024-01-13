class Solution {
public:
    unordered_map<int,vector<int>>tree;
    void dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            
            return;
        }
        if(root->left){
            tree[root->val].push_back(root->left->val);
            tree[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right){
            tree[root->val].push_back(root->right->val);
            tree[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        queue<pair<int,int>>q;
        int time=0;
        q.push({start,0});
        set<int>vis;
        vis.insert(start);
        while(!q.empty()){
            auto front=q.front();
            int node=front.first;
            int currTime=front.second;
            time=max(time,currTime);
            q.pop();
            for(auto &it:tree[node]){
                if(vis.find(it)==vis.end()){
                    //means if not visited
                    vis.insert(it);
                    q.push({it,currTime+1});
                }
            }
        }
        for(auto &it:tree){
            for(auto &jt:it.second){
                cout<<" ";
            }
        }
        return time;
    }
};
