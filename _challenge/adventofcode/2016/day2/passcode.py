#!/usr/bin/env python3

def part1():
    f = open('input.txt')

    direction_map = {
        'R': (0, 1),
        'L': (0, -1),
        'U': (1, -1),
        'D': (1, 1)
    }

    keypad = [
        ['1', '2', '3'],
        ['4', '5', '6'],
        ['7', '8', '9']
    ]

    position = [1, 1]
    code = []

    while True:
        content = f.readline().strip()
        if not content:
            break

        for c in content:
            index, change = direction_map[c]

            position[index] = max(0, min(2, position[index] + change))

        code.append(keypad[position[1]][position[0]])

    print(''.join(code))


def part2():
    f = open('input.txt')

    direction_map = {
        'R': (0, 1),
        'L': (0, -1),
        'U': (1, -1),
        'D': (1, 1)
    }

    keypad =[
        ['0', '0', '1', '0', '0'],
        ['0', '2', '3', '4', '0'],
        ['5', '6', '7', '8', '9'],
        ['0', 'A', 'B', 'C', '0'],
        ['0', '0', 'D', '0', '0']
    ]

    position = [2, 0]

    code = []

    while True:
        content = f.readline().strip()
        if not content:
            break

        for c in content:
            index, change = direction_map[c]
            potential = list(position)

            potential[index] = max(0, min(4, position[index] + change))
            if keypad[potential[1]][potential[0]] == '0':
                pass
            else:
                position = potential

        code.append(keypad[position[1]][position[0]])

    print(''.join(code))

if __name__ == '__main__':
    part1()
    part2()
