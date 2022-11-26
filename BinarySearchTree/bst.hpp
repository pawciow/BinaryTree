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
	using NodePtr = std::shared_ptr< Node<T> >;
	void expandTree(T valueToAdd);

	void walkTree();
	NodePtr findNode(T valueToFind);
	NodePtr findMinimum();
	NodePtr findMaximum();

private:
	NodePtr _root;

	void visitNode(NodePtr &  visitingNode) const;
	NodePtr treeSearch(NodePtr & checkingNode, T valueToFind);
	NodePtr iterativeTreeSearch(T valueToFind);

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
			_root = std::make_shared<Node <T> >(e);
		}
	}
}

template <typename T>
void BinarySearchTree<T>::expandTree(T valueToAdd)
{
	_root->addChild(valueToAdd);
}

template<typename T>
void BinarySearchTree<T>::visitNode(std::shared_ptr< Node<T> > & visitingNode) const
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
std::shared_ptr<Node<T> > BinarySearchTree<T>::findNode(T valueToFind)
{
	// return treeSearch(_root, valueToFind);
	return iterativeTreeSearch(valueToFind);
}

template <typename T>
std::shared_ptr< Node<T> > BinarySearchTree<T>::treeSearch(std::shared_ptr< Node<T> > & checkingNode,T valueToFind)
{
	if (!checkingNode || checkingNode->getValue() == valueToFind)
		return checkingNode;

	if (valueToFind < checkingNode->getValue())
		return treeSearch(checkingNode->getLeftChild(), valueToFind);
	else
		return  treeSearch(checkingNode->getRightChild(), valueToFind);
}



template <typename T>
std::shared_ptr< Node<T> > BinarySearchTree<T>::iterativeTreeSearch(T valueToFind)
{
	NodePtr checkingNode = _root;
	while (checkingNode && checkingNode->getValue() != valueToFind)
	{
		if (valueToFind < checkingNode->getValue())
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

template<typename T>
std::shared_ptr< Node<T> > BinarySearchTree<T>::findMinimum()
{
	NodePtr minimum = _root;
	while (minimum->getLeftChild())
	{
		minimum = minimum->getLeftChild();
	}
	return minimum;
}

template<typename T>
std::shared_ptr< Node<T> > BinarySearchTree<T>::findMaximum()
{
	NodePtr minimum = _root;
	while (minimum->getRightChild())
	{
		minimum = minimum->getRightChild();
	}
	return minimum;
}