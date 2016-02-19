n = int(raw_input())
while n>0:
	n=n-1
	a,b=map(int, raw_input().split())
	if a == b:
		if a%2==0:
			print 2*a
		else:
			print 2*a-1

	elif b+2==a:
		if b%2==0:
			print 2*b+2
		else:
			print 2*b+1
	else:
		print 'No Number'		

