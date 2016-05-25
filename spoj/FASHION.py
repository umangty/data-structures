n = int(raw_input())

while n>0:
	n=n-1
	l = int(raw_input())
	
	a = map(int, raw_input().split())
	b = map(int, raw_input().split())
	a.sort()
	b.sort()
	res = 0
	for i in range(l):
		res = res + a[i]*b[i]

	print res 