
/* TODO */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

template<typename Ostream,typename Container>
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
#define SEARCH
//#define INCLUDES

#ifdef REMOVE_ERASE
int main()
{
	std::string s{ "Name, Mid,dle, Last" };
	auto itr = std::remove(s.begin(), s.end(), ',');
	std::cout << s<<"\n";
	s.erase(itr, s.end());
	std::cout << s<<"\n";;
}
#endif // REMOVE_ERASE

#ifdef SEARCH
int main(){
	std::string s{ "First Middle Last" };

	bool exists=s.find("Midle")!=std::string::npos;
	std::string sub = "Middle";
	auto subitr = std::search(s.begin(), s.end(), sub.begin(), sub.end());
	exists = subitr != s.end();
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

#ifdef INCLUDE
	/* both ranges must be ordered to use include */
		//std::cout<<std::includes(v.begin(), v.end(), needle.begin(), needle.end());
#endif // INCLUDE


