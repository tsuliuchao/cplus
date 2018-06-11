//
// Created by Zhou,Baochuan on 18/6/7.
//

#ifndef WORK_STRING_UTIL_H
#define WORK_STRING_UTIL_H

#include "common.h"

namespace work{
    class StringUtil {
    public:
        StringUtil();
        ~StringUtil();
        static vector<string> split(string text, string sep);
    };
}


#endif //WORK_STRING_UTIL_H
