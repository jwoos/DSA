#!/usr/bin/env python2

from collections import deque


def get_possible_moves(maze, coord):
    max_row = len(maze) - 1
    max_col = len(maze[0]) - 1

    row, col = coord
    moves = []

    if row < max_row:
        # no up
        moves.append((row + 1, col))

    if row > 0:
        # no down
        moves.append((row - 1, col))

    if col < max_col:
        # no left
        moves.append((row, col + 1))

    if col > 0:
        # no right
        moves.append((row, col - 1))

    return moves

def bfs(maze):
    q = deque([(0, 0)])
    max_row = len(maze) - 1
    max_col = len(maze[0]) - 1

    matrix = [[0 for _ in range(len(maze[0]))] for _ in range(len(maze))]
    matrix[0][0] = 1

    while q:
        x, y = q.popleft()

        if (x, y) == (max_row, max_col):
            return matrix[x][y]

        for m in get_possible_moves(maze, (x, y)):
            m_x, m_y = m

            if not matrix[m_x][m_y] and not maze[m_x][m_y]:
                matrix[m_x][m_y] = matrix[x][y] + 1
                q.append((m_x, m_y))

    return None

def generate_all_possible(maze):
    walls = []
    for x in range(len(maze)):
        for y in range(len(maze[0])):
            # passable we don't care
            if not maze[x][y]:
                continue

            # get all possible walls
            moves = get_possible_moves(maze, (x, y))
            # check of there are less than 3 walls around
            # which means it can be travelled to and has a route after breaking
            if sum([maze[i][j] for (i, j) in moves]) < 3:
                walls.append((x, y))

    # generate all possible mazes when walls are removed
    all = [maze]
    for wall in walls:
        x, y = wall
        copy = [i[:] for i in maze]
        copy[x][y] = 0
        all.append(copy)

    return all

def answer(maze):
    shortest = 1000000

    all_possible = generate_all_possible(maze)

    for m in all_possible:
        length = bfs(m)

        if length is not None and length < shortest:
            shortest = length

    return shortest

# print(answer([[0, 1, 1, 0], [0, 0, 1, 0], [1, 0, 1, 0]]))
# print(answer([[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]))
# print(answer([[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]))
print(answer([
    [0,1,1,1,1,1,1,1,0,1,1],
    [0,1,1,0,0,0,1,1,0,0,0],
    [0,0,0,0,1,0,1,1,0,1,1],
    [1,1,1,1,1,0,1,1,0,1,1],
    [0,0,0,0,1,0,1,0,0,0,0],
    [0,1,1,0,1,0,1,0,1,1,0],
    [0,1,1,0,0,0,1,0,1,1,0],
    [0,1,1,1,1,1,1,0,1,1,0],
    [0,0,0,0,0,0,1,0,1,1,0],
    [1,1,1,1,1,0,1,0,1,1,0],
    [1,1,1,1,1,0,0,0,1,1,0]
]))
# print(answer([[0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]))
# print(answer([[0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]))
