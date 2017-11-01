#!/usr/bin/env python2

def undo(digest, prev_msg):
    x = 0

    while True:
        # quotient, remainder = divmod((digest ^ prev_msg) + x * 256, 129)
        quotient = ((digest ^ prev_msg) + (x * 256)) // 129
        remainder = ((digest ^ prev_msg) + (x * 256)) % 129

        if remainder == 0:
            print((digest, prev_msg, quotient, remainder))

            break

        x += 1

    return quotient

def answer(digest):
    '''
    digest[i] = ( (129 * message[i]) XOR message[i - 1]) % 256
    1. a = 129 * message[i]
    2. b = message[i - 1]
    3. c = a XOR b
    4. c % 256

    (int list) message = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    (int list) digest = [0, 129, 3, 129, 7, 129, 3, 129, 15, 129, 3, 129, 7, 129, 3, 129]
    =============
    (int list) message = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225]
    (int list) digest = [0, 129, 5, 141, 25, 137, 61, 149, 113, 145, 53, 157, 233, 185, 109, 165]
    '''
    # NOT FINISHED
    raise NotImplementedError()

    message = [
        undo(digest[0], 0)
    ]

    digest.pop(0)

    for i in digest:
        message.append(undo(i, message[-1]))

    print(digest)
    print(message)

    return message

answer([0, 129, 3, 129, 7, 129, 3, 129, 15, 129, 3, 129, 7, 129, 3, 129])
# assert answer([0, 129, 3, 129, 7, 129, 3, 129, 15, 129, 3, 129, 7, 129, 3, 129]) == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
# assert answer([0, 129, 5, 141, 25, 137, 61, 149, 113, 145, 53, 157, 233, 185, 109, 165]) == [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225]
