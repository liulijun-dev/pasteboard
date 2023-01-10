#ifndef C2P_H_INCLUDED
#define C2P_H_INCLUDED
#pragma once

#include <string>
#include <boost/operators.hpp>

using namespace std;

class Pasteboard
{
public:
    const string readPasteboard();

    bool copy2Pasteboard(const string &file);

    void preview(const string &file);

    void copy2Output(const string &file);

private:
    const boost::optional<string> readFileContent(const string &file);
};

#endif