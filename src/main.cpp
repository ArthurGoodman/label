#include <fstream>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "matrix.hpp"
#include "solver.hpp"
#include "valuewrapper.hpp"

int main(int argc, char **argv) {
    using ValueType = ValueWrapper<int, oper::min, oper::plus>;

    static constexpr size_t k = 3;

    std::vector<Matrix<ValueType>> q;
    std::vector<Matrix<ValueType>> G;

    q.push_back(Matrix<ValueType>::zero(k, 1));
    q.back().at(0, 0) = 1;
    q.back().at(1, 0) = 3;
    q.back().at(2, 0) = 1;

    q.push_back(Matrix<ValueType>::zero(k, 1));
    q.back().at(0, 0) = 2;
    q.back().at(1, 0) = 1;
    q.back().at(2, 0) = 3;

    q.push_back(Matrix<ValueType>::zero(k, 1));
    q.back().at(0, 0) = 4;
    q.back().at(1, 0) = 0;
    q.back().at(2, 0) = 2;

    G.push_back(Matrix<ValueType>::one(k, k));
    G.back().at(0, 0) = 1;
    G.back().at(0, 2) = 2;
    G.back().at(1, 1) = 2;
    G.back().at(1, 2) = 1;
    G.back().at(2, 1) = 3;

    G.push_back(Matrix<ValueType>::one(k, k));
    G.back().at(0, 0) = 1;
    G.back().at(0, 2) = 2;
    G.back().at(1, 1) = 3;
    G.back().at(1, 2) = 1;
    G.back().at(2, 0) = 3;
    G.back().at(2, 1) = 2;
    G.back().at(2, 2) = 1;

    std::cout << "Result = " << Solver::solve(q, G, false) << std::endl;

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

    return 0;
}
