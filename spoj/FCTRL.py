n = int(raw_input())
while n>0:
	n = n-1
	num = int(raw_input())/5
	ans = 0
	while num>0:
		ans += num
		num = num/5
	print ans