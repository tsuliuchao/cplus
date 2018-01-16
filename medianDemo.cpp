// 中位数
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int main(){
	vector<double>v;
    v.push_back(0.11);
    v.push_back(0.22);
    v.push_back(0.01);
    v.push_back(0.01);
    v.push_back(0.003);
    v.push_back(0.9);
    sort(v.begin(),v.end());
    for(int i=0;i<5;i++)
    {
        cout<<v[i]<<endl;
    }

	cout << "中位数:";
	if (v.size() % 2 != 0) {
		cout << v[v.size() / 2] << endl;
	} else {
		cout << (v[v.size()/2] + v[v.size()/2 -1])/2 << endl;
	}
	return 0;
}
