#ifndef C2P_H_INCLUDED
#define C2P_H_INCLUDED
#pragma once

#include <string>
#include <boost/operators.hpp>

using namespace std;

class C2P
{
public:
    explicit C2P(const string &file) : file(file)
    {
    }

    static const string readPaster();

    bool copy2Paster();

private:
    string file;

    const boost::optional<string> readContent();
};

#endif