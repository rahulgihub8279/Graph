class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int sr,int sc,int iniCol,int newCol){
        ans[sr][sc]=newCol;
        int n=image.size();
        int m=image[0].size();
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nr=sr+delrow[i];
            int nc=sc+delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==iniCol && ans[nr][nc]!=newCol){
                dfs(image,ans,nr,nc,iniCol,newCol);        
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initialColor=image[sr][sc];
        dfs(image,ans,sr,sc,initialColor,color);

        return ans;
    }
};