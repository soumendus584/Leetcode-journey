class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Store index of each litter
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sx = 0, sy = 0;
        int litter = 0;

        // Find starting position and assign IDs to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        // No litter
        if (litter == 0)
            return 0;

        int totalMask = (1 << litter) - 1;

        /*
            State:
            x       -> row
            y       -> column
            e       -> remaining energy
            mask    -> collected litter
        */

        queue<tuple<int, int, int, int>> q;

        // visited[x][y][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litter, false)
                )
            )
        );

        // Initially no litter is collected
        q.push({sx, sy, energy, 0});
        visited[sx][sy][energy][0] = true;

        int moves = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == totalMask)
                    return moves;

                // Cannot move without energy
                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Outside grid
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    // Obstacle
                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Reset area
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Litter
                    if (classroom[nx][ny] == 'L') {
                        int idx = id[nx][ny];
                        newMask |= (1 << idx);
                    }

                    // Visit this state only once
                    if (!visited[nx][ny][newEnergy][newMask]) {

                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};