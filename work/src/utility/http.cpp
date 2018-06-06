//
// Created by Zhou,Baochuan on 18/6/5.
//

#include "http.h"

using namespace work;

Http::Http(string url)
{
    this->_url = url;
}

Http::~Http()
{
}

string Http::get(map<string, string> params)
{
    string response;
    return response;
}
