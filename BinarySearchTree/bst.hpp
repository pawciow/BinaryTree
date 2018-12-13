#pragma once
#include "node.hpp"
#include <initializer_list>
#include <memory>
#include <cstddef>
#include <iostream>

template <typename T> class BinarySearchTree 
	: private Node<T>
{
public:
	BinarySearchTree(std::initializer_list<T> list);
	using NodePtr = std::unique_ptr< Node<T> >;
	void expandTree(T valueToAdd);

	void walkTree();

//	std::unique_ptr< Node<T> > & treeSearch(T valueToFind);
	std::unique_ptr< Node<T> > & iterativeTreeSearch(T valueToFind);

private:
	NodePtr _root;
	void visitNode(NodePtr &  visitingNode) const;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> list)
{
	for (auto & e : list)
	{
		if (_root)
		{
			_root->addChild(e);
		}
		else
		{
			_root = std::make_unique<Node <T> >(e);
		}
	}
}

template<typename T>
void BinarySearchTree<T>::visitNode(std::unique_ptr< Node<T> > & visitingNode) const
{
	if (visitingNode->getLeftChild())
	{
		visitNode(visitingNode->getLeftChild());
	}

	visitingNode->printValue();

	if (visitingNode->getRightChild())
	{
		visitNode(visitingNode->getRightChild());
	}
}
template <typename T>
void BinarySearchTree<T>::walkTree()
{
	visitNode(_root);
}

template <typename T>
void BinarySearchTree<T>::expandTree(T valueToAdd)
{
	_root->addChild(valueToAdd);
}

template <typename T>
std::unique_ptr< Node<T> > & BinarySearchTree<T>::iterativeTreeSearch(T valueToFind)
{
	const std::unique_ptr< Node<T> > & checkingNode = _root;
	while (checkingNode & checkingNode->getValue() != valueToFind)
	{
		if (checkingNode->getValue() < valueToFind)
		{
			checkingNode = checkingNode->getLeftChild();
		}
		else
		{
			checkingNode = checkingNode->getRightChild();
		}
	}
	return checkingNode;
}
