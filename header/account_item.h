//
// Created by 墨染 on 2024/4/28.
//

#ifndef ACCOUNT_DB_ACCOUNT_ITEM_H
#define ACCOUNT_DB_ACCOUNT_ITEM_H

#pragma once


#include "mysql.h"
#include "common.h"


typedef struct Account{
    int id;
    string name;
    int type;
    float nums;
}Account;

class AccountItem {
    AccountItem();
    ~AccountItem();
public:
    static AccountItem* GetInstance()    // 单例模式
    {
        static AccountItem DBAccountItem;
        return &DBAccountItem;
    }
public:
    bool insert(Account& ac);
    bool deleted(int id);
    bool update(Account& ac);
    vector<Account> query();

private:
    MYSQL* con;
    const char* host = "127.0.0.1";
    const char* user = "root";
    const char* pw = "1021";
    const char* db_name = "account_cpp";
    const int port = 3306;
};


#endif //ACCOUNT_DB_ACCOUNT_ITEM_H
