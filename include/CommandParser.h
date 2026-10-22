#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>

enum class CommandType {
    SET,
    GET,
    DEL,
    UNKOWN
};
 struct ParsedCommand {
    CommandType type=CommandType::UNKOWN;
    std::string key;
    std::string value;
};
class CommandParser{
public:
    ParsedCommand parse(const std::string&line);
};
#endif