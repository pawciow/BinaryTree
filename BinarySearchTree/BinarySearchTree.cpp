
#include "pch.h"
#include <iostream>
#include <cstdlib>

int main()
{
	BinarySearchTree<int> example = { 150,20,300 };
	for (int i = 0; i < 100; i++)
		example.expandTree(std::rand());
	example.walkTree();
	auto e = example.findNode(300);

	std::cout << "I found this value: " << e->getValue() << "\n";
	std::cout << "Minimal value: " << example.findMinimum()->getValue() << std::endl;
	std::cout << "Maximum value: " << example.findMaximum()->getValue() << std::endl;
}