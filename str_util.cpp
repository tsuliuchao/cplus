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


vector<string> jq_str_split_v2 (const string& inStr, const string &splitChar)
{
    vector<string> result;
    if (inStr.empty())
    {
        return result;
    }
    size_t flag = 0;
    size_t start = 0;
	size_t splitCharLength = splitChar.length();
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
            start = pos + splitCharLength;
            continue;
        }
        flag++;
        result.push_back(inStr.substr(start,pos-start));
		start = pos + splitCharLength;
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
	string str3 = "卡诺恩·席尔贝鲁特、浅月香介";
	string find = "、";
	vector<string> str3_rows = jq_str_split_v2(str3, "、");
	for (int i = 0; i < str3_rows.size(); i++) {
		cout << str3_rows[i] << endl;
	}
	return 0;
	int pos  = str3.find(find);
	if (pos != string::npos) {
		cout << str3.substr(0, pos) << endl;
		cout << str3.substr(pos + find.length(), find.length() - pos) << endl;
	}
	return 0;
	string str2 = "{\"lang_id\":\"1\",\"lang_para\":\"0\",\"query\":\"local方式在运行时需要下载相应的词典文件，下载时需要依赖 hadoop client，在不同hadoop 机器上hadoop client 位置不同并且配置也不同，所以我们直接自己将hadoop client 压缩包上传到我们的运行环境中，并且在配置文件指定使用我们自己上传的hadoop client。modify.sh 文件会修改配置文件中的hadoop client 路径，直接在运行环境当前目录下的 ./hadoop-client/ 中寻找我们自己上传的hadoop client 。这就是modify.sh文件的作用。\"}xxdfafdsaaf";
	cout << str2.substr(str2.find("{"), str2.find("}") + 1) << endl;

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
