#include <iostream>
#include "Binary_Search_Tree.h"

using namespace std;

Binary_Tree<char> create(std::ifstream& fin);

int main() {

	ifstream morseFile("morse.txt");

	Binary_Tree<char>* mTree;
	mTree = mTree->create(morseFile);

}

Binary_Tree<char> create(std::ifstream& fin) {
	char letter;
	string morse;
	map<char, string> mMap;
	Binary_Tree<char> mTree;
	BTNode<char>* root;
	BTNode<char>* ptr;
	string::iterator iter;

	root = new BTNode<char>(' ');
	mTree.setRoot(root);

	while (!fin.eof()) {
		ptr = root;
		fin >> letter;
		getline(fin, morse);
		mMap[letter] = morse;

		iter = morse.begin();
		while (iter != morse.end()) {
			if (*iter == '.') {
				if (ptr->left == NULL)
					ptr->left = new BTNode<char>(' ');
				ptr = ptr->left;
			}
			else {
				if (ptr->right == NULL)
					ptr->right = new BTNode<char>(' ');
				ptr = ptr->right;
			}
			iter++;
		}
		ptr->data = letter;
	}
	return mTree;
}