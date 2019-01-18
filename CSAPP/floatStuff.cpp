#include <iostream>
#include <string>
#include <vector>
#include <integerStuff.h>
using namespace std;

int main(int argc, char** argv) {
	cout << "Hello world!\n";
	return 0;

}

/**
在早期的时候，浮点数是这样表示的
用一部分二进制数字去标识整数部分
用另一部分二进制数字去标识小数部分
d(m), d(m-1), d(1), d(0), d(-1), d(-2), d(-n+1), d(-n)
0 -> m 位二进制标识整数，-1 -> -n 用于标识小数部分 
**/

double getDoubleValue(int negBits, vector<bool> bits) {
	double result = 0;
	for(size_t = bits.size()-1; i > -1; i--) {
		result += powerOfAll(bits[i], negBits++);
	}
	return result;
}

/**
由于上述方式在运算的时候不是非常有效
于是乎，在后期有了一种新的浮点数表示方法
IEEE 754 方法。
**/
/** 
一般有两种精度
single precision
	1位符号位 (single sign bit)
	8位指数位 (exponent field, exponent E), k = 8, k - 1 = 7
	23位有效数字位 (fraction field, significand M), n = 23, n - 1 = 22
	<-1位符号位-><-8位指数位-><-23位有效数字位->
double precision
	1位符号位
	11位指数位, k = 11, k - 1 = 7
	52位有效数字位, n = 52, n - 1 = 51
	<-1位符号位-><-11位指数位-><-52位有效数字位->
**/

/**
Normalized Values:
	指的是,当exponent field不是所有bit都为0或者都为1.
	假设指数位是非负数的, 他们所表达的值是e

	exponent field E的值, E = e - 2^(k - 1) + 1
	例如：
		float数字的八个指数位是 11111110, k = 8
		e = 0b11111110 = 254
		E = 254 - 2 ^ 7 + 1 = 254 - 128 + 1 = 127

		假如float数字八个指数位为 00000001, k = 8
		e = 0b00000001 = 1
		E = 1 - 2 ^ 7 + 1 = 1 - 128 + 1 = -126
	
	fraction field, M的值 M = f + 1  ===>  1 <= M < 2
	0 <= f < 1, 通过f位的fractional bit表达出来
	按理来说M的值域应该是 0 <= M <1, 不过让M的最小值为1的话
	就可以节省一位的空间用于表达精度

Denormalized Values:
	当所有exponent bit都是0的时候

Special Values:
	当所有exponent bit都是1的时候
	Infinity:
		当所有fraction bit都是0的时候
	NaN:
		当所有fraction bit并不是都是0的时候
**/

/* Rounding 也是一个非常重要的话题
IEEE 定义了四种rounding的方式

Round-to-even     1.4=>1, 1.6=>2, 1.5=>2, 2.5=>2, -1.5=<-2
Round-toward-zero 1.4=>1, 1.6=>1, 1.5=>1, 2.5=>2, -1.5=>-1
Round-down        1.4=>1, 1.6=>1, 1.5=>1, 2.5=>2, -1.5=>-2
Round-up          1.4=>2, 1.6=>2, 1.5=>2, 2.5=>3, -1.5=>-1