//
// Created by Zhou,Baochuan on 18/5/31.
//

#include "common.h"
#include <gtest/gtest.h>
using namespace boost::algorithm;

// 去空格
TEST(string_util, trim)
{
    string  str = " 空格校验 ";
    cout << "befor trim str=" << str << endl;
    trim(str);
    cout << "after trim str=" << str << endl;
}

