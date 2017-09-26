#include "jsonparser.hpp"

#include <fstream>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

Task<ValueType> JsonParser::parseFile(const std::string &fileName) {
    std::ifstream file("data.json");
    rapidjson::IStreamWrapper stream(file);

    rapidjson::Document document;
    document.ParseStream(stream);

    if (document.HasParseError()) {
        std::cout << "Parse error code: " << document.GetParseError() << std::endl;
        return 0;
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    std::cout << buffer.GetString() << std::endl;

    return {};
}
