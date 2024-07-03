#pragma once

#include <unordered_map>
#include <string>

// 框架读取配置文件类
class MprpcConfig
{
public:
    // 负责解析加载配置文件
    void loadConfigFile(const char *config_file);

    // 查询配置项信息
    std::string load(const std::string &key);

private:
    std::unordered_map<std::string, std::string> config_map_;

    // 去掉字符串前后的空格
    void trim(std::string &src_buf);
};