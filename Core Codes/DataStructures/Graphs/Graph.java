public class Graph {
	private final int V;		// number of vertices
	private int E;				// number of edges
	private Bag<Integer>[] adj;	// adjacency lists

	public Graph(int V) {
		this.V = V;
		this.E = 0;
		adj = (Bag<Integer>[]) new Bag[V];		// Create array of lists
		for(int v = 0; v < V; v++) {
			adj[v] = new Bag<Integer>();		// Initialize all lists to empty
		}
	}

	public Graph(In in) {
		this(in.readInt());		// Read V and construct this graph.
		int E = in.readInt();	// Read E
		for(int i = 0; i < E; i++) {
			// Add an edge
			int v = in.readInt();	// Read a vertex
			int w = in.readInt();	// read another vertex
			addEdge(v, w);

		}
	}

	public int V() {
		return V;
	}

	public int E() {
		return E;
	}

	public void addEdge(int v, int w) {
		adj[v].add(w);		// add w to v's list
		adj[w].add(v);		// add v to w's list 
		E++;
	}

	public Iterable<Integer> adj(int v) {
		return adj[v];
	}


	// Compute the degree of v
	public static int degree(Graph G, int v) {
		int degree = 0;
		for(int w : G.adj(v)) degree++;
		return degree;
	}

	// Compute maximum degree
	public static int maxDegree(Graph G) {
		int max = 0;
		for(int v = 0; v < G.V(); v++) {
			if(degree(G, v) > max) {
				max = degree(G, v);
			}
		}
		return max;
	}

	// Compute average degree
	public static itn avgDegree(Graph G) {
		return 2 * G.E() / G.V();
	}

	// Count self-loops
	public static int numberOfSelfLoops(Graph G) {
		int count = 0;
		for(int v = 0; v < G.V(); v++) {
			for(int w : G.adj(v)) {
				if(v == w) count++;
			}
		}
		return count / 2;		// each edge counted twice
	}

	// String representation of the graph's adjacency lists
	public String toString() {
		String s = V + " vertices, " + E + " edges\n";
		for(int v = 0; v < V; v++) {
			s += v + ": ";
			for(int w : this.adj(w)) {
				s += w + " ";
			}
			s += "\n";
		}
		return s;
	}
}