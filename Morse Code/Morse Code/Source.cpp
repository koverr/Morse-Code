#include <iostream>
#include "Binary_Search_Tree.h"

using namespace std;

Binary_Tree<char> create(std::ifstream& fin);
string decode(string morse, Binary_Tree<char> mTree);

int main() {

	ifstream morseFile("morse.txt");

	Binary_Tree<char> mTree = create(morseFile);

	cout << decode("._ ....", mTree);
	cin.get();
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

string decode(string morse, Binary_Tree<char> mTree) {
	string::iterator strItr = morse.begin();
	string decoded = "";

	
	while (strItr != morse.end()) {
		BTNode<char>* ptr = mTree.getRoot();
		while (*strItr != ' ' ) {
			if (*strItr == '.')
				ptr = ptr->left;
			else
				ptr = ptr->right;

			if (strItr + 1 != morse.end())
				strItr++;
			else
				break;
		}
		decoded += ptr->data;
		if(strItr != morse.end())
			strItr++;
	}
	return decoded;
}