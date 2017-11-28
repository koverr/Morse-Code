#include <iostream>
#include "Binary_Search_Tree.h"

using namespace std;

int main() {
	
	ifstream morseFile("morse.txt");

	Binary_Tree<char>* mTree;
	mTree = mTree->create(morseFile);
	
}