#include  <iostream>
#include "json-develop/single_include/nlohmann/json.hpp"
using json = nlohmann::json;


std::string dumpJson(const char* fileName);

json getJson(const char* fileName);

template<typename U>
U readKey(const char* filename, const char* keyName);