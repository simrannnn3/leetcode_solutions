class Solution {
public:
    struct state{
        int x;
        int y;
        int mask;
        int moves;
    };
    bool islower(char c){
        if(c>='a' && c<='z')return true;
        return false;
    }
    bool isupper(char c) {
        return c >= 'A' && c <= 'Z';
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int src,dst;
        int keys=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    src=i;
                    dst=j;
                }
                if(islower(grid[i][j])){
                    keys++;
                }
            }
        }
        queue<state>q;
        int fullmask=(1<<keys)-1;
        q.push({src,dst,0,0});
        vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(1<<keys,false)));
        vis[src][dst][0]=true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            state curr=q.front();
            q.pop();
            if(curr.mask==fullmask)return curr.moves;
            for(int i=0;i<4;i++){
                int nx=dr[i]+curr.x;
                int ny=dc[i]+curr.y;
                if(nx>=n || nx<0 || ny>=m || ny<0)continue;
                if(grid[nx][ny]=='#')continue;
                int newmask = curr.mask;
                if(isupper(grid[nx][ny])){
                    int key=grid[nx][ny]-'A';
                    if(!(newmask & (1<<key)))continue;
                }
                if(islower(grid[nx][ny])){
                    int key=grid[nx][ny]-'a';
                    newmask|=(1<<key);
                }
                if(!vis[nx][ny][newmask]){
                    vis[nx][ny][newmask]=true;
                    q.push({nx,ny,newmask,curr.moves+1});
                }
            }
        }
        return -1;

    }
};