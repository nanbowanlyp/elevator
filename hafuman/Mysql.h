#pragma once
#include <mysql.h>
void Connect();
MYSQL_RES* Select();
void Insert(int id, int start, int now, int end, char direction[20], char state[20]);
void Delete(int delete_id);