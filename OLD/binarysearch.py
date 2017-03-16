# n- integer to be found in list li

# Iterative version of Binary Search
def BinarySearch(li, n):
	length = len(li)
	low = 0
	high = length - 1
	while low <= high:
		mid = low + (high-low)/2
		if li[mid] == n:
			return mid
		if n < li[mid]:
			high = mid-1
		if n > li[mid]:
			low = mid+1
	return -1

# Recursive version of Binary Search
# low, high - indices
def BinarySearchRecur(li, n, low, high):
	mid = low + (high-low)/2
	if li[mid] == n:
		return mid
	if n > li[mid]:
		return BinarySearchRecur(li, n, mid+1, high)
	if n < li[mid]:
		return BinarySearchRecur(li, n, low, mid-1)

li = [1, 2 , 3 , 4 , 5]
print BinarySearch(li, 3)
print BinarySearchRecur(li, 5, 0, 4)