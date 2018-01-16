#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <curl/curl.h>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
int main(void)
{
	vector<string> v;
	v.push_back("test1");
	v.push_back("test2");
	v.push_back("test3");
	cout << v.size() << endl;

	vector<string>().swap(v);
	cout << v.size() << endl;
	v.push_back("test3");
	cout << v.size() << endl;
	return 0;
}
