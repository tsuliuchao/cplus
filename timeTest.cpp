#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(void)
{
	// 字符串格式日期转化为时间戳
	string src = "2017-11-12";
	struct tm* tmp_time = (struct tm*)malloc(sizeof(struct tm));  
    strptime(src.c_str(),"%Y-%m-%d",tmp_time);  
    time_t t = mktime(tmp_time);  
    printf("%ld\n",t);  
    free(tmp_time); 
	cout << (int)t;
	return 0;

	tm tm_;
	time_t t_;
	strptime(src.c_str(), "%Y-%m-%d", &tm_);
	t_ = mktime(&tm_);
	cout << t_ << endl;
	return 0;
	

	// 打印前一天日期
	time_t now;
	struct tm ts;
	char buf[80];

	// Get current time
	time(&now);

	// Format time, "yyyy-mm-dd hh:mm:ss""
	now = now - 24 * 3600;
	ts = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &ts);
	// printf("%s\n", buf);
	string yesterday = buf;
	cout << "yesterday:" + yesterday << endl;
	return 0;
}
