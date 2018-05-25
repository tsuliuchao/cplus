//
// Created by Zhou,Baochuan on 18/5/25.
//

#ifndef WORK_STRING_UTIL_H
#define WORK_STRING_UTIL_H

#include "common.h"
namespace work{
    class StringUtil{
    public:
        // left 去空格
        static string ltrim(string str);
        // right 去空格
        static string rtrim(string str);
        // 两边去空格
        static string trim(string str);
    };
}
#endif //WORK_STRING_UTIL_H
