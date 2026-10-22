#ifndef STORAGE_ENGINE_H
#define STORAGE_ENGINE_H

#include <string>
#include <unordered_map>

class StorageEngine {
public:
    bool set(const std::string& key, const std::string& value);
    
    std::string get(const std::string& key); 
    
    bool del(const std::string& key);

private:
    std::unordered_map<std::string, std::string> store_; 
};

#endif // STORAGE_ENGINE_H