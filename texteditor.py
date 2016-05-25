N = int(raw_input())
s = ""
aux = []
while N>0:
	N = N-1
	inp = raw_input().split(" ")
	op = int(inp[0])
	
	if op==1 :
		s = s + inp[1]
		aux.append(s)


	if op==2 :
		k = int(inp[1])
		li = list(s)
		while k>0:
			li[len(li)-k] = ""
			k = k-1
		s = ''.join(li)	
		aux.append(s)	

	if op==3 :
		print s[int(inp[1])-1]

	if op==4 :
		if '' in aux:
			aux.remove('')
		s = aux.pop()
		#print s

	
	#print aux
#print ''.join(text)
