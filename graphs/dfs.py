graph = {
	"s" : ["a", "b"],
	"a" : ["s", "b", "c"],
	"b" : ["s", "a", "d"],
	"c" : ["a", "d", "e"],
	"d" : ["b", "c", "e"],
	"e" : ["c", "d"],
}

explored = {
	"s" : False,
	"a" : False,
	"b" : False,
	"c" : False,
	"d" : False,
	"e" : False,
}

# iterative version of dfs
def DFS_Iter(graph, start_vertex):
	explored[start_vertex] = True
	li = [start_vertex]
	while li != []:
		v = li.pop()
		for node in graph[v]:
			if explored[node] == False:
				explored[node] = True
				li.append(node)
DFS_Iter(graph, "s")

# recursive version of dfs
# def DFS_Recur(graph, start_vertex):
# 	explored[start_vertex] = True
# 	for node in graph[start_vertex]:
# 		if explored[node] == False:
# 			print node
# 			DFS(graph, node)
# DFS_Recur(graph, "s")

print explored