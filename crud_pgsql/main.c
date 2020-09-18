#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <windows.h>
#include <sql.h>
#include <sqlext.h>
int main()
{
SQLHENV env;
if ( !SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_ENV,NULL, &env)))
    fprintf(stderr, "La fonction SQLAllocHandle a echoue
(SQL_HANDLE_ENV).
\
n");
else
{
if ( !SQL_SUCCEEDED(SQLSetEnvAttr(env,
SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0)) )
fprintf(stderr, "La fonction SQ
LSetEnvAttr a
echoue.
\
n");
else
{
SQLHDBC con;
if ( !SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC, env,
&con)) )
fprintf(stderr, "La fonction SQLAllocHandle a echoue
(SQL_HANDLE_DBC).
\
n");
else
{
SQLCHAR dsn[] = "pays_dsn", uid[] = "melem", pwd[] =
"1234";
if ( !SQL_SUCCEEDED(SQLConnect(con, dsn, SQL_NTS,
uid, SQL_NTS, pwd, SQL_NTS)) )
fprintf(stderr
, "La fonction SQLConnect a
echoue.
\
n");
else
{
SQLHSTMT stmt;
if (
!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, con, &stmt)) )
fprintf(s
tderr, "La fonction SQLAllocHandle
a echoue (SQL_HANDLE_STMT).
\
n");
else
{
if ( !SQL_SUCCEEDED(SQLExecDirect(stmt,
"SELECT * FROM pays_tbl;", SQL_NTS)) )
fprintf(st
derr, "La fonction
SQLExecDirect a echoue.
\
n");
else
{
SQLCHAR pays[15], capitale[15];
printf("PAYS > CAPITALE
\
n
\
n");
while (SQL_SUCCEEDED(SQLFetch(stmt)))
{
SQLGetData(stmt, 1, SQL_C_CHAR,
pays, sizeof(pays), NULL);
SQLGetData(st
mt, 2, SQL_C_CHAR,
capitale, sizeof(capitale), NULL);
printf("%
-
14s %
-
14s
\
n", pays,
capitale);
}
}
SQLFreeHandle(SQL_HANDLE
_STMT, stmt);
}
SQLDisconnect(con);
}
SQLFreeHandle(SQL_HANDLE_DBC, con);
}
}
SQLFreeHandle(SQL_HANDLE_EN
V, env);
}
return 0;
}
