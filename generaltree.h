#ifndef _GENERAL_TREE_H
#define _GENERAL_TREE_H

//#include <cstdlib>
#include <vector>
#include <exception>
//using namespace std;
class TreeException : public std :: exception{
	public:
		virtual const char* what() const throw(){
			return "Cannot replace start node with this node.";
		}
};

class Node{
	public:
		Node();
		Node* child;
		Node* sibling;
		Node* par;
		char value;
};
class GeneralTree{
	public:
		GeneralTree();
		GeneralTree(const GeneralTree& other);
		~GeneralTree();
		GeneralTree & operator=(const GeneralTree& other);
		Node* insert(char val, Node* parent);
		void print() const;
	private:
		Node* start;
		Node* insert2(char val, Node* parent);
		void pushFrom(Node* chi, Node*sib);
		void printFrom(Node* star) const;
		void copyFrom(Node* star, Node* parent);
		void clear();
		void clearFrom(Node* star);
		//void copyOther(const GeneralTree& other);
};
#endif

