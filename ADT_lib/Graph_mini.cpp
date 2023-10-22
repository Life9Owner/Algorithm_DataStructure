#include<iostream>
using namespace std;
class Graph{
	using Vertex=int;
	using WeightType=int;
	using DataType=char;
	Vertex v1,v2;//vertex
	WeightType weight;//the weight of edge
	void Create();
	void ins_Vertex();
	void ins_Edge();
	void DFS();
	void BFS();
	void shortest_path(Vertex v,int dis[]);
	void MST();//Minimum spanning tree
	void visit(Vertex v);
};
int main()
{
	
}
void Graph::DFS()
{
	
}
void Graph::visit(Vertex v)
{
	cout<<"You are visiting " <<v<<endl;
}