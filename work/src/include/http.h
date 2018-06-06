//
// Created by Zhou,Baochuan on 18/6/5.
//

#ifndef WORK_HTTP_H
#define WORK_HTTP_H

#include "common.h"

namespace work {
    class Http {
    private:
        string _url;
    public:
        Http(string url);
        ~Http();
        static string get(map<string, string> params);
    };
}

#endif //WORK_HTTP_H
