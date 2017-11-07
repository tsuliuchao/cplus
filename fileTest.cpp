#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifile;
    ifile.open("./data/test.txt", ios::in);
    if(ifile.fail()) {
        cout << "open failure" << endl;
        return -401;
    }
    
    string input;
    
    while(getline(ifile, input, '\n')) {
        printf("%s\n",input.c_str());
    }
    return 0;
}
