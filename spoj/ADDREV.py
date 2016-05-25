n = int(raw_input())
while n>0:
	n = n - 1
	li = raw_input().split()
	a1 = li[0][::-1]
	a2 = li[1][::-1]
	s = int(a1) + int(a2)
	res = str(s)[::-1]
	print int(res)
 