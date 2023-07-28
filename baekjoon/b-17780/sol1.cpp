#include <iostream>
#include <vector>

using namespace std;

enum Color {WHITE, RED, BLUE};

struct Board {
    Color color;
    int bottom_idx = -1;
    int top_idx = -1;
    int pcount = 0;
};

struct Piece_info {
    int x;
    int y;
    int dir;
    int up_idx = -1;
    int down_idx = -1;
};

int N, K;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}; // r l u d

void move_piece(vector<Piece_info>& chess, int nx, int ny, int idx) {
    while(idx != -1) {
        chess[idx].x = nx;
        chess[idx].y = ny;
        idx = chess[idx].up_idx;    
    }
}

void reverse_piece(vector<Piece_info>& chess, int idx) {
    while(idx != -1) {
        int tmp = chess[idx].up_idx;
        chess[idx].up_idx = chess[idx].down_idx;
        chess[idx].down_idx = tmp;
        idx = tmp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    Board **board = new Board*[N + 1];
    for(int i = 0; i <= N; ++i)
        board[i] = new Board[N + 1];

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            int color;
            cin >> color;
            board[i][j].color = static_cast<Color>(color);
        }   
    }

    vector<Piece_info> chess(K);
    for(int i = 0; i < K; ++i) {
        int x, y, d;
        cin >> x >> y >> d;

        chess[i].x = x;
        chess[i].y = y;
        chess[i].dir = d - 1;
        
        board[x][y].bottom_idx = i;
        board[x][y].top_idx = i;
        board[x][y].pcount += 1;
    }

    int turn = 0;
    while(turn <= 1000) {
        bool break_flag = false;
        turn += 1;

        for(int i = 0; i < K; ++i) {
            int idx = board[chess[i].x][chess[i].y].bottom_idx;
            if(idx != i)
                continue;
            
            Piece_info& p = chess[idx];
            int nx = p.x + dx[p.dir];
            int ny = p.y + dy[p.dir];

            if(nx < 1 || ny < 1 || nx > N || ny > N || board[nx][ny].color == BLUE) {
                p.dir = (p.dir < 2) ? 1 - p.dir : 5 - p.dir;
                nx = p.x + dx[p.dir];
                ny = p.y + dy[p.dir];
            }

            if(nx < 1 || ny < 1 || nx > N || ny > N || board[nx][ny].color == BLUE)
                continue;

            board[nx][ny].pcount += board[p.x][p.y].pcount;
            board[p.x][p.y].pcount = 0;
            if(board[nx][ny].pcount >= 4) {
                break_flag = true;
                break;
            }

            if(board[nx][ny].color == RED) {
                reverse_piece(chess, idx);
                int tmp = board[p.x][p.y].bottom_idx;
                board[p.x][p.y].bottom_idx = board[p.x][p.y].top_idx;
                board[p.x][p.y].top_idx = tmp;

                idx = board[p.x][p.y].bottom_idx;
            }

            if(board[nx][ny].bottom_idx == -1)
                board[nx][ny].bottom_idx = idx;
            else {
                chess[idx].down_idx = board[nx][ny].top_idx;
                chess[board[nx][ny].top_idx].up_idx = idx;
            }
            
            board[nx][ny].top_idx = board[p.x][p.y].top_idx;
            board[p.x][p.y].bottom_idx = -1;
            board[p.x][p.y].top_idx = -1;

            move_piece(chess, nx, ny, idx);
        }

        if(break_flag)
            break;
    }

    if(turn > 1000)
        turn = -1;

    std::cout << turn << '\n';

    return 0;
}