def main():
    name = input('Please enter your name: ')
    age = input('Please enter your age: ')
    username = input('Please enter your username: ')
    
    sentence = 'Your name is %s, you are %s, and your username is %s' % (name, age, username)
    print(sentence)
    
    file = 'log.txt'
    f = open(file, 'w')
    
    f.write(sentence + '\n')

if __name__ == '__main__':
    main()