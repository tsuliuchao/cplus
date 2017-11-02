//
//  main.cpp
//  study
//
//  Created by Zhou,Baochuan on 17/10/31.
//  Copyright © 2017年 Zhou,Baochuan. All rights reserved.
//

#include <iostream>
#include <vector>
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

string& trim(std::string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
  
    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}

int main(int argc, const char * argv[]) {
	string str1 = "     ";
	trim(str1);
	cout << str1 << endl;
	return 0;
	
    // insert code here...
    string src="最后一集燃爆了啊！！期待第二季不要瞎扯";
    vector<string> vectorSrc = split(src.c_str());
    int8_t vSize = vectorSrc.size();
    for (int8_t i=0; i < vSize; i++) {
        cout << vectorSrc[i] << endl;
    }
    //cout << src << endl;
    return 0;
}
