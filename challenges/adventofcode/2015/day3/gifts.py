#!/usr/bin/env python3

def part1():
    position = [0, 0]
    directions = open('input.txt').read().strip()
    visited = set()
    visited.add(tuple(position))

    for x in directions:
        if x == '>':
            position[0] += 1
        elif x == '<':
            position[0] -= 1
        elif x == '^':
            position[1] += 1
        else:
            position[1] -= 1
        visited.add(tuple(position))

    print('Part 1:', len(visited))

def part2():
    santa_position = [0, 0]
    robo_position = [0, 0]
    directions = open('input.txt').read().strip()
    visited = set()
    visited.add(tuple(santa_position))

    next = 'santa'

    for x in directions:
        if next == 'santa':
            next = 'robot'
            position = santa_position
        else:
            next = 'santa'
            position = robo_position

        if x == '>':
            position[0] += 1
        elif x == '<':
            position[0] -= 1
        elif x == '^':
            position[1] += 1
        else:
            position[1] -= 1

        visited.add(tuple(position))

    print('Part 2:', len(visited))

if __name__ == '__main__':
    part1()
    part2()
