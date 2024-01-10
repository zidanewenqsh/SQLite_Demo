CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -Wall
CXXFLAGS=-g -Wall
LDFLAGS=-g
LDLIBS=-lsqlite3

all: SQLiteCDatabaseOperations SQLiteCppDatabaseExample

SQLiteCDatabaseOperations: SQLiteCDatabaseOperations.o
	$(CC) $(LDFLAGS) -o SQLiteCDatabaseOperations SQLiteCDatabaseOperations.o $(LDLIBS)

SQLiteCDatabaseOperations.o: SQLiteCDatabaseOperations.c
	$(CC) $(CFLAGS) -c SQLiteCDatabaseOperations.c

SQLiteCppDatabaseExample: SQLiteCppDatabaseExample.o
	$(CXX) $(LDFLAGS) -o SQLiteCppDatabaseExample SQLiteCppDatabaseExample.o -lSQLiteCpp -lpthread -ldl $(LDLIBS)
# -lsqlite3 位于链接器参数的最后，因为链接器是按顺序解析依赖关系的。
SQLiteCppDatabaseExample.o: SQLiteCppDatabaseExample.cpp
	$(CXX) $(CXXFLAGS) -c SQLiteCppDatabaseExample.cpp

clean:
	$(RM) *.o *~ SQLiteCDatabaseOperations SQLiteCppDatabaseExample
