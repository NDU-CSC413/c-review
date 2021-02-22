
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

template <typename Ostream,typename Container>
Ostream& operator<<(Ostream& os,Container& c) {
	for (auto x : c)
		os<< x << ",";
	return os;
}

/* template specialization */
template <>
std::ostream& operator<< <std::ostream, std::string>
			(std::ostream& os, std::string& s) {
	/* cannot use os<<s because we enter infinite recursion */
	os.write(s.c_str(), s.size());
	return os;
}


//#define REMOVE_ERASE
//#define SEARCH
#define INCLUDES
struct Test {

};

#ifdef REMOVE_ERASE
int main()
{
	int y = 6;
	
	std::vector< int > v{ 1,2,3,2,6,2,4,2 };
	std::string s{ "Name, Mid,dle, Last" };
	//auto itr = std::remove(s.begin(), s.end(), ',');
	auto itr = std::remove_if(v.begin(), v.end(),
		[](int x) {
			return (x % 2 == 0);
		}
	);
		
	std::cout << v;
	std::cout << "\n";
	v.erase(itr, v.end());
	std::cout << v;
	std::cout << "\n";
}
#endif // REMOVE_ERASE

#ifdef SEARCH
int main(){
	std::string s{ "First Middle Last" };

	//bool exists=s.find("Midle")!=std::string::npos;
	std::string sub = "Middle";

	/*auto subitr = std::search(s.begin(), s.end(), sub.begin(), sub.end());
	exists = subitr != s.end();*/

	std::vector<int> v{ 4,2,7,3,1,5 };
	std::reverse(v.begin(), v.end());
	std::cout<<v<<"\n";
	std::vector<int> needle{ 3,7,2 };
	std::cout << std::boolalpha;
	
	auto r=std::search(v.begin(), v.end(), needle.begin(), needle.end());
	if (r != v.end()) {
		std::cout << *r << "\n";
	}
	else std::cout << "not found\n";
}
#endif // SEARCH

#ifdef INCLUDES
#include <memory>
struct NoCopy {

};
int main(){
	std::vector<int> v{ 8,4,9,29,6 };// {4,6,8,9,29}
	std::sort(v.begin(), v.end());
	std::vector<int> needle{ 6,10};
	/* both ranges must be ordered to use include */
	std::cout<<std::includes(v.begin(), v.end(), needle.begin(), needle.end());
	std::unique_ptr<int> p, q;
	p = std::move(q);
	}
#endif // INCLUDE


