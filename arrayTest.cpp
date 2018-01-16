#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <curl/curl.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(void)
{
	string dateList[] = {"2017-11-14", "2017-11-15", "2017-11-16", "2017-11-17", "2017-11-18", "2017-11-19", "2017-11-20", "2017-11-21"};
	int size = sizeof(dateList)/sizeof(dateList[0]);
	for (int i = 0; i < size; i++) {
		cout << dateList[i] << endl;
	}
	return 0;
}
