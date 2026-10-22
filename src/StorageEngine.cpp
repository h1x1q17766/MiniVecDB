#include"StorageEngine.h"
bool StorageEngine::set(const std::string&key,const std::string&value){
    store_[key]=value;
    return true;
}
std::string StorageEngine::get(const std::string& key){
    auto it=store_.find(key);
    if(it!=store_.end()){
        return it->second;
    }
    return "";
}
bool StorageEngine::del(const std::string&key){
    return store_.erase(key)>0;
}