
import sys
sys.setrecursionlimit(100000)
def visit_current_island(table, i, j, n, m):
	if (i<0 or j<0 or i>=n or j>=m or table[i][j] == '0'):
		return

	table[i][j] = '0'
	visit_current_island(table,i+1,j,n,m)
	visit_current_island(table,i-1,j,n,m)
	visit_current_island(table,i,j+1,n,m)
	visit_current_island(table,i,j-1,n,m)


n,m = input().split(" ")
n = int(n)
m = int(m)
table = []
flag = 0
num_islands = 0
if(n != 0 and m != 0):
	for i in range(n):
		inputs = list(map(str,input().split()))
		table.append(inputs)

	for i in range(n):
		for j in range(m):
			if table[i][j] == '1':
				visit_current_island(table,i,j,n,m)
				num_islands += 1

print(num_islands)
