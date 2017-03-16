def fact(n):
	if n==0:
		return 1
	else:
		return n*fact(n-1)

n = int(raw_input())
while n>0:
	n = n-1
	num = int(raw_input())
	print fact(num)