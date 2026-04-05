from collections import deque
import sys

input = sys.stdin.readline

R, C = map(int, input().split())
lake = [list(input().strip()) for _ in range(R)]

# 방향 벡터
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

# 백조 위치 저장
swans = []

# 물 BFS용 큐
water_q = deque()
water_visited = [[False] * C for _ in range(R)]

# 백조 BFS용 큐
swan_q = deque()
swan_visited = [[False] * C for _ in range(R)]

# 초기 상태 세팅
for r in range(R):
    for c in range(C):
        if lake[r][c] != 'X':  # 물 또는 백조 위치
            water_q.append((r, c))
            water_visited[r][c] = True

        if lake[r][c] == 'L':
            swans.append((r, c))

# 백조 시작점
sr, sc = swans[0]
er, ec = swans[1]

swan_q.append((sr, sc))
swan_visited[sr][sc] = True


# 백조가 만날 수 있는지 확인하는 BFS
def move_swan():
    next_q = deque()

    while swan_q:
        r, c = swan_q.popleft()

        if (r, c) == (er, ec):
            return True, next_q

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= R or nc < 0 or nc >= C:
                continue
            if swan_visited[nr][nc]:
                continue

            swan_visited[nr][nc] = True

            # 물이면 오늘 바로 이동 가능
            if lake[nr][nc] != 'X':
                swan_q.append((nr, nc))
            # 얼음이면 오늘은 못 가고 내일 후보
            else:
                next_q.append((nr, nc))

    return False, next_q


# 얼음을 하루 동안 녹이는 BFS
def melt():
    next_q = deque()

    while water_q:
        r, c = water_q.popleft()

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= R or nc < 0 or nc >= C:
                continue
            if water_visited[nr][nc]:
                continue

            water_visited[nr][nc] = True

            # 얼음이면 내일 물이 됨
            if lake[nr][nc] == 'X':
                lake[nr][nc] = '.'
                next_q.append((nr, nc))
            # 이미 물이면 계속 확장 가능
            else:
                water_q.append((nr, nc))

    return next_q


days = 0

while True:
    meet, next_swan_q = move_swan()
    if meet:
        print(days)
        break

    water_q = melt()
    swan_q = next_swan_q
    days += 1