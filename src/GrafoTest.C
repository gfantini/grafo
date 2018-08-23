#include <iostream>
#include <string>
#include <vector>

using namespace std;
// this is a comment line

class Node{
public:
  Node(string name);
  string GetName();
private:
  string fName;
};

Node::Node(string name)
{
  cout << "You called the Node constructor." << endl;
  cout << "fName set to " << name << endl;
  fName = name;
};

string Node::GetName(){
  return fName;
}


class Edge{
public:
  Edge(Node* node1,Node* node2);
  Node* GetNode1();
  Node* GetNode2();
private:
  Node* fNode1;
  Node* fNode2;
};

Edge::Edge(Node* node1,Node* node2)
{
  cout << "You called the Edge constructor." << endl;
  cout << "This will create and Edge between node " << node1->GetName() << " and node " << node2->GetName() << endl;
  fNode1 = node1;
  fNode2 = node2;
};

Node* Edge::GetNode1(){
  return fNode1;
}
Node* Edge::GetNode2(){
  return fNode2;
}


class Graph{
public:
  Graph(); // this is the constructor
  void AddNode(Node* newNode);
  void AddEdge(Edge* newEdge);
  void PrintNodes();
  void PrintEdges();
private:
  bool fValid;
  vector<Node*> fNode;
  vector<Edge*> fEdge;
};

Graph::Graph(){
  cout << "You called the Graph constructor." << endl;
  cout << "This will set fValid = false." << endl;
  cout << "Please add a Node to build a valid Graph" << endl;
  fValid = false;
}

void Graph::AddNode(Node* newNode)
{
  // FIXME: add sanity check
  fNode.push_back(newNode);
}

void Graph::AddEdge(Edge* newEdge)
{
  bool FoundNode1 = false;
  bool FoundNode2 = false;
  // 1. controlla che i node dell'edge siano dentro il graph
  for(int i=0; i < fNode.size(); i++)
    {
      if( fNode[i] == newEdge->GetNode1() )FoundNode1 = true;
      if( fNode[i] == newEdge->GetNode2() )FoundNode2 = true;
    }
  // 2. se non lo sono? -> dai errore
  if( FoundNode1 == false || FoundNode2 == false){
    cout << "WARNING! Trying to add egde between one or more nodes not belonging to graph!" << endl;
    if( FoundNode1 == false){
      AddNode( newEdge->GetNode1() );
      cout << "Node " << newEdge->GetNode1()->GetName() << " automatically added to graph." << endl;
    }
    if( FoundNode2 == false){
      AddNode( newEdge->GetNode2() );
      cout << "Node " << newEdge->GetNode2()->GetName()<< " automatically added to graph." << endl;
    }
  }
  //3. aggiungi Edge al Graph
  fEdge.push_back(newEdge);
}

void Graph::PrintNodes(){
  cout << "[PrintNodes] Will print the list of nodes of the graph." << endl;
  for(int i=0; i<fNode.size(); i++){
    cout << "Node " << i << ": \t" << fNode[i]->GetName() << endl;
  }
  cout << "[PrintNodes] ---------------------------------------------" << endl;
}

void Graph::PrintEdges(){
  for(int i=0; i<fEdge.size(); i++){
    cout << "Edge" << i << ": \t "<< fEdge[i]->GetNode1()->GetName() << " <-> " << fEdge[i]->GetNode2()->GetName() << endl;
  }
  cout << "[PrintEdges] -----------------------------------------" << endl;
}

int main(int argc, char* argv[])
{
 
  Graph* Grafo = new Graph(); // this is a pointer-to-Graph object
 
  Node* casa = new Node("casa");
  Node* Carrefour = new Node("Carrefour");
  Node* Conad = new Node("Conad");
  Node* Tabaccaio = new Node("Tabaccaio");
  Node* Parco = new Node("Parco");
  Node* Guido = new Node("Guido");

  Edge* casaGuido = new Edge(casa,Guido);
  Edge* casaTabaccaio = new Edge(casa,Tabaccaio);
  Edge* casaCarrefour = new Edge(casa,Carrefour);
  Edge* casaConad = new Edge(casa,Conad);
  
  Edge* CarrefourGuido = new Edge(Carrefour,Guido);
  
  Edge* ConadTabaccaio = new Edge(Conad,Tabaccaio);
  
  Edge* TabaccaioParco = new Edge(Tabaccaio,Parco);
  
  Grafo->AddNode( casa );
  Grafo->AddNode( Carrefour );
  Grafo->AddNode( Conad );
  Grafo->AddNode( Tabaccaio );
  Grafo->AddNode( Parco );
  Grafo->AddNode( Guido );
 
  Grafo->AddEdge( casaGuido );
  Grafo->AddEdge( casaTabaccaio );
  Grafo->AddEdge( casaCarrefour );
  Grafo->AddEdge( casaConad );
  Grafo->AddEdge( CarrefourGuido );
  Grafo->AddEdge( ConadTabaccaio);
  Grafo->AddEdge( TabaccaioParco );

  Grafo->PrintNodes();
  Grafo->PrintEdges();
  
  

  return 0;
}
