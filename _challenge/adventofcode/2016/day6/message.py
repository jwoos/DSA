#!/usr/bin/env python3

from collections import Counter

def part1():
    f = open('input.txt')
    lines = [l.strip() for l in f.readlines() if l]

    count = [Counter(x).most_common()[0][0] for x in zip(*lines)]

    print(''.join(count))



def part2():
    f = open('input.txt')
    lines = [l.strip() for l in f.readlines() if l]

    count = [Counter(x).most_common()[-1][0] for x in zip(*lines)]

    print(''.join(count))

if __name__ == '__main__':
    part1()
    part2()
