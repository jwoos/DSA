#!/usr/bin/env python3

def part1():
    file = open('input.txt')
    text = file.read().strip()
    file.close()

    floor = 0

    for x in text:
        if x == '(':
            floor += 1
        else:
            floor -= 1

    print('part 1:', floor)

def part2():
    file = open('input.txt')
    text = file.read().strip()
    file.close()

    floor = 0
    basement_index = -1

    for index, x in enumerate(text):
        index += 1
        if x == '(':
            floor += 1
        else:
            floor -= 1

        if floor == -1 and basement_index == -1:
            basement_index = index

    print('part 2:', floor, basement_index)

if __name__ == '__main__':
    part1()
    part2()
