#include <iostream>
#include "Morse_Tree.h"

using namespace std;

int main() {
	ifstream morseFile("morse.txt");
	Morse_Tree mTree(morseFile);

	cout << mTree.decode("._ ._.. . _._.") << " and " << mTree.decode(mTree.encode("kory")) << endl;

	cout << mTree.encode("abcdefghijklmnopqrstuvwxyz") << endl;
	cout << mTree.decode(mTree.encode("abcdefghijklmnopqrstuvwxyz"));
	cin.get();

	return 0;
}
