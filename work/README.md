## 目录结构
output ： 输出目录，用于打包上线的文件夹<br/>
data    :   存放数据 <br/>
doc     :   存放文档 <br/>
lib     :   库 <br/>
  &ensp;|—ext    :   存放第三方库

src     :   源代码 <br/>
 &ensp;|—include  ： 存放头文件 <br/>
 &ensp;|—utility：实现代码,对应include<br/>
 &ensp;|—main ：执行代码 <br/>
 &ensp;|—test ： 单元测试代码<br/>
 
 ## 单元测试
 目录位置： src/test/添加单元测试代码<br/>
 代码样例参考: src/test/string_util.cpp
 
 ## 依赖库安装
 ### boost安装
 下载地址:https://dl.bintray.com/boostorg/release/1.67.0/source/boost_1_67_0.tar.gz<br/>
 cd boost_1_67_0<br/>
 ./bootstrap.sh<br/>
 ./b2  install<br/>
 
 ## 相关使用文档
 
 googletest :   http://www.cnblogs.com/coderzh/archive/2009/04/06/1426755.html <br/>
 CMakeLists.txt 学习样例: https://github.com/yyzybb537/libgo/blob/master/CMakeLists.txt<br/>
 百度rpc(内部使用的)：https://github.com/brpc/brpc