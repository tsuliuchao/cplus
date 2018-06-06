//
// Created by Zhou,Baochuan on 18/5/31.
//

#include "common.h"
#include <gtest/gtest.h>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

// 去空格
TEST(string_util, trim)
{
    string  str = " 空格校验 ";
    trim(str);
    EXPECT_STREQ("空格校验", str.c_str());
}

