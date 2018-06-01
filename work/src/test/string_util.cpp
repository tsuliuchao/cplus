//
// Created by Zhou,Baochuan on 18/5/31.
//

#include "common.h"
#include "string_util.h"
#include <gtest/gtest.h>

using namespace work;

TEST(string_util, trim)
{
    string src1 = " 空格校验 ";
    string src2 = StringUtil::trim(src1);
    EXPECT_STREQ("空格校验", src2.c_str());
}

