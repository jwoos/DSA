#!/usr/bin/env python3

from functools import reduce

def part1():
    total = 0
    wrapping_paper = open('input.txt').read().strip().split('\n')

    for x in wrapping_paper:
        dimensions = list(map(int, x.split('x')))
        areas = [dimensions[0] * dimensions[1], dimensions[0] * dimensions[2], dimensions[1] * dimensions[2]]
        areas.sort()

        total += areas[0]
        total += reduce(lambda x, y: x + (2*y), areas, 0)

    print('part 1:', total)

def part2():
    total = 0
    all_dimensions = open('input.txt').read().strip().split('\n')

    for x in all_dimensions:
        dimensions = list(map(int, x.split('x')))
        dimensions.sort()

        total += (dimensions[0] + dimensions[1]) * 2
        total += reduce(lambda x, y: x*y, dimensions)

    print('part 2:', total)

if __name__ == '__main__':
    part1()
    part2()
