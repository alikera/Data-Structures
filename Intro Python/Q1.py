

def count_qmarks(number):
	counter = 0
	for element in number:
		if element == "?":
			counter+=1
	return counter


def remainder_calculator(tens_power):
    q = int(tens_power / 16)
    r = tens_power % 16
    power = 10**r
    if q == 0:
        return power
    else:
        return ((49**q) * power)


bigger_num = input()
smaller_num = input()

smaller_num = str(smaller_num)
bigger_num = str(bigger_num)

sum = 0
counter_qmark = 0
total_qmarks = count_qmarks(smaller_num)

for element in range(0,len(smaller_num)):
    if smaller_num[element] == "?":
        counter_qmark+=1
        sum += (int(bigger_num[element]) * remainder_calculator(total_qmarks-counter_qmark))%100000007
    elif smaller_num[element] > bigger_num[element]:
    	break
    elif smaller_num[element] < bigger_num[element]:
    	sum += (remainder_calculator(total_qmarks-counter_qmark))%100000007
    	break

print(sum%100000007)


