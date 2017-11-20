//
//  main.cpp
//  study
//
//  Created by Zhou,Baochuan on 17/10/31.
//  Copyright © 2017年 Zhou,Baochuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void replace_all_distinct(string& str,const string& old_value,const string& new_value)
{
    for(string::size_type pos(0);pos!=string::npos;pos+=new_value.length()){
        if((pos=str.find(old_value,pos))!=string::npos){
            str.replace(pos,old_value.length(),new_value);
        }else{
            break;
        }
    }
    return;
}



vector<string> jq_str_split (const string& inStr, char splitChar, size_t nSplit)
{
    vector<string> result;
    if (nSplit < 2 || splitChar == 0 || inStr.empty())
    {
        return result;
    }
    size_t flag = 0;
    size_t start = 0;
    while (start < inStr.size())
    {
        size_t pos = inStr.find(splitChar,start);
        if (pos == string::npos)
        {
            goto final;
        }
        if (pos == start)
        {
            result.push_back(inStr.substr(start,pos-start));
            start = pos + 1;
            continue;
        }
        flag++;
        result.push_back(inStr.substr(start,pos-start));
        if ((flag + 1) == nSplit)
        {
            start = pos +1;
            goto final;
        }
        start = pos + 1;
    }
    final:
    result.push_back(inStr.substr(start));
    return result;
}

vector<string> split(const char *src){
    string delimSign[] = {" ","，","。", "；", "：", "！", "？"};
    //cout << delimSign[1] << endl;
    int size = sizeof(delimSign)/sizeof(delimSign[0]);
    string target = src;
    vector<string> retVector;
    for (int i = 0; i < size; i++) {
        replace_all_distinct(target, delimSign[i], "\t");
        retVector = jq_str_split(target, '\t', 100);
        //cout << "147:src=" << src << "\tdel="<< delimSign[i] << "\ttarget=" << target << endl;
    }
    return retVector;
}

string &sStrim(std::string &s) {
    if (s.empty())   
    {  
        return s;  
    }  
  
    s.erase(0,s.find_first_not_of("\r"));  
    s.erase(s.find_last_not_of("\r") + 1);  
    s.erase(0,s.find_first_not_of("\n"));  
    s.erase(s.find_last_not_of("\n") + 1);  
    return s;  
}

string& trim(std::string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
  
    s.erase(0,s.find_first_not_of("	"));  
    s.erase(s.find_last_not_of(" ") + 1);  

    s.erase(0,s.find_first_not_of("\t"));  
    s.erase(s.find_last_not_of("\t") + 1);  

    s.erase(0,s.find_first_not_of("tag"));  
    s.erase(s.find_last_not_of("tag") + 1);  

    s.erase(0,s.find_first_not_of("﻿"));  
    s.erase(s.find_last_not_of("﻿") + 1);  

    s.erase(0,s.find_first_not_of("\""));  
    s.erase(s.find_last_not_of("\"") + 1);  
    return s;  
}

int main(int argc, const char * argv[]) {
	ifstream targetIfstream;
    targetIfstream.open("./1.txt", ios::in);
    if(targetIfstream.fail()) {
        cout << "open failure" << endl;
        return -401;
    }

	ifstream srcIfstream;
    srcIfstream.open("./2.txt", ios::in);
    if(srcIfstream.fail()) {
        cout << "open failure" << endl;
        return -401;
    }

	ofstream ofile;
	ofile.open("./3.txt", ios_base::out);
    if (ofile.fail()) {
        cout << "open failure" << endl;
        return -401;
    }


    string input;
	vector<string> searchVector;
    while(getline(targetIfstream, input, '\n')) {
		//sStrim(input);
		trim(input);
		searchVector.push_back(input);
    }
	targetIfstream.close();
	int vSize = searchVector.size();

	vector<string> splitVector;
	size_t charPos;
	string tmp;

    while(getline(srcIfstream, input, '\n')) {
		tmp = input;
		splitVector = jq_str_split(input, '\t', 100);
		if (splitVector.size() > 4) {
			trim(splitVector[3]);
			for (int i=0; i < vSize;i++) {
				if (splitVector[3].empty()) {
					continue;
				}
				//cout << splitVector[3] << "\t" << searchVector[i] << endl;
				if (splitVector[3].find(searchVector[i]) != string::npos || searchVector[i].find(splitVector[3]) != string::npos) {
					 //cout << tmp << endl;
					//cout << splitVector[3] << "\t" << searchVector[i] << endl;
					ofile << tmp ;
					break;
				}
			}
		}
    }

	srcIfstream.close();
	ofile.close();


	return 0;
}
