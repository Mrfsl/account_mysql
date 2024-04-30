//
// Created by 墨染 on 2024/4/28.
//

#include "../header/account_item.h"

AccountItem::AccountItem() {
    con = mysql_init(NULL);
    mysql_options(con,MYSQL_SET_CHARSET_NAME,"utf8");

    // 连接数据库
    if(!mysql_real_connect(con,host,user,pw,db_name,port,NULL,0)){
        exit(1);
    }
}

AccountItem::~AccountItem() {
    mysql_close(con);
}


bool AccountItem::insert(Account& ac) {
    char sql[1020];
    sprintf(sql, "INSERT INTO account_item (name,type,nums) VALUES('%s', %d, '%f');",ac.name.c_str(),ac.type,ac.nums);
    if(mysql_query(con,sql)){
        cout << " 错误：" << mysql_error(con) << endl;
        return false;
    }
    cout << "添加成功!" << endl;
    return true;
}


bool AccountItem::deleted(int id) {
    char sql[1020];
    sprintf(sql, "DELETE FROM account_item WHERE id = %d",id);
    if(mysql_query(con,sql)){
        cout << " 错误：" << mysql_error(con) << endl;
        return false;
    }
    cout << "删除成功!" << endl;
    return true;
}

bool AccountItem::update(Account& ac) {
    char sql[1020];
    sprintf(sql, "UPDATE account_item SET name = '%s',type = '%d',nums = '%f' WHERE id = %d",
            ac.name.c_str(),ac.type,ac.nums,ac.id);
    if(mysql_query(con,sql)){
        cout << " 错误：" << mysql_error(con) << endl;
        return false;
    }
    cout << "修改成功!" << endl;
    return true;
}

vector<Account> AccountItem::query() {
    vector<Account> vc;
    char sql[1020];
    sprintf(sql, "SELECT * FROM account_item;");

    if(mysql_query(con,sql)){
        cout << " 错误：" << mysql_error(con) << endl;
        return vc;
    }
    MYSQL_RES* res = mysql_store_result(con);
    MYSQL_ROW row;
    while (row = mysql_fetch_row(res)) {
        Account account;
        account.name = row[1];
        account.type = atoi(row[2]);
        account.nums = atof(row[3]);
        vc.push_back(account);
    }
    // 释放结果集
    mysql_free_result(res);

    cout << "查询成功!" << endl;
    return vc;
}



