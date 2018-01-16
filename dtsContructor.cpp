#include <iconv.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << "[" << endl;
	for (int i = 0; i < 256; i++) {
		printf("{\"type\":\"table\", \"src\":\"news_base.t_news_%d\", \"dst\":\"shushuo.dim_baidu_news_2017\", \"where\":\"m_public_time>1483200000 and m_category=4 and m_tag <> ''\"},\n", i);
	}
	cout << "]" << endl;
	return 0;
}
