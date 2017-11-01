#!/usr/bin/env python3

# There are 256 values possible for an ascii string. We want to check all of them and if we find proper words in between, abort.

import utils
from collections import Counter

a_string = '1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736'
a_byte = utils.hex_string_to_bytes(a_string)

def score(x):
    c = Counter(list(x))

for k in range(256):
    possible.append(''.join(chr(x ^ k) for x in a_bytes))

print(max(possible, key=lambda x: x.count(' ')))
