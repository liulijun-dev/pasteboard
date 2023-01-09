#include <iostream>
#include <fstream>
#include <string>
#include <boost/optional.hpp>

#include "c2p.h"
#include "clip.h"

using namespace std;

const boost::optional<string> C2P::readContent()
{
    string result;
    string line;
    ifstream inputFileStream(file);
    if (inputFileStream.is_open())
    {
        while (getline(inputFileStream, line))
        {
            result += line + "\n";
        }
        inputFileStream.close();
        return boost::optional<string>(result);
    }
    else
    {
        return boost::none;
    }
}

bool C2P::copy2Paster()
{
    boost::optional<string> fileContent = readContent();
    if (fileContent == boost::none)
    {
        cout << "read file content error: file not exist or cannot open" << endl;
        return false;
    }
    clip::set_text(fileContent.value());
    return true;
}

const string C2P::readPaster() {
    string result;
    clip::get_text(result);
    return result;
}