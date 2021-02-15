#include <iostream>
#include <type_traits>
#include <utility>
#include <chrono>
#include <cmath>
#include <random>
#include <immintrin.h>
#define Q(x) #x
#define QUOTE(x) Q(x)

struct tmp {
	int _size, _twice;
	tmp(int size) :_size(size), _twice(2 * _size) {
	}
	int& twice() {
		return _twice;
	}

};
int main() {
	tmp t{ 3 };
	std::cout << t.twice() << "\n";
}
//#include "../../hw1-sol/utility.h"
//static const int length = (1<<24)*8;
//static float a[length];
//static float b[length];
//
//float scalarAverage() {
//    float sum = 0.0;
//    double f = 0.001;
//    for (uint32_t j = 0; j <length; ++j) {
//        sum += a[j];
//    }
//
//    return sum /length  ;
//}
//
//int main(){
//    Duration d1;
//    float total;
//    a[0] = 1; b[0] = 1;
//    for (int i = 1; i < length; ++i)a[i] = i;
//    for (int i = 1; i < length; ++i)b[i] = 2*i;
//    
//        TIMEIT(d1, total = scalarAverage();
//        )
//        std::cout << total << "\n";
//        std::cout << "time =" << d1.count() << "\n";
//  
//}
//#include "immintrin.h"
//const int n = 1 << 20;
//
//
//float a[n], b[n];
//float d[n];
//float c = 3.0;
//
//void seq_sin(int n, int terms, float* x, float* result) {
//	for (int i = 0; i < n; ++i) {
//		float origx = x[i];
//		float value = origx;
//		float numer = origx * origx * origx;
//		float denom = 6;
//		int sign = -1;
//		for (int j = 1; j <= terms; ++j) {
//			value += sign * numer / denom;
//			numer *= origx * origx;
//			denom *= (2 * j + 2) * (2 * j + 3);
//			sign *= -1;
//		}
//		result[i] = value;
//	}
//	
//}
//void sinx(int N, int terms, float* x, float* result)
//{
//	float three_fact = 6; // 3!
//	for (int i = 0; i < N; i += 16)
//	{
//		__m512 origx = _mm512_load_ps(&x[i]);
//		__m512 value = origx;
//		__m512 numer = _mm512_mul_ps(origx, _mm512_mul_ps(origx, origx));
//		__m512 denom = _mm512_set1_ps(three_fact);
//		int sign = -1;
//		for (int j = 1; j <= terms; j++)
//		{
//			// value += sign * numer / denom
//			__m512 tmp = _mm512_div_ps(_mm512_mul_ps(_mm512_set1_ps(sign), numer),denom);
//			value = _mm512_add_ps(value, tmp);
//			numer = _mm512_mul_ps(numer, _mm512_mul_ps(origx, origx));
//			denom = _mm512_mul_ps(denom, _mm512_set1_ps((2*j+2)*(2*j+3)));
//			sign *= -1;
//		}
//		_mm512_store_ps(&result[i], value);
//	}
//}
//
//
//int main() {
//	std::cout << "Executing \n";
//	std::cout << QUOTE(FUNC(OPT)) << "\n";
//	std::cout << "With n= " << n << "\n";
//	std::random_device rd;
//	std::uniform_real_distribution<float> dist(0,4);
//	for (int i = 0; i < n; ++i)a[i] =dist(rd);
//	::seq_sin(n,20, a, b);
//	Duration d;
//	
//	TIMEIT(d, seq_sin(n, 20, a, b);
//	)
//	std::cout <<d.count()<< "\n";
//	TIMEIT(d,sinx(n, 20, a, b);
//	)
//		std::cout << d.count() << "\n";
//	std::cout << "\n";
//}
