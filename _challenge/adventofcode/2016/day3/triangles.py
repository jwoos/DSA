#!/usr/bin/env python3

def part1():
    f = open('input.txt')

    count = 0
    possible = [(x, y, z) for x in range(3) for y in range(3) for z in range(3) if x != y and y != z and x != z]

    while True:
        content = f.readline().strip()

        if not content:
            break

        content = [int(x) for x in content.split(' ') if x]

        is_triangle = True

        for pos in possible:
            x, y, z = pos

            if not content[x] + content[y] > content[z]:
                is_triangle = False
                break

        if is_triangle:
            count += 1

    print(count)


def part2():
    f = open('input.txt')

    count = 0
    possible = [(x, y, z) for x in range(3) for y in range(3) for z in range(3) if x != y and y != z and x != z]

    while True:
        contents = [
            [int(x) for x in f.readline().strip().split(' ') if x] for _ in range(3)
        ]

        if not contents[0]:
            break

        temp = [contents[y][x] for x in range(3) for y in range(3)]
        actual_contents = [
            temp[0:4],
            temp[3:7],
            temp[6:]
        ]

        for cont in actual_contents:
            is_triangle = True

            for pos in possible:
                x, y, z = pos

                if not cont[x] + cont[y] > cont[z]:
                    is_triangle = False
                    break

            if is_triangle:
                count += 1

    print(count)


if __name__ == '__main__':
    part1()
    part2()
