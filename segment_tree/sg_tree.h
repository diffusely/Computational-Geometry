#pragma once

#include <iostream>
#include <functional>
#include <vector>


class SG_tree
{
public:
	SG_tree(const std::vector<int>& vec,
			std::function<int(int, int)>,
			int defVal);

	int query(int left, int right);
	void update(int pos, int val);

	void print() const;
	void set_function(const std::vector<int> &vec, 
						std::function<int(int, int)> f, int def);

private:

	std::function<int(int ,int)> _foo;
	std::vector<int> _tree;
	int _defVal;

private:

	void construct(const std::vector<int>& vec);
};
