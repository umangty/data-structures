graph = {
	"s" : ["a", "b"],
	"a" : ["s", "c"],
	"b" : ["s", "c", "d"],
	"c" : ["a", "b", "d", "e"],
	"d" : ["b", "c", "e"],
	"e" : ["c", "d"]
}

# print graph
# for node in graph:
# 	print node
# 	print graph[node]

# keeps track of whether nodes in the graphs are visited or not
explored = {
	"s" : False,
	"a" : False,
	"b" : False,
	"c" : False,
	"d" : False,
	"e" : False,
}

#computes shortest distance from source vertex, s
#initialize dist[s] = 0 and rest of the distances to -inf.
dist = {
	"s" : 0,
	"a" : -1,
	"b" : -1,
	"c" : -1,
	"d" : -1,
	"e" : -1,
} 

# def BFS(graph, start_vertex):
# 	explored[start_vertex] = True
# 	li = [start_vertex]
# 	while li != []:
# 		v = li.pop(0) #Queue data structure needed. 
#  		for vertex in graph[v]:
# 			if explored[vertex]==False:
# 				explored[vertex] = True
# 				li.append(vertex)
# BFS(graph, "b")
# print explored

def ShortestDistance(graph, start_vertex):
	explored[start_vertex] = True
	li = [start_vertex]
	while li != []:
		v = li.pop(0)
		for vertex in graph[v]:
			if explored[vertex] == False:
				explored[vertex] = True
				dist[vertex]  = dist[v] + 1
				li.append(vertex)
ShortestDistance(graph, "s")
print dist
