#include "tasks_rk2.h"
namespace Global {
	int sizeOld = 1;
	int nameToFind;
	bool check = true;
	std::string str;
}

Node::Node() {
	parent = nullptr;
	name = countNodes;
}
Node::Node(int nameNode) {
	parent = nullptr;
	name = countNodes++;
}
Node::~Node() {
};

int Node::countNodes = 0;
std::queue<Node*> stack;
Node* elToFind = nullptr;

Graph::Graph() {
	head = nullptr;
	std::cout << "    Empty Graph" << std::endl;
}

Graph::Graph(int countNodes) {
	head = nullptr;
	if (countNodes < 0) {
		Global::check = false;
		std::cout << "Graph can`t be constructed" << std::endl;
	}
	if (countNodes >= 0) {
		Global::check = true;
		buildTreeBFS(countNodes);
		Global::sizeOld = 1;
		Node::countNodes = 0;
	}
}

Graph::~Graph() {
	if (head == nullptr)
		return;
	stack.push(head);
	while (!stack.empty()) {
		Node* el;
		el = stack.front();
		std::list<Node*>::iterator it = el->listChilds.begin();
		while (it != el->listChilds.end()) {
			stack.push(*it);
			it++;
		}
		delete el;
		el = nullptr;
		stack.pop();
	}
}

int Graph::buildTreeBFS_recursion(int countNodes) {
	Node* child;
	Node* el = stack.front();
	if (countNodes == 1) {
		while (!stack.empty()) {
			child = new Node(countNodes);
			child->parent = el;
			el->listChilds.push_back(child);
			stack.pop();
			if (!stack.empty())
				el = stack.front();
		}
		return Node::countNodes;
	}
	for (int i = 0; i < countNodes; i++) {
		child = new Node(countNodes);
		child->parent = el;
		el->listChilds.push_back(child);
		stack.push(child);
	}
	stack.pop();
	if (stack.size() == Global::sizeOld) {
		Global::sizeOld *= countNodes - 1;
		buildTreeBFS_recursion(countNodes - 1);
	}
	else {
		buildTreeBFS_recursion(countNodes);
	}
	return Node::countNodes;
}

int Graph::buildTreeBFS(int countNodes) {
	Global::sizeOld = countNodes;
	Node* Tree = new Node(countNodes);
	int ans = 0;
	if (countNodes > 0) {
		stack.push(Tree);
		ans = buildTreeBFS_recursion(countNodes);
	}
	head = Tree;
	head->parent = nullptr;
	return ans;
}

void Graph::BFS() {
	if (Global::check == false)
		return;
	Node* el = head;
	stack.push(el);
	if (head->listChilds.empty()) {
		FILE* fLog = fopen("bfs_res.txt", "a");
		fprintf(fLog, "%s\n\n", (std::to_string(el->name)).c_str());
		fclose(fLog);
		stack.pop();
		return;
	}
	while (!stack.empty()) {
		Node* el;
		el = stack.front();
		if (el->listChilds.empty()) {
			stack = {};
			break;
		}
		std::string s;
		s += std::to_string(el->name) + "{";
		for (std::list<Node*>::iterator it = el->listChilds.begin(); it != el->listChilds.end(); it++) {
			stack.push(*it);
			s += std::to_string((*it)->name) + ",";
		}
		s[s.length() - 1] = '}';
		s += "\n";
		Global::str += s;
		stack.pop();
	}
	FILE* fLog = fopen("bfs_res.txt", "a");
	fprintf(fLog, "%s\n", Global::str.c_str());
	fclose(fLog);
	Global::str = "";
}

std::pair<bool, std::list<int>> Graph::searchBFS(int nameNode) {
	std::pair<bool, std::list<int>> ans;
	if (head == nullptr || nameNode < 0) {
		ans.first = false;
		return std::pair<bool, std::list<int>>();
	}
	Global::nameToFind = nameNode;
	Node* _head = head;
	stack.push(_head);
	while (!stack.empty()) {
		Node* el;
		el = stack.front();
		if (el->name == Global::nameToFind) {
			stack = {};
			elToFind = el;
			break;
		}
		std::list<Node*>::iterator it = el->listChilds.begin();
		while (it != el->listChilds.end()) {
			stack.push(*it);
			it++;
		}
		stack.pop();
	}
	if (elToFind == nullptr) {
		ans.first = false;
		return std::pair<bool, std::list<int>>();
	}
	std::list<int> parents;
	while (elToFind->parent != nullptr) {
		elToFind = elToFind->parent;
		int name = elToFind->name;
		parents.push_back(name);
	}
	elToFind = nullptr;
	ans.first = true;
	ans.second = parents;
	return ans;
}