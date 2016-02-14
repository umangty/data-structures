# Check if an array has duplicate elements or not.

# python solution
def DuplicateElements(li):
	s = set(li)
	if len(li) != len(s):
		return "Duplicate elements present."
	return "Duplicate elements not present."

# sorting solution. sorting alog used in python O(nlogn)
def DuplicateElementsSort(li):
	li.sort()
	for i in range (0,len(li)-1):
		if li[i]==li[i+1]:
			return "Duplicate elements present."
	return "Duplicate elements not present."		

li1 = [1, 1, 1, 2, 3, 4, 5, 6]
li2 = [1, 2, 3, 4, 5]

print DuplicateElements(li1)
print DuplicateElements(li2)

print "------"

print DuplicateElementsSort(li1)
print DuplicateElementsSort(li2)