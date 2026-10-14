// ===== 头文件：引入需要用到的库 =====
#include <iostream>      // 输入输出：cin/cout/endl
#include <sstream>       // stringstream：用来切分字符串
#include <string>        // std::string：字符串类型
#include <unordered_map> // 哈希表：用来存 key-value

// ===== 主函数：程序的入口 =====
int main() {
    // 创建一个哈希表，key是string，value也是string
    // 就像一本字典，左边是名字，右边是解释
    std::unordered_map<std::string, std::string> store;

    // 准备一个字符串变量，用来接收每一行输入
    std::string line;

    // 打印欢迎信息
    std::cout << "MiniVecDB v0.1" << std::endl;

    // while循环：不断读取输入，直到没有输入为止
    // getline(cin, line)：从终端读一整行，存到line里
    while (std::getline(std::cin, line)) {
        // 把读到的这一行变成一个"流"，方便用 >> 逐个取词
        // 比如 "SET name hxq" 会被拆成三块：SET、name、hxq
        std::stringstream ss(line);

        // 准备三个变量，分别存命令、key、value
        std::string cmd, key, value;

        // 从流里取第一个词，当作命令
        ss >> cmd;

        // ===== 如果是 SET 命令 =====
        if (cmd == "SET") {
            // 继续取两个词：key 和 value
            ss >> key >> value;

            // 检查key或value是不是空的
            if (key.empty() || value.empty()) {
                // 参数不够，报错
                std::cout << "ERR wrong number of arguments" << std::endl;
            } else {
                // 存进哈希表：store["name"] = "hxq"
                store[key] = value;
                // 回复OK
                std::cout << "OK" << std::endl;
            }
        }
        // ===== 如果是 GET 命令 =====
        else if (cmd == "GET") {
            // 取一个词：key
            ss >> key;

            // find(key) != end()：说明哈希表里有这个key
            if (store.find(key) != store.end()) {
                // 有，输出对应的value
                std::cout << store[key] << std::endl;
            } else {
                // 没有，输出(nil)，表示空
                std::cout << "(nil)" << std::endl;
            }
        }
        // ===== 如果是 DEL 命令 =====
        else if (cmd == "DEL") {
            // 取一个词：key
            ss >> key;

            // erase(key)返回被删掉的元素个数
            // 如果大于0，说明删掉了
            if (store.erase(key)) {
                std::cout << "OK" << std::endl;
            } else {
                // 返回0，说明本来就没有这个key
                std::cout << "(nil)" << std::endl;
            }
        }
        // ===== 如果是 EXIT 命令 =====
        else if (cmd == "EXIT") {
            // 跳出while循环，程序结束
            break;
        }
        // ===== 其他未知命令 =====
        else {
            std::cout << "ERR unknown command" << std::endl;
        }
    }

    return 0; // 程序正常退出
}
