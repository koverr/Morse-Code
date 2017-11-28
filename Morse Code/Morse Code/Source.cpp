#include <iostream>
#include "Binary_Tree.h"

using namespace std;

Binary_Tree<char> create(std::ifstream& fin, map<char, string>& mMap);
string decode(string morse, Binary_Tree<char> mTree);
string encode(string chars, map<char, string> mMap);

int main() {

	ifstream morseFile("morse.txt");
	map<char, string> mMap;
	Binary_Tree<char> mTree = create(morseFile, mMap);

	cout << decode("._ ._.. . _._.", mTree) << endl;

	cout << decode(encode("abcdefghijklmnopqrstuvwxyz", mMap), mTree);
	cin.get();
}

Binary_Tree<char> create(std::ifstream& fin, map<char, string>& mMap) {
	char letter;
	string morse;
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


// Takes in a string of morse code seperated by spaces and a Morse code Binary Tree and converts the string from
// Morse code to letters
// Complexity: O(n) because it iterates through the string and makes a single pointer traversal for each char in the string
string decode(string morse, Binary_Tree<char> mTree) {
	string::iterator strItr = morse.begin();
	string decoded = "";
	BTNode<char>* ptr;

	
	while (strItr != morse.end()) {			// Keeps converting until the end of the string
		ptr = mTree.getRoot();		// Reset the pointer after every letter is decoded so it starts at the top of the tree
		while (*strItr != ' ' ) {
			if (*strItr == '.')
				ptr = ptr->left;		// If dot then traverse left in the tree
			else
				ptr = ptr->right;		// If underscore then traverse right in the tree

			if (strItr + 1 != morse.end())		// Iterate to next character in string as long as there are more characters to decode
				strItr++;
			else
				break;
		}
		decoded += ptr->data;		// Append the decoded letter to a string
		if(strItr != morse.end())
			strItr++;
	}
	return decoded;		// Return decoded string
}

string encode(string chars, map<char, string> mMap) {
	string morse = "";
	string::iterator iter = chars.begin();

	while (iter != chars.end()) {
		morse += mMap[*iter];
		iter++;
		if (iter != chars.end())
			morse += " ";
	}
	return morse;
}