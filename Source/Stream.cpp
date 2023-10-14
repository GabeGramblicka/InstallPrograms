#include "Precompiled.h"
#include "json-develop/single_include/nlohmann/json.hpp"
#include "Stream.h"
#include "Trace.h"

//using the json for modern c++ library: https://github.com/nlohmann/json

using json = nlohmann::json;

Stream::Stream(String fileName)
{
	std::ifstream jsonIn(fileName);
	if (jsonIn)
	{
		_file.swap(jsonIn);
		json data = json::parse(_file);
		_fileJson = data;
	}
	else
	{
		Trace::Log() << "Could not open '" << fileName << "' \n";
	}
}

Stream::~Stream()
{
	_file.close();
}

json& Stream::Get()
{
	if (_file)
	{
		return _fileJson;
	}

	Trace::Log() << "This stream does not contain a file";
	return _fileJson;
}

void Stream::Dump(String fileName)
{
	_fileJson.dump();
}

void Stream::Save(String stream, json jsonFile)
{
	std::ofstream file(stream);

	if (file)
	{
		file << jsonFile;
	}
	
}


