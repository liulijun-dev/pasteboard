#ifndef PASTEBOARD_H_INCLUDED
#define PASTEBOARD_H_INCLUDED
#pragma once

#include <string>
#include <boost/operators.hpp>
#include <string_view>
#include <boost/optional.hpp>

using namespace std;

class Pasteboard
{
public:
    const string readPasteboard();

    bool copy2Pasteboard(const string &file);

    void preview(const string &file);

    void copy2Output(const string &file);

    void clear();

private:
    const boost::optional<string> readFileContent(const string &file);
};

extern string_view must_set_file;
extern string_view unknown_error;

#endif