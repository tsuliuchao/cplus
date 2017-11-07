#include<iostream>  
#include<cstdlib>  
#include<string>  
#include<mysql/mysql.h>

using namespace std;  

class MyDB  
{  
public:  
    MyDB();  
    ~MyDB();  
    bool initDB(string host, string user, string pwd, string db_name, unsigned int port);  
    bool exeSQL(string sql);  
    bool insertSQL(string sql);  
private:  
    MYSQL *connection;  
    MYSQL_RES *result;  
    MYSQL_ROW row;  
};  

MyDB::MyDB()  
{  
    connection = mysql_init(NULL); // 初始化数据库连接变量  
    if(connection == NULL)  
    {  
        cout << "Error:" << mysql_error(connection);  
        exit(1);  
    }  
}  
  
MyDB::~MyDB()  
{  
    if(connection != NULL)  // 关闭数据库连接  
    {  
        mysql_close(connection);  
    }  
}  
  
bool MyDB::initDB(string host, string user, string pwd, string db_name, unsigned int port)  
{  
    // 函数mysql_real_connect建立一个数据库连接  
    // 成功返回MYSQL*连接句柄，失败返回NULL  
	cout << "host:" << host << "\tuser:" << user << "\tpwd:" << pwd  << "\tdb:" << db_name << endl;
    connection = mysql_real_connect(connection, host.c_str(),  
            user.c_str(), pwd.c_str(), db_name.c_str(), port, NULL, 0);  
    if(connection == NULL)  
    {  
        cout << "Error:" << mysql_error(connection);  
        exit(1);  
    }  
    return true;  
}  
  
bool MyDB::exeSQL(string sql)  
{  
    // mysql_query()执行成功返回0，失败返回非0值。与PHP中不一样  
    if(mysql_query(connection, sql.c_str()))  
    {  
        cout << "Query Error:" << mysql_error(connection);  
        exit(1);  
    }  
    else  
    {  
        result = mysql_use_result(connection); // 获取结果集  
        // mysql_field_count()返回connection查询的列数  
        for(int i=0; i < mysql_field_count(connection); ++i)  
        {  
            // 获取下一行  
            row = mysql_fetch_row(result);  
            if(row <= 0)  
            {  
                break;  
            }  
            // mysql_num_fields()返回结果集中的字段数  
            for(int j=0; j < mysql_num_fields(result); ++j)  
            {  
                cout << row[j] << " ";  
            }  
            cout << endl;  
        }  
        // 释放结果集的内存  
        mysql_free_result(result);  
    }  
    return true;  
}

  
bool MyDB::insertSQL(string sql)  
{  
    // mysql_query()执行成功返回0，失败返回非0值。与PHP中不一样  
    if(mysql_query(connection, sql.c_str()))  
    {  
        cout << "Query Error:" << mysql_error(connection);  
		return false;
    }  
      
    return true;  
}

  
int main()  
{  
    MyDB db;  
    db.initDB("cp01-rdqa-dev307-zhoubaochuan.epc.baidu.com", "shushuo", "shushuo", "shushuo", 9906);  
    // db.exeSQL("SELECT * FROM dim_comment_sentiment");  

	string sql = "INSERT INTO dim_comment_sentiment(subject_name,content) values('test', 'test')";
	db.insertSQL(sql);
	return 0;
}  
