while True:
	a,b,c = map(int, raw_input().split())
	if (a==0 and b==0 and c==0):
		break
	else:
		if b-a==c-b:
			print 'AP' + ' ' + str(c + (b-a))
		else:
			print 'GP' + ' ' + str(c*c/b) 
