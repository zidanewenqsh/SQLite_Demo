#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]){
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    // 打开数据库
    rc = sqlite3_open("example.db", &db);
    if(rc){
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "数据库打开成功\n");
    }

    // 创建 SQL 语句
    char *sql = "CREATE TABLE IF NOT EXISTS user("  \
                "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                "NAME TEXT NOT NULL," \
                "EMAIL TEXT NOT NULL);";

    // 执行 SQL 语句
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "表创建成功\n");
    }

    // 插入数据
    sql = "INSERT INTO user (NAME, EMAIL) VALUES ('Alice', 'alice@example.com'); " \
          "INSERT INTO user (NAME, EMAIL) VALUES ('Bob', 'bob@example.com');";

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "记录插入成功\n");
    }

    // 查询数据
    sql = "SELECT * FROM user;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "查询操作成功\n");
    }

    // 更新数据
    sql = "UPDATE user set EMAIL = 'alice_smith@example.com' where ID = 1; " \
          "SELECT * FROM user;";
    
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "更新操作成功\n");
    }

    // 删除数据
    sql = "DELETE FROM user where ID = 2; " \
          "SELECT * FROM user;";
    
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL 错误: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "删除操作成功\n");
    }

    // 关闭数据库
    sqlite3_close(db);
    return 0;
}
