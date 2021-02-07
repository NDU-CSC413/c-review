
#include <iostream>
/* Make the Container class
* moveable but copyable
*
*/

class Container {
	int _size;
	int* _data=nullptr;
public:
	Container(int size) :_size(size), _data(new int[size] {}) {}
	int& operator[](int idx) {
		return _data[idx];
	}
	void resize(int newsize) {
		if (newsize <= _size)return;
		int* tmp = new int[newsize]();//initialize with 0
		for (int i = 0; i < _size; ++i)
			tmp[i] = _data[i];
		_size = newsize;
		delete[] _data;
		_data = tmp;
	}
	Container(const Container& rhs) = delete;
	Container& operator=(Container& rhs) = delete;

	Container(Container&& rhs) noexcept{
		_size = rhs._size;
		_data = rhs._data;
		rhs._size = 0;
		rhs._data = nullptr;
	}
	Container& operator=(Container&& rhs) noexcept  {
		if (_data != nullptr)
			delete[] _data;
		_size = rhs._size;
		_data = rhs._data;
		rhs._size = 0;
		rhs._data = nullptr;
		return *this;
	}
	int size() {
		return _size;
	}
	~Container() {
		if (_data != nullptr)
			delete[] _data;
	}
};

int main()
{
	
	const int n = 8;
	/* create a container of size n */
	Container c(n);
	/* initial values */
	for (int i = 0; i < c.size(); ++i)std::cout << c[i] << ",";
	std::cout << "\n";
	/* change the initial values */
	for (int i = 0; i < c.size(); ++i)c[i] = i;
	/* resize */
	c.resize(12);
	
	/* use move ctor d of c */
	Container d = std::move(c);//move ctor
	if(c.size()>0)
		std::cout << "c[0]=" << c[0] << "\n";
	for (int i = 0; i < d.size(); ++i)
		std::cout<<d[i]<<",";
	std::cout << "\n";
	c = std::move(d);


}

