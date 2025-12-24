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

## [1697 숨바꼭질](https://www.acmicpc.net/problem/1697)

최소 시간을 구한다는 점, 수빈이가 총 세 군데로 이동할 수 있다는 점을 미루어 보아 BFS를 사용해 풀 수 있다는 것을 알 수 있다. 각 점에 대하여 수빈이가 최소로 이동할 수 있는 시간을 구하고 원하는 점에 도달할 때까지 계속 확장한다.

    if (!visited[a - 1] && a - 1 < MAX && a - 1 >= MIN)
        {
            q.push(a - 1);
            map[a - 1] += map[a] + 1;
            visited[a - 1] = true;
            if (a - 1 == k)
            {
                cout << map[a - 1];
                return;
            }
        }

## [11967 불켜기](https://www.acmicpc.net/problem/11967)

해당 칸에서 켤 수 있는 불의 방 위치를 리스트로 저장한다.

    vector<pair<int, int>> map[101][101];

입장한 방에서 켤 수 있는 불의 방을 모두 켠 후, 불을 켠 방까지 도달할 수 있는지 확인하기 위한 상하좌우 검사를 실시한다. 불을 켠 방으로부터 상하좌우에서 이미 방문한 방이 있다면 해당 방으로 도달할 수 있다는 뜻이다. 도달할 수 있다면, 불을 켠 방도 큐에 넣는다.

        for (pair<int, int> p : map[x][y])
        {
            if (!lighted[p.first][p.second])
            {
                lighted[p.first][p.second] = true;
                answer++;
                for (int i = 0; i < 4; i++)
                {
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];
                    if (nx > 0 && nx <= n && ny > 0 && ny <= n)
                    {
                        // 도달할 수 있는 방
                        if (visited[nx][ny])
                        {
                            q.push(make_pair(p.first, p.second));
                            visited[p.first][p.second] = true;
                        }
                    }
                }
            }
        }

## [13549 숨바꼭질 3](https://www.acmicpc.net/problem/13549)

-1, *2와 +1, +1은 동일한 거리에 도달하지만 총 비용이 다르다. *2를 최대한 많이 쓰는 게 유리한데 이걸 많이 쓰기 위해서는 반대되는 방향, 즉 -1이 많을수록 유리하다. 그래서 -1이 +1보다 먼저 와야 한다. [출처] (https://www.acmicpc.net/board/view/144960)

## [7569 토마토](https://www.acmicpc.net/problem/7569)

3개의 자료형을 묶고싶을 때는 tuple을 사용하고, tuple의 값에 접근하려면 인덱스를 이용한다.

        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
