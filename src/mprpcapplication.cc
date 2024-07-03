#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>

MprpcConfig MprpcApplication::config_;

void showArgsHelp()
{
    std::cout << "format: command -i <configfile>" << std::endl;
}

void MprpcApplication::init(int argc, char **argv)
{
    if (argc < 2)
    {
        showArgsHelp();
        exit(EXIT_FAILURE);
    }

    int c = 0;
    std::string config_file;
    while ((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            showArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            showArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }

    // 开始加载配置文件了 rpcserver_ip=  rpcserver_port   zookeeper_ip=  zookepper_port=
    config_.loadConfigFile(config_file.c_str());

    std::cout << "rpcserverip:" << config_.load("rpcserverip") << std::endl;
    std::cout << "rpcserverport:" << config_.load("rpcserverport") << std::endl;
    std::cout << "zookeeperip:" << config_.load("zookeeperip") << std::endl;
    std::cout << "zookeeperport:" << config_.load("zookeeperport") << std::endl;
}

MprpcApplication &MprpcApplication::getInstance()
{
    static MprpcApplication app;
    return app;
}

MprpcConfig &MprpcApplication::getConfig()
{
    return config_;
}