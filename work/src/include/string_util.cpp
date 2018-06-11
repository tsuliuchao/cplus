//
// Created by Zhou,Baochuan on 18/6/7.
//

#include <regex>
#include "common.h"
#include "string_util.h"

using namespace work;
StringUtil::StringUtil ()
{
}
StringUtil::~StringUtil ()
{
}

vector<string> StringUtil::split(string text, string sep)
{
    vector<string> ret;
    std::regex regex(sep);

    std::sregex_token_iterator iterator(text.begin(), text.end(), regex, -1);
    std::sregex_token_iterator end;

    for ( ; iterator != end; ++iterator) {
        ret.push_back(*iterator);
    }
    return ret;
}
