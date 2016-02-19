while True:
	n = int(raw_input())
	if n==-1:
		break
	
	li = []
	s = 0

	for i in range(n):
		li.append(int(raw_input()))
		s += li[i]

	if s%n!=0:
		print -1
	else:
		av = s/n
		res = 0
		for i in li:
			if i>av:
				res += (i-av)
		print res