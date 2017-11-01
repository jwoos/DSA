from random import SystemRandom

# probably has unconventional characters but oh well
CHARACTER_ARR = [chr(i) for i in range(33, 127)]

amount = int(input('Amount of passwords: '))
length = int(input('Password length: '))

randomizer = SystemRandom()

for _ in range(amount):
    password = ''
    length = length if length else 10

    for _ in range(length):
        password += str(CHARACTER_ARR[randomizer.randrange(len(CHARACTER_ARR))])

    print(password)
