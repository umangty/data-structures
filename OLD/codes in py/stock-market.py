# inefficient. Stack based solution in more efficient. Try
inp = map(int, raw_input().split(" "))
a = len(inp)
ans = []
ans.append(1)
for i in range(1, a):
	j=1
	while(j<=i and inp[i-j]<inp[i]):
		j += 1
	ans.append(j)
print ans

