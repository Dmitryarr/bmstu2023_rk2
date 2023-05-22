#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

struct Node {
	Node();
	Node(int nameNode);
	~Node();
	Node* parent;
	std::list<Node*> listChilds;
	int name;
	static int countNodes;
};

class Graph {
private:
	Node* head;
	int buildTreeBFS_recursion(int countNodes);
public:
	Graph();
	Graph(int countNodes);
	~Graph();
	int buildTreeBFS(int countNodes);
	void BFS();
	std::pair<bool, std::list<int>> searchBFS(int nameNode);
};

