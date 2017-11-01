// 正则表达式提取
#include <iostream>
#include <string>
#include <regex>

using namespace std;
int main(){
	string input = "douban://douban.com/tv/26611088/interest/1258190902";
	const regex pattern("douban://douban.com/tv/([0-9]+)/interest/[0-9]+");
	match_results<string::const_iterator> matchResult;

	if (regex_match(input, matchResult, pattern)) {
		for (size_t i = 0; i < matchResult.size(); i++) {
			cout << matchResult[i] << endl;
		}
	} else {
		cout << "No Match" << endl;
	}

	return 0;
}
