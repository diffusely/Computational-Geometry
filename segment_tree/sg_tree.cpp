#include "sg_tree.h"

SG_tree::SG_tree(const std::vector<int> &vec, std::function<int(int, int)> f, int defVal)
	: _tree(vec)
	, _foo(f)
	, _defVal(defVal)
{
	// Only use even number
	_tree.assign(2 * vec.size(), _defVal);
	construct(vec);
}

int SG_tree::query(int left, int right)
{
	int n = _tree.size() / 2;
	int res = _defVal;

	left = _tree.size() - left - 1;
	right = _tree.size() - right - 1;

	while (left >= right)
	{
		if (right % 2 == 1)
		{
			res = _foo(res, _tree[right]);
			++right;
		}
		if (left % 2 == 0)
		{
			res = _foo(res, _tree[left]);
			--left;
		}
		left /= 2;
		right /= 2;
	}

	return res;
}

void SG_tree::update(int pos, int val)
{
	int i = _tree.size() - pos - 1;
	_tree[i] = val;

	while (i > 1)
	{
		i /=  2;
		_tree[i] = _foo(_tree[i * 2], _tree[i * 2 + 1]);
	}
}

void SG_tree::print() const
{
	for (size_t i = 0; i < _tree.size(); i++)
		std::cout << _tree[i] << " ";
	std::cout << "\n";
}

void SG_tree::set_function(const std::vector<int> &vec,
	std::function<int(int, int)> f, int def)
{
	_foo = f;
	_defVal = def;
	construct(vec);
}

void SG_tree::construct(const std::vector<int>& vec)
{
	int size = vec.size();
	int n = _tree.size();

	for (int i = n - 1; i >= size; i--)
		_tree[i] = vec[n - i - 1];

	for (int i = size - 1; i > 0; i--)
		_tree[i] = _foo(_tree[i * 2], _tree[i * 2 + 1]);
}
