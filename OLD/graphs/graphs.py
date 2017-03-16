graph = {
	"a" : ["c"],
	"b" : ["c", "e"],
	"c" : ["a", "b", "d", "e"],
	"d" : ["c"],
	"e" : ["c", "b"],
	"f" : []
}

# generate the list of all edges
def generate_edges(graph):
	edges = []
	for node in graph:
		for neighbour in graph[node]:
			edges.append((node, neighbour))
	return edges
#print generate_edges(graph)

# find isloated node in a graph
def find_isolated_nodes(graph):
	isloated = []
	for node in graph:
		if not graph[node]:
			isloated += node
	return isloated
#print find_isolated_nodes(graph)

# Representation in terms of python class
class Graph(object):

	#initializes a graph object
	def __init__(self, graph_dict={}):
		self.__graph_dict = graph_dict

	def vertices(self):
		return list(self.__graph_dict.keys())

	def edges(self):
		return self.__generate_edges()

	# __generate_edges -> static method
	def __generate_edges(self):
		edges = []
		for vertex in self.__graph_dict:
			for neighbour in self.__graph_dict[vertex]:
				if {neighbour, vertex} not in edges:
					edges.append({vertex, neighbour})
		return edges

	def add_vertex(self, vertex):
		if vertex not in self.__graph_dict:
			self.__graph_dict[vertex] = []

	def add_edge(self, edge):
		edge = set(edge)
		(vertex1, vertex2) = tuple(edge)
		if vertex1 in self.__graph_dict:
			self.__graph_dict[vertex1].append(vertex2)
		else:
			self.__graph_dict[vertex1] = [vertex2]

	def __str__(self):
		res = "vertices: "
		for k in self.__graph_dict:
			res += str(k) + " "
		for edge in self.__generate_edges():
			res += str(edge) + " "
		return res


if __name__ == "__main__":

    g = { "a" : ["d"],
          "b" : ["c"],
          "c" : ["b", "c", "d", "e"],
          "d" : ["a", "c"],
          "e" : ["c"],
          "f" : []
        }


    graph = Graph(g)

    print("Vertices of graph:")
    print(graph.vertices())

    print("Edges of graph:")
    print(graph.edges())

    print("Add vertex:")
    graph.add_vertex("z")

    print("Vertices of graph:")
    print(graph.vertices())
 
    print("Add an edge:")
    graph.add_edge({"a","z"})
    
    print("Vertices of graph:")
    print(graph.vertices())

    print("Edges of graph:")
    print(graph.edges())

    print('Adding an edge {"x","y"} with new vertices:')
    graph.add_edge({"x","y"})
    print("Vertices of graph:")
    print(graph.vertices())
    print("Edges of graph:")
    print(graph.edges())
  




