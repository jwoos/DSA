f = open('wordlist.txt', 'r')

words = [
    'mkeart',
    'sleewa',
    'edcudls',
    'iragoge',
    'usrlsle',
    'nalraoci',
    'nsdeuto',
    'amrhat',
    'inknsy',
    'iferkna'
]

word_list = f.read().split('\n')

solution = {}

for word in words:
    for check in word_list:
        if sorted(word) == sorted(check):
            solution[word] = check

for key in solution:
    print('%s is %s' % (key, solution[key]))
