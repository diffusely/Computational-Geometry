#include <iostream>

#include "sg_tree.h"

int main()
{
	std::vector<int> arr {1, 5, 3, 7, 3, 2, 5, 7};

	SG_tree t(arr, [](int a,int b){ return std::min(a,b); }, 0);

	t.print();
}