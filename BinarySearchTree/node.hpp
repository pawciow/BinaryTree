#pragma once

#include <initializer_list>
#include <memory>
#include <cstddef>
#include <iostream>

template <typename T> class Node
{
public:
	Node() = default;
	Node(T value);
	using NodePtr = std::unique_ptr< Node<T> >;
	bool isChildInitialized(const std::unique_ptr < Node<T> >& checkingChild) const;
	void addChild(T value);
	void printValue() const;
	T getValue() { return _value; }
	NodePtr & getRightChild();
	NodePtr & getLeftChild();
	~Node() = default;
protected:
	T _value;
	NodePtr _parent;
	NodePtr _leftChild;
	NodePtr _rightChild;
};

template <typename T>
Node<T>::Node(T value) : _value(value) {}

template <typename T>
std::unique_ptr< Node<T> > & Node<T>::getLeftChild()
{
	return _leftChild;
}

template <typename T>
std::unique_ptr< Node<T> > & Node<T>::getRightChild()
{
	return _rightChild;
}

template <typename T>
void Node<T>::addChild(T value)
{
	if (_value > value)
	{
		if (isChildInitialized(_leftChild))
			_leftChild->addChild(value);
		else
			_leftChild = std::make_unique<Node<T>>(value);
	}
	else
	{
		if (isChildInitialized(_rightChild))
			_rightChild->addChild(value);
		else
			_rightChild = std::make_unique<Node<T>>(value);
	}
}
template<typename T>
bool Node<T>::isChildInitialized(const std::unique_ptr < Node<T> > & checkingChild) const
{
	return checkingChild.operator bool();
}

template<typename T>
void Node<T>::printValue() const
{
	std::cout << _value << ::std::endl;
}

