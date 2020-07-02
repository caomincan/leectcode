class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();

        unordered_map<int, int> dist;
        dist[1]= 0;

        queue<int> queue;
        queue.push(1);

        while (!queue.empty()) {
            int s = queue.front();
            queue.pop();
            if (s == N*N) return dist[s];

            for (int s2 = s+1; s2 <= min(s+6, N*N); ++s2) {
                int rc = get(s2, N);
                int r = rc / N, c = rc % N;
                int s2Final = board[r][c] == -1 ? s2 : board[r][c];
                if (dist.find(s2Final) == dist.end()) {
                    dist[s2Final] = dist[s] + 1;
                    queue.push(s2Final);
                }
            }
        }
        return -1;
    }
    
    int get(int s, int N) {
        // Given a square num s, return board coordinates (r, c) as r*N + c
        int quot = (s-1) / N;
        int rem = (s-1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
};