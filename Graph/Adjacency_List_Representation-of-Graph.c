// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph
{
	int V;
	struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode =
	(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
	struct Graph* graph =
		(struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists. Size of
	// array will be V
	graph->array =
	(struct AdjList*) malloc(V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by
	// making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected, add an edge from
	// dest to src also
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n\t\t\t Adjacency list of vertex %d \n\t\t\t head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

// Driver program to test above functions
int main()
{
  	// create the graph given in above fugure
	int v;
    int edge,src,dest;
    printf("\n Enter the number of vertices present in Undirected Graph: ");
    scanf("%d",&v);
    struct Graph *graph=createGraph(v);
    printf("\n Enter the Noumber of Edges prsent in Undirected Graph: ");
    scanf("%d",&edge);
    for(int i=1;i<=edge;i++) //Because of in undirected graph edge is connected to both side.
    {
        printf("\n Enter the Source and Dest for '%d' Edge: ",i);
        scanf("%d %d",&src,&dest);
        addEdge(graph,src,dest);
    }

	// print the adjacency list representation of the above graph
	printGraph(graph);

	getch();
}
