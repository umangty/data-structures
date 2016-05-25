# for directed acyclic graph only
# wrong

graph = {
	"s" : ["v", "w"],
	"v" : ["x"],
	"w" : ["x"],
	"x" : [],
}

explored = {
	"s" : False,
	"v" : False,
	"w" : False,
	"x" : False,
}

topo = {
	"s" : -1,
	"v" : -1,
	"w" : -1,
	"x" : -1,
}
def dfs_loop(graph):
	
	for node in graph:
		dfs(graph, node)


def dfs(graph, start_vertex):
	current_label = 4
	explored[start_vertex] = True
	for node in graph[start_vertex]:
		if explored[node] == False:
			dfs(graph, node)

	topo[start_vertex] = current_label
	current_label = current_label - 1

dfs_loop(graph)
print topo