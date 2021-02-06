	#include <iostream>
	#include <memory>
	#include <thread>
	#include <chrono>

/* uncomment one of the lines below
* to choose the problem
*/
#define PROBLEM1// memory leak
//#define PROBLEM2// double delete

#if defined(PROBLEM1) && defined(PROBLEM2)
#error "cannot define both PROBLEM1 and PROBLEM2"
#endif
using Long = unsigned long long;

void* memory_block(size_t size) {
	return operator new(size);
}
void release_memory(void* p) {
	operator delete(p);
}

struct Leaker {
	int* _values;
	int _size;
	Leaker(Long size) :_size(size) {
		_values = (int*)memory_block(_size * sizeof(int));
	}
	int* values() {
		return _values;
	}
};
struct Double_Delete {
	int* _values;
	int _size;
	Double_Delete(int size) :_size(size) {
		_values = (int*)memory_block(_size * sizeof(int));
	}
	int* values() {
		return _values;
	}
	~Double_Delete() {
		release_memory(_values);
	}
};

struct Unique_Owner {
	std::unique_ptr<int> _values;
	Long _size;
	Unique_Owner(Long size) :_size(size) {
		/* in three steps for clarity */
		void* raw = memory_block(_size * sizeof(int));
		std::unique_ptr<int> q ((int *)raw);
		_values = std::move(q);
		/*q will be destroyed here. It is ok 
		* it holds no resource since it was
		* transfered to p
		*/
	}
	std::unique_ptr<int> values() {
		return std::move(_values);
	}
};
struct Shared_Owner {
	std::shared_ptr<int> _values;
	Long _size;
	Shared_Owner(Long size) :_size(size) {
		/* in three steps for clarity */
		void* raw = memory_block(_size * sizeof(int));
		std::shared_ptr<int> q((int*)raw);
		_values = q;
		/*q will be destroyed here. It is ok
		* it holds no resource since it was
		* transfered to p
		*/
	}
	std::shared_ptr<int> values() {
		return _values;
	}
};
int main()
{

#ifdef PROBLEM1
/* uncomment one of the lines below to activate the fix */
//#define UNIQUE
//#define SHARED

	const unsigned long long n = 1 << 20;
	std::cout << n << "\n";
	for (int i = 0; i < 50; ++i) {
#ifdef UNIQUE
		Unique_Owner x(n);
		std::unique_ptr<int> p = x.values();
		std::this_thread::sleep_for(std::chrono::microseconds(10));
#elif defined(SHARED)
		Shared_Owner x(n);
		std::shared_ptr<int> p = x.values();
		std::this_thread::sleep_for(std::chrono::microseconds(10));
#else
		Leaker x(n);
		int* p = x.values();
		
#endif // !FIX1
		
	}
	/* keep the program running long enough */
	int y;
	std::cout << "type anything\n";
	std::cin >> y;
#endif // PROBLEM1

#ifdef PROBLEM2
	{
/* uncomment one of the lines below to activate the fix */
//#define UNIQUE
//#define SHARED
#ifdef UNIQUE
		Unique_Owner d(20);
		std::unique_ptr<int> p = d.values();
		std::cout << "Done using unique\n";
#elif defined(SHARED)
		Shared_Owner d(20);
		std::shared_ptr<int> p = d.values();
		std::cout << "Done using shared\n";
		std::shared_ptr<int> q = d.values();

#else 
		Double_Delete d(20);
		int* p = d.values();
		/* finished using p
		* delete so we don't get a leak
		*/
		delete p;
		std::cout << "Done \n";

#endif
	}
#endif // PROBLEM2



}

