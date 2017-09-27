#pragma once

#include <fstream>
#include <string>
#include <vector>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>

#include "matrix.hpp"

namespace label {

template <class T>
struct Task {
    std::vector<Matrix<T>> vertices;
    std::vector<Matrix<T>> edges;
};

#undef assert
#define assert(value) \
    if (!(value))     \
        throw std::runtime_error("assertion `" + std::string(#value) + "' failed'");

template <class T>
Task<T> parseJsonFile(const std::string &fileName) {
    std::ifstream file(fileName);

    if (!file)
        throw std::runtime_error("error opening file \'" + fileName + "'");

    rapidjson::IStreamWrapper stream(file);

    rapidjson::Document document;
    document.ParseStream(stream);

    if (document.HasParseError())
        throw std::runtime_error(
            "rapidjson: " + std::string(GetParseError_En(document.GetParseError())));

    Task<T> task;

    assert(document.IsObject());
    assert(document.HasMember("vertices"));
    assert(document.HasMember("edges"));
    assert(document.MemberCount() == 2);

    rapidjson::Value &vertices = document["vertices"];
    assert(vertices.IsArray());

    int k = -1;

    for (size_t c = 0; c < vertices.Size(); c++) {
        assert(vertices[c].IsArray());

        if (k == -1)
            k = vertices[c].Size();
        else if (vertices[c].Size() != k)
            throw std::runtime_error("inconsistent vector sizes");

        task.vertices.push_back(Matrix<T>::zero(k, 1));

        for (size_t i = 0; i < vertices[c].Size(); i++) {
            if (vertices[c][i].IsNull())
                continue;

            assert(vertices[c][i].IsNumber());
            task.vertices.back().at(i, 0) = vertices[c][i].GetDouble();
        }
    }

    rapidjson::Value &edges = document["edges"];
    assert(edges.IsArray());

    assert(vertices.Size() == edges.Size() + 1);

    for (size_t c = 0; c < edges.Size(); c++) {
        assert(edges[c].IsArray());

        if (edges[c].Size() != k)
            throw std::runtime_error("invalid edge matrix");

        task.edges.push_back(Matrix<T>::zero(k, k));

        for (size_t i = 0; i < edges[c].Size(); i++) {
            if (edges[c][i].Size() != k)
                throw std::runtime_error("invalid edge matrix");

            for (size_t j = 0; j < edges[c][i].Size(); j++) {
                if (edges[c][i][j].IsNull())
                    continue;

                assert(edges[c][i][j].IsNumber());
                task.edges.back().at(i, j) = edges[c][i][j].GetDouble();
            }
        }
    }

    return task;
}

} // namespace label
