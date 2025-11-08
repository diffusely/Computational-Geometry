#include <iostream>
#include <limits>

#include "sg_tree.h"

int main()
{
	std::vector<int> arr {1, 5, 3, 7, 3, 2, 5, 7};

	SG_tree t(arr, [](int a,int b){ return a + b; }, 0);

	std::cout << t.query(0, 2) << "\n";

	t.set_function(arr, [](int a,int b){ return std::min(a, b);}, 
									std::numeric_limits<int>::max());

	std::cout << t.query(0, 3) << "\n";

}