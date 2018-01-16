//
//  main.cpp
//  study
//
//  Created by Zhou,Baochuan on 17/10/31.
//  Copyright © 2017年 Zhou,Baochuan. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
	std::string src = "100000000000";// 1千亿
	std::string target = src.substr(0, src.length()-4);
	std::cout << src << "\t" << target << std::endl;
	return 0;
}
