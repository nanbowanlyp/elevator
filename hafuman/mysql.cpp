#include <iostream>
using namespace std;
#include <WinSock.h>
#include <mysql.h>
#include <string>
#include<Mysql.h>
MYSQL m;        //mysql����
MYSQL_RES* res; //��ѯ�����
MYSQL_ROW row;  //��ά���飬�������



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
	//��ʼ�����ݿ�
	mysql_init(&m);

	//���ñ��뷽ʽ
	mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");

	//�������ݿ�
	if (mysql_real_connect(&m, "localhost", "root", "Restart1128", "test", 3306, NULL, 0))
	{                           //����       �û���   ����      ���ݿ���  �˿�
		printf("���ݿ����ӳɹ�\n");
	}
	else {
		printf("���ݿ�����ʧ��:%s \n", mysql_error(&m));
		//���������Ϣ
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
		printf("��������ʧ�ܣ�%s \n", mysql_error(&m));
	}
	else
	{
		printf("�������ݳɹ�\n");
	}
}

MYSQL_RES* Select() {
	const char* sql_query = "select * from elevator ";
	if (mysql_query(&m, sql_query))
	{
		printf("δ�鵽��¼��%s \n", mysql_error(&m));
	}
	else
	{
		printf("��ѯ�ɹ� \n");
	}
	//��ȡ��ѯ�����
	res = mysql_store_result(&m);
	return res;
	if (res)
	{
		printf("��ȡ������\n");
	}
	else
	{
		printf("δ��ȡ�����ݣ�%s \n", mysql_error(&m));
	}
	//��ӡ��ȡ��������
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
		printf("ɾ������ʧ�ܣ�%s \n", mysql_error(&m));
	}
	else
	{
		printf("ɾ�����ݳɹ�\n");
	}
}


