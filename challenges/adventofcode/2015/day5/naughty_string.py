#!/usr/bin/env python3
import hashlib

def part1():
    words = open('input.txt').read().strip().splitlines()
    NOT_ALLOWED = ('ab', 'cd', 'pq', 'xy')
    VOWELS = ('a', 'e', 'i', 'o', 'u')

    good_words = []

    invalid = False

    for word in words:
        vowel_count = 0
        twice_in_a_row = False

        invalid = False
        good_word = True

        for i, c in enumerate(word):
            if i != (len(word) - 1):
                current_pair = word[i:i + 2]

                if current_pair in NOT_ALLOWED:
                    invalid = True
                    break

                if current_pair == current_pair[::-1]:
                    twice_in_a_row = True

            if c in VOWELS:
                vowel_count += 1

        if invalid:
            continue

        good_word = twice_in_a_row and vowel_count >= 3

        if good_word:
            good_words.append(word)

    print('Part 1:', len(good_words))

def part2():
    words = open('input.txt').read().strip().splitlines()

    good_words = []

    for word in words:
        count = {}

        has_between_repeat = False
        has_double_pair = False

        skip_next = False
        for i, c in enumerate(word):
            if i != len(word) - 1 and not skip_next:
                current_pair = word[i:i + 2]

                if current_pair == current_pair[::-1]:
                    if i != len(word) - 2 and word[i + 2] == current_pair[0]:
                        skip_next = True

                current_count = count.get(current_pair)
                if not current_count:
                    count[current_pair] = 1
                else:
                    count[current_pair] += 1
            else:
                skip_next = False

            if i != len(word) - 2 and i != len(word) - 1:
                current_triplet = word[i:i + 3]

                if current_triplet == current_triplet[::-1]:
                    has_between_repeat = True

        if len(list(filter(lambda x: x >= 2, count.values()))):
            has_double_pair = True

        if has_between_repeat and has_double_pair:
            good_words.append(word)

    print('Part 2:', len(good_words))

if __name__ == '__main__':
    part1()
    part2()
