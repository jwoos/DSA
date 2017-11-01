import random

def number_guess(lower_bound, upper_bound, guesses):
    guess = 0
    while guess in guesses:
        guess = random.randint(lower_bound, upper_bound)
    guesses.append(guess)
    
    print(guess)
    check = input('Is this your number? (y/n) >> ')
    hint = ''
    
    if check.lower() == 'y':
        return None
    elif check.lower() == 'n':
        hint = input('Is it higher or lower? (h/l) >> ')
        
        if hint == 'h':
            return (guess + 1, None) 
        elif hint =='l':
            return (None, guess - 1)

def main():
    solved = False

    guesses = [0]
    
    lower_bound = 1
    upper_bound = 100
    
    tries = 0
    
    while not solved:
        tries += 1
        return_value = number_guess(lower_bound, upper_bound, guesses)
        
        if return_value is None:
            print('It took me %s tries' % tries)
            solved = True
        else:
            if return_value[0] is None:
                upper_bound = return_value[1]
            elif return_value[1] is None:
                lower_bound = return_value[0]
            
if __name__ == '__main__':
    main()