
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

