//
// Created by Zhou,Baochuan on 18/5/31.
//

#include "gtest/gtest.h"
#include "common.h"
#include "string_util.h"
using namespace work;

#ifdef ENV_DEBUG
TEST(string_util, trim)
{
    string src1 = " 空格校验 ";
    string src2 = StringUtil::trim(src1);
    EXPECT_STREQ("空格校验", src2.c_str());
    EXPECT_STREQ("空格校验 ", src2.c_str());
}
#endif