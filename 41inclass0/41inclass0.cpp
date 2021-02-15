
#include <iostream>
/* create a class Container 
* 1. It has a size
* 2. uses a int array for storage
* 3. The array is allocated dynamically by ctor
* 4. The array is destroyed by dtor
* 5. Has an index operator
* 6. Has a resize function to INCREASE the size
*    Does NOT decrease the size
* 
*/

struct  Container {
	int _size=0;
	int* _data=nullptr;
	Container() {}
	Container(int size) :_size(size),_data(new int[size]) {}
	Container & operator=(const Container& rhs) {
		_size = rhs._size;
		delete[] _data;
		_data = new int[_size];

		for (int i = 0; i < rhs.size(); ++i)
			_data[i] = rhs._data[i];
		return *this;
	}
	int& operator[](int idx) {
		return _data[idx];
	}
	int size() const {
		return _size;
	}
	~Container() {
		if (_data != nullptr)delete[] _data;
	}
};
#include <string>
int main() {
	Container e;

	std::cout << e._size << "\n";
	//Container n(10);
	//for (int i = 0; i < n.size(); ++i)n[i] = i;
	//Container a(10),b(20);
	//b=(a = n);//b.operator=(a.operator=(n))
	////a._data=n._data;
	//n[0] = 99;
	//std::cout << a[0] << "\n";
	
}


#define INCLASS
#ifndef INCLASS

class Container {
	int _size;
	int* _data;
public:
	Container(int size) :_size(size), _data(new int[size]) {}
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
	int size() {
		return _size;
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
	for (int i = 0; i < c.size(); ++i)std::cout << c[i] << ",";
	std::cout << "\n";
	/* create a copy d of c */
	Container d = c;//copy ctor
	d[0] = 99;
	std::cout << "c[0]=" << c[0] << "\n";


}

#endif // !INCLASS
