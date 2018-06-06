//
// Created by Zhou,Baochuan on 18/6/4.
//

#include "common.h"
#include "http.h"
#include <gtest/gtest.h>
#include <curl/curl.h>

using namespace work;

// curl版本要求
TEST(curl, all)
{
    EXPECT_EQ(3, CURLVERSION_NOW );
    map<string, string> params;
    Http http("http://www.baidu.com/");
    cout << http.get(params) << endl;
}

