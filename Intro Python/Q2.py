
def cells_in_row_are_full(table, i):
	for r in range(n):
		if table[i-1][r] == 0:
			return False
	return True


def cells_in_col_are_full(table, j):
	for r in range(n):
		if table[r][j-1] == 0:
			return False
	return True

def check_for_duplicate(this_list, num):
	for element in this_list:
		if num == element:
			return

	this_list.append(num)

n = int(input())
table = []
filled_cols = []
filled_rows = []
for i in range(n):
	a=[]
	for j in range(n):
		a.append(0)
	table.append(a)

lovely = False
always_hideos = False
for x in range(0,n**2):
	i,j = input().split(" ")
	i = int(i)
	j = int(j)
	table[i-1][j-1] = 1
	check_for_duplicate(filled_rows, i)
	check_for_duplicate(filled_cols, j)

	empty = False
	if always_hideos == False:
		if (cells_in_row_are_full(table, i)):
			print("HIDEOUS")
			if lovely == True:
				always_hideos = True
			continue

		elif (cells_in_col_are_full(table, j)):
			print("HIDEOUS")
			if lovely == True:
				always_hideos = True
			continue

		elif len(filled_cols) == n and len(filled_rows) == n:
			lovely = True
			print("LOVELY")

		else:
			print("HIDEOUS")

	else:
		print("HIDEOUS")


