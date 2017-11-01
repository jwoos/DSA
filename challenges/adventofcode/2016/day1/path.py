#!/usr/bin/env python3

def part1():
    f = open('input.txt')
    directions = [dir.strip().lower() for dir in f.read().split(', ')]
    position = [0, 0]

    guide = ['west', 'north', 'east', 'south']

    direction_map = {
        'west': (0, -1),
        'south': (1, -1),
        'east': (0, 1),
        'north': (1, 1)
    }

    current_direction = 1

    for dir in directions:
        if dir[0] == 'l':
            current_direction -= 1
        else:
            current_direction += 1

        if current_direction == -1:
            current_direction = len(guide) - 1
        elif current_direction == 4:
            current_direction = 0

        position_index, multiplier = direction_map[guide[current_direction]]

        position[position_index] += multiplier * int(dir[1:])

    print(position)
    print(abs(position[0]) + abs(position[1]))

def part2():
    f = open('input.txt')
    directions = [dir.strip().lower() for dir in f.read().split(', ')]
    position = [0, 0]
    history = []

    guide = ['west', 'north', 'east', 'south']

    direction_map = {
        'west': (0, -1),
        'east': (0, 1),
        'south': (1, -1),
        'north': (1, 1)
    }

    current_direction = 1

    for dir in directions:
        if dir[0] == 'l':
            current_direction -= 1
        else:
            current_direction += 1

        if current_direction == -1:
            current_direction = 3
        elif current_direction == 4:
            current_direction = 0

        position_index, multiplier = direction_map[guide[current_direction]]
        delta = multiplier * int(dir[1:])
        change = 1 if delta > 0 else -1

        for _ in range(abs(delta)):
            position[position_index] += change

            if position in history:
                print(position)
                print(abs(position[0]) + abs(position[1]))
                return

            history.append(list(position))


if __name__ == '__main__':
    part1()
    part2()
