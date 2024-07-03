#include <iostream>
#include "test.pb.h"
using namespace std;
using namespace fixbug;

int main()
{
    // 封装了login请求对象的数据
    LoginRequst req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据序列化 -> char*
    string send_str;
    if (req.SerializeToString(&send_str))
        cout << send_str.c_str() << endl;

    // 从send_str反序列化一个login请求对象
    LoginRequst reqB;
    if (reqB.ParseFromString(send_str))
    {
        cout << reqB.name() << endl;
        cout << reqB.pwd() << endl;
    }

    return 0;
}