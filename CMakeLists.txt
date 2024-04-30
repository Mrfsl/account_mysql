cmake_minimum_required(VERSION 3.19)
project(account_db)

set(CMAKE_CXX_STANDARD 11)

#主要配置
include_directories("E:/MySql/MySQL Server 8.0/include")  #本机MySQL下的include路径
link_directories("E:/MySql/MySQL Server 8.0/lib")  #本机MySQL下的lib路径
link_libraries(libmysql)  #这个这样填就行

#与本次配置无关，一般由项目自动生成（注意要在引入文件夹的下面）
add_executable(account_db src/account.cpp header/common.h src/account_item.cpp header/account_item.h)

target_link_libraries(account_db libmysql) # account_db 为工程名

