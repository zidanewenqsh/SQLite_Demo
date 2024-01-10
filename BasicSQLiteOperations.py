import sqlite3

# 连接到SQLite数据库
# 如果文件不存在，会自动在当前目录创建:
conn = sqlite3.connect('example.db')
cursor = conn.cursor()

# 创建一个表:
cursor.execute('CREATE TABLE IF NOT EXISTS user (id INTEGER PRIMARY KEY, name TEXT, email TEXT)')

# 插入一行记录:
cursor.execute('INSERT INTO user (name, email) VALUES (?, ?)', ('Alice', 'alice@example.com'))
cursor.execute('INSERT INTO user (name, email) VALUES (?, ?)', ('Bob', 'bob@example.com'))

# 通过rowid来查询刚插入的数据:
cursor.execute('SELECT * FROM user WHERE rowid = ?', (1,))
print(cursor.fetchone())

# 查询多条记录:
cursor.execute('SELECT * FROM user')
for row in cursor.fetchall():
    print(row)

# 更新数据:
cursor.execute('UPDATE user SET name = ? WHERE id = ?', ('Alice Smith', 1))
cursor.execute('SELECT * FROM user WHERE id = ?', (1,))
print(cursor.fetchone())

# 删除数据:
cursor.execute('DELETE FROM user WHERE id = ?', (1,))
cursor.execute('SELECT * FROM user')
print(cursor.fetchall())

# 提交事务:
conn.commit()

# 关闭Cursor和Connection:
cursor.close()
conn.close()
