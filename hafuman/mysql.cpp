#include <iostream>
using namespace std;
#include <WinSock.h>
#include <mysql.h>
#include <string>
#include<Mysql.h>
MYSQL m;        //mysql连接
MYSQL_RES* res; //查询结果集
MYSQL_ROW row;  //二维数组，存放数据



//int main()
//{
//	int id = 1;
//	//Connect();
//	//Insert();
//	//Select();
//	//Delete();
//	//Select();
//	test(id);
//	return 0;
//}

void Connect() {
	//初始化数据库
	mysql_init(&m);

	//设置编码方式
	mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");

	//连接数据库
	if (mysql_real_connect(&m, "localhost", "root", "Restart1128", "test", 3306, NULL, 0))
	{                           //主机       用户名   密码      数据库名  端口
		printf("数据库连接成功\n");
	}
	else {
		printf("数据库连接失败:%s \n", mysql_error(&m));
		//输出错误信息
	}
}

void Insert(int id,int start, int now, int end, char direction[20], char state[20])
{
	//int id;
	//char start[20],now[20],end[20], direction[20], state[20];
	//cin >> id;
	//cin >> start;
	//cin >> now;
	//cin >> end;
	//cin >> direction;
	//cin >> state;
	const char* str = "insert into elevator values(";

	char sql_insert[200];
	sprintf_s(sql_insert, "%s%d%s%d%s%d%s%d%s%s%s%s%s%s%s%s%s", str,id,",",start, ",", now, ",", end,",", "'", direction, "'",",", "'", state, "'", ")");
	printf(sql_insert);
	
	if (mysql_query(&m, sql_insert))
	{
		printf("插入数据失败：%s \n", mysql_error(&m));
	}
	else
	{
		printf("插入数据成功\n");
	}
}

MYSQL_RES* Select() {
	const char* sql_query = "select * from elevator ";
	if (mysql_query(&m, sql_query))
	{
		printf("未查到记录：%s \n", mysql_error(&m));
	}
	else
	{
		printf("查询成功 \n");
	}
	//获取查询结果集
	res = mysql_store_result(&m);
	return res;
	if (res)
	{
		printf("获取到数据\n");
	}
	else
	{
		printf("未获取到数据：%s \n", mysql_error(&m));
	}
	//打印获取到的数据
	//printf("id\tstart\tnow\tend\tdirection\tstate\n");
	//while (row = mysql_fetch_row(res))
	//{
	//	
	//	printf("%s\t%s\t%s\t%s\t%s\t\t%s\n", row[0], row[1], row[2],row[3],row[4],row[5]);
	//}
}

void Delete(int delete_id) {
	const char * sql_delete = "delete from elevator where id = ";
	char sql_delete1[200];
	sprintf_s(sql_delete1, "%s%d", sql_delete, delete_id);
	if (mysql_query(&m, sql_delete1))
	{
		printf("删除数据失败：%s \n", mysql_error(&m));
	}
	else
	{
		printf("删除数据成功\n");
	}
}


