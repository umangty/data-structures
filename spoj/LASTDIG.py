n = int(raw_input())
while n>0:
	n=n-1
	a,b = map(int, raw_input().split())
	print pow(a,b,10)