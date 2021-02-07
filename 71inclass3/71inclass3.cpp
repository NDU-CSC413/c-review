
#include <iostream>
/* create a class Container
* 1. It has a size
* 2. uses a int array for storage
* 3. The array is allocated dynamically by ctor
* 4. Has an index operator
* 5. Has a resize function to INCREASE the size
*    Does NOT decrease the size
* 6. Uses deep copy for copy ctor
*    and operator=
* 7. Allocated array is destroyed byt dtor
*/
template<typename T>
class Container {
	int _size;
	T* _data;
public:
	Container(int size) :_size(size), _data(new T[size]{}) {}
	T& operator[](int idx) {
		return _data[idx];
	}
	Container(const Container& rhs) {
		_size = rhs._size;
		_data = new T[_size];//no point in initializing
		for (int i = 0; i < _size; ++i)
			_data[i] = rhs._data[i];
	}
	Container& operator=(const Container& rhs) {
		/* using = means it already exists */
		delete[] _data;
		_size = rhs._size;
		_data = new T[_size];
		for (int i = 0; i < _size; ++i)
			_data[i] = rhs._data[i];
		return *this;
	}
	void resize(int newsize) {
		if (newsize <= _size)return;
		int* tmp = new T[newsize]();//initialize 
		for (int i = 0; i < _size; ++i)
			tmp[i] = _data[i];
		_size = newsize;
		delete[] _data;
		_data = tmp;
	}
	int size() {
		return _size;
	}
	~Container() {
		delete[] _data;
	}
};
int main()
{
	const int n = 8;
	/* create a container of size n */
	Container<int> c(n);
	/* initial values */
	for (int i = 0; i < c.size(); ++i)std::cout << c[i] << ",";
	std::cout << "\n";
	/* change the initial values */
	for (int i = 0; i < c.size(); ++i)c[i] = i;
	/* resize */
	c.resize(12);
	for (int i = 0; i < c.size(); ++i)std::cout << c[i] << ",";
	std::cout << "\n";
	/* create a copy d of c */
	Container<int> d = c;//copy ctor
	d[0] = 99;
	std::cout << "c[0]=" << c[0] << "\n";
	c = d;
	d[0] = 101;
	std::cout << "c[0]=" << c[0] << "\n";



}

