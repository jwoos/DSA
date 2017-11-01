#!/usr/bin/env python3

import regex as re # builtin re module doesn't support overlap

def part1():
    f = open('input.txt')
    lines = [l.strip() for l in f.readlines()]

    outside = r'(\w+)\['
    end = r'](\w+)'
    inside = r'\[(\w+)\]'
    abba = r'(\w)(\w)\2\1'

    count = 0

    for l in lines:
        outside_matches = re.findall(outside, l) + re.findall(end, l)
        inside_matches = re.findall(inside, l)

        inside_abba_matches = [re.findall(abba, x) for x in inside_matches if x]
        filtered_inside_abba_matches = [x[0] for x in inside_abba_matches if x and x[0][0] != x[0][1]]
        outside_abba_matches = [re.findall(abba, x) for x in outside_matches if x]
        filtered_outside_abba_matches = [x[0] for x in outside_abba_matches if x and x[0][0] != x[0][1]]

        if not filtered_inside_abba_matches and filtered_outside_abba_matches:
            count += 1

    print(count)


def part2():
    f = open('input.txt')
    lines = [l.strip() for l in f.readlines()]

    outside = r'(\w+)\['
    end = r'\](\w+)'
    inside = r'\[(\w+)\]'
    aba = r'(\w)(\w)\1'

    count = 0

    for l in lines:
        outside_matches = re.findall(outside, l) + re.findall(end, l)
        inside_matches = re.findall(inside, l)

        outside_aba_matches = [re.findall(aba, x, overlapped=True) for x in outside_matches if x]
        flat_outside_aba_matches = [item for sublist in outside_aba_matches for item in sublist]
        filtered_outside_aba_matches = [x for x in flat_outside_aba_matches if x and x[0] != x[1]]

        if not filtered_outside_aba_matches:
            continue

        bab = [x[1] + x[0] + x[1] for x in filtered_outside_aba_matches]

        print(filtered_outside_aba_matches)
        print(bab)
        print(inside_matches)
        print()

        for pattern in bab:

            should_continue = True
            for hypernet in inside_matches:
                if pattern in hypernet:
                    # print(pattern, hypernet, pattern in hypernet)
                    count += 1
                    should_continue = False
                    break

            if not should_continue:
                break


    print(count)

if __name__ == '__main__':
    part1()
    part2()
