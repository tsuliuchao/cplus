#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <stdio.h>
// 内存对齐:http://www.flysnow.org/2017/07/02/go-in-action-unsafe-memory-layout.html
using namespace std;

typedef struct {
	char b;
	uint32_t i;
	uint64_t j;
} user1 ;


typedef struct {
	char b;
	uint64_t j;
	uint32_t i;
} user2 ;

int main(void)
{
	user1 u1;
	user2 u2;
	cout << "u1=" << sizeof(u1) << endl; // 16
	cout << "u2=" << sizeof(u2) << endl; // 24
	return 0;
}
