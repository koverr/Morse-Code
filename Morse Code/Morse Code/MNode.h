#pragma once

#include <stddef.h>

struct MNode {

	char data;
	MNode* left;
	MNode* right;

	MNode(const char the_data,
		MNode* left_val = NULL,
		MNode* right_val = NULL) :
		data(the_data), left(left_val), right(right_val) {}

};