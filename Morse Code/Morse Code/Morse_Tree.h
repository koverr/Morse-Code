#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#include "MNode.h"
#include <string>
#include <map>
#include <fstream>

using namespace std;


class Morse_Tree
{
public:



	// Constructs a Morse Tree from a file stream
	Morse_Tree(ifstream& fin);
		
	// Decodes a string of morse code 
	string Morse_Tree::decode(string morse);

	// Takes a string of characters and converts it to morse code
	string Morse_Tree::encode(string chars);


private:
	map<char, string> mMap;
	MNode* root;

};
#endif

Morse_Tree::Morse_Tree(ifstream& fin)
{
	/*Takes in an input file, and reads in
	the information needed to complete the morse map and tree
	Time Complexity: O(n)
	-Because the function needs to read through all of the morse strings*/
	char letter;
	string morse;
	MNode* ptr;
	string::iterator iter;

	root = new MNode(' ');		//Makes a new root node and starts the tree
	//mTree.setRoot(root);

	while (!fin.eof()) {			//While the there is still data in the file
		ptr = root;						//Start at the top of the tree
		fin >> letter;
		getline(fin, morse);
		mMap[letter] = morse;			//Map the letter to its morse code

		iter = morse.begin();
		while (iter != morse.end()) {		//Iterate through the morse code to insert the letter into the tree
			if (*iter == '.') {					//If  the morse character is a ., move to the left, make a new 'dead' node if there is nothing there yet
				if (ptr->left == NULL)
					ptr->left = new MNode(' ');
				ptr = ptr->left;
			}
			else {							//Same as above for _
				if (ptr->right == NULL)
					ptr->right = new MNode(' ');
				ptr = ptr->right;
			}
			iter++;
		}
		ptr->data = letter;			//After going throught the entire morse string, set the node that you arrived at to the letter
	}
}

string Morse_Tree::decode(string morse)
{
	string::iterator strItr = morse.begin();
	string decoded = "";
	MNode* ptr;


	while (strItr != morse.end()) {			// Keeps converting until the end of the string
		ptr = root;		// Reset the pointer after every letter is decoded so it starts at the top of the tree
		while (*strItr != ' ') {
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
		if (strItr != morse.end())
			strItr++;
	}
	return decoded;		// Return decoded string
}

string Morse_Tree::encode(string chars)
{
	/*Takes in a string of letters and the morse map to return the morse coded string
	Time Complexity: O(nlogn)
	-Because the function needs to go through the entire string
	of letters to get each morse code*/
	string morse = "";
	string::iterator iter = chars.begin();

	while (iter != chars.end()) {
		morse += mMap[*iter];		//Add each character's morse code to the morse string
		iter++;
		if (iter != chars.end())		//If not done with the letter string, put a space after every code
			morse += " ";
	}
	return morse;				//Return the morse coded string
}
