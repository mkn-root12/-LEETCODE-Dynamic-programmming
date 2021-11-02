int xM[4] = {-1,0,1,0};
int yM[4] = {0,1,0,-1};

class Solution {
    vector<vector<int>> mgrid;
    int row, col;
    int count;
    int tsteps;
public:
    bool isValid(int x, int y){
        if(x >= 0 && x <= row-1 && y >= 0 && y <= col-1 && mgrid[x][y] != -1)
            return true;
        return false;
    }
    
    void process(int x, int y, int step){
        if(!isValid(x,y))
            return;
        
        if(mgrid[x][y] == 2){
            if(step+1 == tsteps)
                count++;
            return;
        }
        
       
        mgrid[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int nx = x + xM[i];
            int ny = y + yM[i];
            process(nx, ny, step+1);
        }
        mgrid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        mgrid = move(grid);
        count = 0;
        int x, y;
        tsteps = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mgrid[i][j] == 1){
                    x = i;
                    y = j;
                }
                if(mgrid[i][j] != -1)
                    tsteps++;
            }
        }
        process(x, y, 0);
        return count;
    }
};
