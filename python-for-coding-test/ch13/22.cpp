#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set<int> visited;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int N = board.size();
    int time = 0;
    int row_flag = 1;
    int robot_coord[2][2] = {{1, 1}, {1, 2}};
    
    vector<int> v;
    queue<vector<int>> q;
    
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            v.push_back(robot_coord[i][j]);
    v.push_back(row_flag);
    v.push_back(time);
    
    q.push(v);
    visited.insert(11102);
    
    while(!q.empty()) {
        int sx = q.front()[0];
        int sy = q.front()[1];
        int ex = q.front()[2];
        int ey = q.front()[3];
        row_flag = q.front()[4];
        time = q.front()[5];
        
        q.pop();
        
        if((sx == N && sy == N) || (ex == N && ey == N)) {
            answer = time;
            break;
        }
        
        // move
        for(int i = 0; i < 4; ++i) {
            int move_sx = sx + dx[i];
            int move_sy = sy + dy[i];
            int move_ex = ex + dx[i];
            int move_ey = ey + dy[i];
            
            if(move_sx < 1 || move_sy < 1 || move_ex < 1 || move_ey < 1)
                continue;
            if(move_sx > N || move_sy > N || move_ex > N || move_ey > N)
                continue;
            
            if(board[move_sx - 1][move_sy - 1] || board[move_ex - 1][move_ey - 1])
                continue;
            
            if(visited.find(move_sx * 10000 + move_sy * 1000 + move_ex * 100 + move_ey) != visited.end())
                continue;
            
            visited.insert(move_sx * 10000 + move_sy * 1000 + move_ex * 100 + move_ey);
            
            vector<int> info;
            info.push_back(move_sx);
            info.push_back(move_sy);
            info.push_back(move_ex);
            info.push_back(move_ey);
            info.push_back(row_flag);
            info.push_back(time + 1);
            
            q.push(info);
        }
        
        // rotate
        for(int i = 0; i < 4; ++i) {
            int rotate_sx, rotate_sy, rotate_ex, rotate_ey;
            int rotate_wx, rotate_wy;
            
            if(row_flag) {  
                if(i % 2 == 0) {
                    rotate_sx = sx;
                    rotate_sy = sy;
                    rotate_ex = sx + dx[i];
                    rotate_ey = sy;
                    
                    rotate_wx = sx + dx[i];
                    rotate_wy = sy + 1;
                }
                else {
                    rotate_sx = ex;
                    rotate_sy = ey;
                    rotate_ex = ex + dx[i - 1];
                    rotate_ey = ey;
                    
                    rotate_wx = ex + dx[i - 1];
                    rotate_wy = ey - 1;
                }
            }
            else {
                if(i % 2 == 0) {
                    rotate_sx = sx;
                    rotate_sy = sy;
                    rotate_ex = sx;
                    rotate_ey = sy + dy[i + 1];
                    
                    rotate_wx = sx + 1;
                    rotate_wy = sy + dy[i + 1];
                }
                else {
                    rotate_sx = ex;
                    rotate_sy = ey;
                    rotate_ex = ex;
                    rotate_ey = ey + dy[i];
                    
                    rotate_wx = ex - 1;
                    rotate_wy = ey + dy[i];
                }
            }
            
            if(rotate_ex < 1 || rotate_ey < 1 || rotate_ex > N || rotate_ey > N)
                continue;
            if(rotate_wx < 1 || rotate_wy < 1 || rotate_wx > N || rotate_wy > N)
                continue;
            
            if(board[rotate_ex - 1][rotate_ey - 1] || board[rotate_wx - 1][rotate_wy - 1])
                continue;
            
            if(visited.find(rotate_sx * 10000 + rotate_sy * 1000 + rotate_ex * 100 + rotate_ey) != visited.end())
                continue;
            
            visited.insert(rotate_sx * 10000 + rotate_sy * 1000 + rotate_ex * 100 + rotate_ey);
            
            vector<int> info;
            info.push_back(rotate_sx);
            info.push_back(rotate_sy);
            info.push_back(rotate_ex);
            info.push_back(rotate_ey);
            
            row_flag = (row_flag == 1) ? 0 : 1; 
            info.push_back(row_flag);
            info.push_back(time + 1);
            
            q.push(info);
        }
        
    }
    
    return answer;
}

