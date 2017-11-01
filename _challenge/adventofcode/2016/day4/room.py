#!/usr/bin/env python3

from collections import Counter
import re

def part1():
    f = open('input.txt')

    sum = 0

    while True:
        content = f.readline().strip()
        if not content:
            break

        checksum = re.search(r'\[(\w+)\]', content).group(1)
        id = int(re.search(r'\d+', content).group(0))
        letters = ''.join(re.findall(r'(\w+)-', content))

        count = Counter(letters)
        count_ordered = sorted([(-n, c) for c, n in count.most_common()])
        chars = ''.join(c for n, c in count_ordered)

        if chars[:5] == checksum:
            sum += id

    print(sum)


def part2():
    f = open('input.txt')

    rot = lambda char, n: ''.join([chr(97 + ((ord(x) - 97 + (n % 26)) % 26)) for x in char])

    while True:
        content = f.readline().strip()
        if not content:
            break

        checksum = re.search(r'\[(\w+)\]', content).group(1)
        id = int(re.search(r'\d+', content).group(0))
        letters = ''.join(re.findall(r'(\w+)-', content))

        count = Counter(letters)
        count_ordered = sorted([(-n, c) for c, n in count.most_common()])
        chars = ''.join(c for n, c in count_ordered)

        if chars[:5] == checksum:
            for word in re.findall(r'(\w+)-', content):
                rotated = rot(word, id)
                if rotated == 'north' or rotated == 'pole' or rotated == 'northpole':
                    print(id)
                    return

if __name__ == '__main__':
    part1()
    part2()
