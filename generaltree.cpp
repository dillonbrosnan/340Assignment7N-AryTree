#include "generaltree.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <exception>

using namespace std;

GeneralTree::GeneralTree() : start(NULL){
	
}
Node :: Node(): value(NULL), child(NULL), sibling(NULL){
//general constructor for Node class
//each bide has a value, a child pointer, to its first child node, and a pointer
//to its first sibling node
}
//copy constructor for a GeneralTree
GeneralTree::	GeneralTree(const GeneralTree&other) :start(NULL){
	copyFrom(other.start, this->start);
}
//Destructor for General Tree
GeneralTree:: ~GeneralTree(){
	clear();
}
//overloading = operator for use on General Tree
GeneralTree& GeneralTree::operator=(const GeneralTree& other){
	if(this != &other){
		clear();
		copyFrom(other.start, this -> start);
	}
	return *this;
}
/*method to insert a new node into the tree
takes the value of the node to be inserted 
(val) and its parent Node*/
Node* GeneralTree:: insert(char val, Node* parent){
	Node* temp = new Node();//create new Node
	try{
		/*calls true insert method, this is only to catch exceptions
		thrown when a node is inserted as the starting node when one already 
		exists*/
		temp = insert2(val, parent);
	}catch(const TreeException& e){
		cout << e.what() << endl;
		delete temp;
		Node* temp = insert2(val, start);
	}return temp;
}
/*true insert method
if the parent of the node to be inserted is null, but start node already exists,
this method throws an exception*/
Node* GeneralTree::insert2(char val, Node* parent){
	Node* temp = new Node();//create new node and set value
	temp -> value = val;
	temp -> par = parent;
	if(parent == NULL && start != NULL){//check if we need to throw exception
		delete temp;//if so, delete temp
		throw TreeException();//throw exception
		Node* temp = insert(val, start);//inserts as a sibling of start node
	}
	if(start == NULL){//if the start of the tree == null, insert node into 
		start = temp;//start point
		//cout << start -> value << " pushed into start position" << endl;
		return start;
	}
	if(parent -> child == NULL){//if the parent has no children, insert
		parent -> child = temp;//node as first child of the parent node
		//cout << parent -> child -> value << " pushed into child of " << parent -> value << endl;
		return parent -> child;
	}
	pushFrom(parent -> child, temp);//else, push into the last sibling spot
	return temp;//of the parents node's children
}
void GeneralTree:: print() const{
	printFrom(start); 
	cout << endl;
}

void GeneralTree:: clear(){
	clearFrom(start);
	start = NULL;
}
void GeneralTree::pushFrom(Node* chi, Node* sib){
	if(chi -> sibling == NULL){//base case
		chi -> sibling = sib;
		//cout << chi -> sibling -> value << " Pushed into sibling of " << chi -> value << endl;
	}else{
		pushFrom(chi->sibling, sib);//recursive call untill there the sibling is
		//null, then insert node as sibling
	}
	
	
	
}void GeneralTree::printFrom(Node* star) const{//print method
	if(star == NULL){
		return;
	}if(star -> child != NULL){
		cout << "(";
		if(std::isalpha(star -> value)){
			cout << star -> value;
		}
		//count++;
	}else{
		cout << star -> value;
	}
	printFrom(star -> child);
	printFrom(star -> sibling);
	if(star -> sibling == NULL && star != start){
		cout << ")";
	}
}void GeneralTree :: copyFrom(Node* star, Node* parent){
	if(star == NULL){
		return;
	}
	Node* temp = insert(star -> value, parent);
	copyFrom(star-> sibling, temp -> par);
	copyFrom(star-> child, temp);
}
void GeneralTree::clearFrom(Node* star){
	if(star == NULL){
		return;
	}
	clearFrom(star->sibling);
	clearFrom(star -> child);
	delete star;
}

