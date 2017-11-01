def tip_calculator(total, percent_int):
    return int(total) + ((int(total) * int(percent_int)) / 100)


def temperature_conversion(current_temp, current_unit, to_unit):
    conversions = {
    	'f': {
    		'c': f_to_c,
    		'k': f_to_k
    	},
    	'c': {
    		'f': c_to_f,
    		'k': c_to_k
    	},
    	'k': {
    		'c': k_to_c,
    		'f': k_to_f
    	}
    }
    
    return conversions[current_unit][to_unit](current_temp)


def c_to_k(current_temp):
    return current_temp + 273.15


def k_to_c(current_temp):
    return current_temp - 273.15


def f_to_c(current_temp):
    return (current_temp - 32) * 5 / 9


def c_to_f(current_temp):
    return (current_temp * 9 / 5) + 32


def f_to_k(current_temp):
    return f_to_c(current_temp) + 273.15


def k_to_f(current_temp):
    return c_to_f(current_temp - 273.15)


def main():
    choice = input('Tip or temperature?\n')
    if choice.lower() == 'tip':
        total = input('What is the total?\n')
        percent_int = input('What is the tipping rate?\n')
        print(tip_calculator(total, percent_int))
    elif choice.lower() == 'temperature':
        current_temp = float(input('What is the current temperature?\n'))
        current_unit = input('What is the current unit?\n')
        to_unit = input('What unit should it be changed to? \n')
        print(temperature_conversion(current_temp, current_unit, to_unit))

if __name__ == '__main__':
    main()
