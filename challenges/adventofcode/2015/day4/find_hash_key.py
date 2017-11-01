#!/usr/bin/env python3
import hashlib

def part1():
    secret_key = open('input.txt').read().strip()

    digest = ''
    num = 0
    while not digest.startswith('00000'):
        num += 1
        digest = hashlib.md5((secret_key + str(num)).encode()).hexdigest()

    print('Part 1:', (digest, num))


def part2():
    secret_key = open('input.txt').read().strip()

    digest = ''
    num = 0
    while not digest.startswith('000000'):
        num += 1
        digest = hashlib.md5((secret_key + str(num)).encode()).hexdigest()

    print('Part 2:', (digest, num))

if __name__ == '__main__':
    part1()
    part2()
