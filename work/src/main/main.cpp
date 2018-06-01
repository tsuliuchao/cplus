#include "common.h"
#include "string_util.h"


using namespace work;
int main(int argc, char** argv) {
    string src = " OK";
    cout << StringUtil::trim(src) << endl;
    return 0;
}


