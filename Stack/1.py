def find_max_for(inputs):
	n = len(inputs)
	line = []
	line.append(-1)
	code = []

	for_counter = 0
	max_for = 0
	s = 0
	e = 0
	start = 0
	end = 0
	for i in range(n):
		if inputs[i] == "For" or inputs[i] == "While":
			code.append(inputs[i][0])
			line.append(i)

		elif inputs[i] == "Endwhile":
			if len(line) != 0:
				e = line.pop()
				if len(line) == 0:
					for_counter = 0
					line.append(i)

			if len(code) == 0:
				continue

			c = code.pop()
			if c == 'F':
				s = line.pop()
				code.clear()
				line.clear()
				if max_for < for_counter:
					max_for = for_counter
					start = s + 1
					end = e

				for_counter = 0
				line.append(i)

			else:
				if max_for <= for_counter:
					max_for = for_counter
					start = line[len(line)-1] + 1
					end = i + 1


		elif inputs[i] == "Endfor":
			if len(line) != 0:
				e = line.pop()
				if len(line) == 0:
					for_counter = 0
					line.append(i)

			if len(code) == 0:
				continue

			c = code.pop()
			if c == 'W':
				s = line.pop()
				code.clear()
				line.clear()
				if max_for < for_counter:
					max_for = for_counter
					start = s + 1
					end = e

				for_counter = 0
				line.append(i)

			else:
				for_counter += 1
				if max_for <= for_counter:
					max_for = for_counter
					start = line[len(line)-1] + 1
					end = i + 1

		else:
			dummy = i



	counter = 0
	for x in range(start,end):
		if inputs[x] == "For":
			counter += 1

	if counter != max_for:
		while len(line) > 2:
			line.pop()

		if(len(line) >= 2):
			end = line.pop()
			start = line.pop() + 1

		counter = 0
		for y in range(start,end):
			if inputs[y] == "For":
				counter += 1

		max_for = counter


	print(max_for," ",start," ",end)










n = int(input())
inputs = []
for i in range(n):
	each_line = input()
	inputs.append(each_line)

find_max_for(inputs)

