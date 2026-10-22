#include"CommandParser.h"
#include<sstream>
//stream运用了流的思想，管理的是程序与内存里的字符串的交互
//包含stringstream既可读又可写
//istringstream只能读
//ostringstream只能写int main() {
    // 1. 把数字变成字符串
    //int num = 123;
    //std::stringstream ss;
    //ss << num;           // 扔进流里
    //std::string str = ss.str(); // 拿出来变成字符串 "123"
  // 2. 把字符串变成数字
    //std::string text = "456";
    //std::stringstream ss2(text);
    //int result;
    //ss2 >> result;       // 吸出来，自动变整数 456
    //std::cout << result + 1 << std::endl; // 输出 457
    //return 0;
//}
ParsedCommand CommandParser::parse(const std::string&line){
    ParsedCommand result;
    std::stringstream ss(line);
    std::string cmd;
    ss>>cmd;
    if(cmd=="SET"){
        result.type=CommandType::SET;
        ss>>result.key>>result.value;
    }else if(cmd=="GET"){
        result.type=CommandType::GET;
        ss>>result.key;
    }else if(cmd=="DEL"){
         result.type=CommandType::DEL;
         ss>>result.key;
    }
    return result;
}