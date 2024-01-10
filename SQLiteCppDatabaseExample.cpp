#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include <string>

int main() {
    try {
        // 打开（或创建）数据库
        SQLite::Database db("example.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // 创建一个新表
        db.exec("CREATE TABLE IF NOT EXISTS user (id INTEGER PRIMARY KEY, name TEXT, email TEXT)");

        // 插入数据
        SQLite::Statement query(db, "INSERT INTO user (name, email) VALUES (?, ?)");
        query.bind(1, "Alice");
        query.bind(2, "alice@example.com");
        query.exec();
        query.reset();

        query.bind(1, "Bob");
        query.bind(2, "bob@example.com");
        query.exec();

        // 查询数据
        SQLite::Statement select(db, "SELECT * FROM user");
        while (select.executeStep()) {
            std::cout << "User: " << select.getColumn(1) << ", Email: " << select.getColumn(2) << std::endl;
        }

        // 更新数据
        db.exec("UPDATE user SET email = 'alice_smith@example.com' WHERE name = 'Alice'");

        // 删除数据
        db.exec("DELETE FROM user WHERE name = 'Bob'");

    } catch (const std::exception& e) {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
