def calculate_sum(stack):
	temp = 0
	sum1 = 0
	m = 0
	if len(stack) == 0:
		m = 1

	while(m == 0):
		i = len(stack) - 1
		if stack[i] == '(':
			sum1 -= temp
			operand = temp
			stack.pop()
			sum2 = calculate_sum(stack)
			sum1 += operand * sum2

		elif stack[i] == ')':
			stack.pop()
			return sum1

		else:
			temp = int(stack.pop())
			sum1 += temp

		if len(stack) == 0:
			break

	return sum1



exp = input()
stack = []

for c in exp:
	stack.append(c)

stack = stack[::-1]

print(calculate_sum(stack))
