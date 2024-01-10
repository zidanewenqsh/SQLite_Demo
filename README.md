# SQLite_Demo
我的C语言，C++和Python实现的SQLite增删改查的案例

# 安装
## 安装sqlite3
```bash
sudo apt update
sudo apt install sqlite3 libsqlite3-dev
```
> python 自带 sqlite3，没有的话pip安装

## 安装SQLiteCpp
```bash
git clone https://github.com/SRombauts/SQLiteCpp.git
cd SQLiteCpp
mkdir build
cd build
cmake ..
make
sudo make install
```


# 编译
```bash
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
```
```bash
# gcc SQLiteCDatabaseOperations.c -o SQLiteCDatabaseOperations -lsqlite3
clang SQLiteCDatabaseOperations.c -o SQLiteCDatabaseOperations -lsqlite3
```

```bash
# g++ SQLiteCppDatabaseExample.cpp -o SQLiteCppDatabaseExample -lSQLiteCpp -lsqlite3 -lpthread -ldl
clang++ SQLiteCppDatabaseExample.cpp -o SQLiteCppDatabaseExample -lSQLiteCpp -lsqlite3 -lpthread -ldl
```
> gcc或clang都可以