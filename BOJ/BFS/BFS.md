# BFS

## [7576 토마토](https://www.acmicpc.net/problem/7576)

하나의 토마토로부터 영향을 받은 후 다른 토마토에서 또 영향을 받는 것이 아니라 여러개의 토마토로부터 동시에 영향을 받기 때문에 토마토의 위치를 처음부터 모두 큐에 넣고 BFS를 수행한다.
즉, 시작점이 여러개일 때는 시작점을 모두 큐에 넣고 BFS 탐색을 수행한다.

## [4179 불!](https://www.acmicpc.net/problem/4179)

불도 번지는 동시에 지훈이도 가장 짧은 거리를 탐색한다. 즉, 불과 지훈 두 개의 개체에 대해 각각의 BFS가 수행되어야한다. 이처럼 시작점이 두 종류일 때는 각각 BFS 탐색을 수행한다. 이 경우에서 지훈이가 BFS를 수행할 때는, 번진 불에 대한 조건을 추가하여 이동할 수 있는 거리를 확보한다.

            if (nx >= 0 && nx < R && ny >= 0 && ny < C)
            {
                if (j_maze[nx][ny] == 0 && maze[nx][ny] == '.')
                {
                    // 불이 이미 번졌고 (f_maze[nx][ny] != 0) 불이 번진 시점보다 더 뒤에 도착한 경우는 이동할 수 없다.
                    if (f_maze[nx][ny] != 0 && f_maze[nx][ny] <= j_maze[x][y] + 1)
                        continue;

                    j_maze[nx][ny] = j_maze[x][y] + 1;
                    j_q.push(make_pair(nx, ny));

                    if (nx == 0 || nx == R - 1 || ny == 0 || ny == C - 1)
                    {
                        return j_maze[nx][ny];
                    }
                }
            }
        }
