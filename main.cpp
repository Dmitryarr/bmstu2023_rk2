#include "tasks_rk2.h"
void task_1() {
	std::cout << "    countNodes = 0" << std::endl;
	Graph* graph1 = new Graph(0);
	graph1->BFS();
	std::pair<bool, std::list<int>> a;
	a = graph1->searchBFS(50);
	std::cout << "searchBFS(50)" << std::endl;
	if (a.first == false) {
		std::cout << "Element 50 not found" << std::endl;
	}
	a = graph1->searchBFS(0);
	std::cout << "searchBFS(0)" << std::endl;
	if (a.first == false) {
		std::cout << "Element 0 not found" << std::endl;
	}
	std::cout << std::endl;
	delete graph1;


	std::cout << "    countNodes = -2" << std::endl;
	Graph* graph2 = new Graph(-2);
	graph2->BFS();
	std::pair<bool, std::list<int>> b;
	b = graph2->searchBFS(60);
	if (b.first == false) {
		std::cout << "Element 60 not found" << std::endl;
	}
	std::list<int>::iterator it2 = b.second.begin();
	while (it2 != b.second.end()) {
		std::cout << *it2 << std::endl;
		it2++;
	}
	std::cout << std::endl;
	delete graph2;


	Graph* graph3 = new Graph();
	graph3->buildTreeBFS(-10);
	graph3->BFS();
	std::cout << std::endl;
	delete graph3;


	Graph* graph4 = new Graph(3);
	std::cout << "    countNodes = 2" << std::endl;
	graph4->BFS();
	std::pair<bool, std::list<int>> c;
	c = graph4->searchBFS(70);
	if (c.first == false) {
		std::cout << "Element 70 not found" << std::endl;
	}
	std::list<int>::iterator it4 = c.second.begin();
	while (it4 != c.second.end()) {
		std::cout << *it4 << std::endl;
		it4++;
	}
	std::cout << std::endl;
	delete graph4;


	Graph* graph5 = new Graph(5);
	std::cout << "    countNodes = 5" << std::endl;
	graph5->BFS();
	std::pair<bool, std::list<int>> d;
	d = graph5->searchBFS(80);
	std::cout << "searchBFS(80)" << std::endl;
	if (d.first == false) {
		std::cout << "Element 80 not found" << std::endl;
	}
	std::list<int>::iterator it5 = d.second.begin();
	while (it5 != d.second.end()) {
		std::cout << *it5 << std::endl;
		it5++;
	}
	d = graph5->searchBFS(-80);
	std::cout << "searchBFS(-80)" << std::endl;
	if (d.first == false) {
		std::cout << "Element -80 not found" << std::endl;
	}
	std::cout << std::endl;
	delete graph5;
}

int main()
{
	task_1();
	return 0;
}