#!/usr/bin/env python3

import hashlib

def part1():
    door = 'ojvtpuvg'
    password = ''
    index = 0
    password_index = 0

    while True:
        md = hashlib.md5()
        md.update((door + str(index)).encode('utf-8'))

        digest = md.hexdigest()
        if digest[0:5] == '00000':
            password = password[:password_index] + digest[5]
            password_index += 1

            if password_index == 8:
                break

        index += 1

    print(password)

def part2():
    door = 'ojvtpuvg'
    password = [''] * 8
    index = 0

    while True:
        md = hashlib.md5()
        md.update((door + str(index)).encode('utf-8'))

        digest = md.hexdigest()
        if digest[0:5] == '00000':
            pos = int(digest[5], 16)

            if pos <= 7 and not password[pos]:
                password[pos] = digest[6]

                done = True
                for c in password:
                    if not c:
                        done = False

                if done:
                    break

        index += 1

    print(''.join(password))

if __name__ == '__main__':
    # part1()
    part2()
