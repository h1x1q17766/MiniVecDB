#include<iostream>
#include<cassert>
#include "CommandParser.h"
#include "StorageEngine.h"

void test_engine(){
    StorageEngine engine;
    engine.set("name","hxq");
    assert(engine.get("name")=="hxq");
    engine.set("name","abc");
    assert(engine.get("name")=="abc");
    engine.del("name");
    assert(engine.get("name")=="");
    std::cout<<"[Pass] StorageEngine 测试通过!"<<std::endl;
}
void test_parser(){
    CommandParser parser;
    ParsedCommand cmd1=parser.parse("SET age 20");
    assert(cmd1.type==CommandType::SET);
    assert(cmd1.key=="age");
    assert(cmd1.value=="20");
    ParsedCommand cmd2=parser.parse("HELLO WORLD");
    assert(cmd2.type==CommandType::UNKOWN);
    std::cout<<"[Pass] CommandParser 测试通过!"<<std::endl;
}
int main(){
    std::cout<<"--- 开始自动化测试 ---"<<std::endl;
    test_engine();
    test_parser();
    std::cout<<"--- 全部测试通过,代码健康! ---"<<std::endl;
    return 0;
}