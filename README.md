# cplus
c++常用方式汇总
python 常用方式汇总

# 正则表达式提取reg.cpp reg.py
g++ -std=c++14 -O2 -Wall -pedantic -pthread reg.cpp && ./a.out
python reg.py

# mysql操作
gcc mysqlTest.cpp -I /home/work/.jumbo/include/ -L /home/work/.jumbo/lib -lmysqlclient -o mysqlTest
