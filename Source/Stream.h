
#pragma once

#include "Precompiled.h"
#include  <iostream>
#include "json-develop/single_include/nlohmann/json.hpp"
#include <vector>

using json = nlohmann::json;

class Stream
{
private:

	std::ifstream _file;
	json _fileJson;


public:
	
	Stream(String filename);
	~Stream();

	json& Get();
	void Dump(String fileName);

	void Save(String filename, json jsonFile);

};