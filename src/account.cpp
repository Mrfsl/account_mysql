//
// Created by 墨染 on 2024/4/28.
//
#include "../header/common.h"
#include "../header/account_item.h"


int main()
{
    Account ac;
    ac.id = 3;
    ac.name = "星星";
    ac.type = 1;
    ac.nums = 8;
    AccountItem::GetInstance()->insert(ac);   // 增
    // AccountItem::GetInstance()->deleted(1);   // 删
    // AccountItem::GetInstance()->update(ac);   // 删

    // vector<Account> vc;
    // vc = AccountItem::GetInstance()->query();    // 查
    // cout << "共" << vc.size() << "条数据" << endl;


    return 0;
}

