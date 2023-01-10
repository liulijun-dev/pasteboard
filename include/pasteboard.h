#ifndef C2P_H_INCLUDED
#define C2P_H_INCLUDED
#pragma once

#include <string>
#include <boost/operators.hpp>

using namespace std;

class Pasteboard
{
public:
    explicit Pasteboard(const string &file) : file(file)
    {
    }

    static const string readPasteboard();

    bool copy2Pasteboard();

private:
    string file;

    const boost::optional<string> readFileContent();
};

#endif