#include <iostream>
#include <string>
#include "CommandParser.h"
#include "StorageEngine.h"

int main() {
    StorageEngine engine;
    CommandParser parser;
    std::string line;

    std::cout << "MiniVecDB v0.1" << std::endl;

    // 循环读取用户的输入
    while (std::getline(std::cin, line)) {
        // 1. 叫解析器去干活：把字符串拆成结构体包裹
        ParsedCommand cmd = parser.parse(line);

        // 2. 看看包裹里是什么命令，分别派发给仓库管理员
        if (cmd.type == CommandType::SET) {
            engine.set(cmd.key, cmd.value);
            std::cout << "OK" << std::endl;
        } 
        else if (cmd.type == CommandType::GET) {
            std::string val = engine.get(cmd.key);
            if (val.empty()) std::cout << "(nil)" << std::endl;
            else std::cout << val << std::endl;
        } 
        else if (cmd.type == CommandType::DEL) {
            engine.del(cmd.key);
            std::cout << "OK" << std::endl;
        } 
        else if (cmd.type == CommandType::UNKNOWN) {
            // 如果是 EXIT 或者乱码
            if (line == "EXIT") break;
            std::cout << "ERR unknown command" << std::endl;
        }
    }
    return 0;
}