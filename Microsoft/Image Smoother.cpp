class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                int s=0;int c=0;

                for (int br = -1; br <= 1; br++){
                    for (int bc = -1; bc <= 1; bc++) {
                        int nr = i + br;
                        int nc = j + bc;
                        if ((nr < 0) || (nr >= m)) continue;
                        if ((nc < 0) || (nc >= n)) continue;
                        s+= img[nr][nc];
                        c++;
                    }
                }
                ans[i][j] = (s / c);
            }
        }
        return ans;
    }
};
