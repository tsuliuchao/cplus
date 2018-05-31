#include "common.h"
#include "string_util.h"


using namespace work;
#ifndef ENV_DEBUG
int main(int argc, char** argv) {
    string src = " OK";
    cout << StringUtil::trim(src) << endl;
    return 0;
}

#else
GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
