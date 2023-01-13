#include <boost/program_options.hpp>

namespace po = boost::program_options;

#include <iostream>
#include <iterator>
#include "pasteboard.h"
#include "console_color.h"

using namespace std;

int main(int ac, char ** av)
{
    try {
        int opt;
        int portnum;
        po::options_description optionsDesc("Allowed options");
        optionsDesc.add_options()
            ("help,h", "show help message")
            ("preview,p", "preview copy to paster content")
            ("show,s", "show paster content")
            ("clear,c", "clear pasteboard content, donot execute any other options if you specified them")
            ("file,f", po::value<string>(), "input file")
            ("output,o", po::value<string>(), "output file")
        ;

        po::positional_options_description positionalOptionsDesc;
        positionalOptionsDesc.add("file", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(ac, av).options(optionsDesc).positional(positionalOptionsDesc).run(), vm);
        po::notify(vm);

        if (vm.count("help")) {
            cout << "Usage: pb [options] [-f] file\n";
            cout << optionsDesc;
            return 0;
        }

        Pasteboard pasteboard;

        if (vm.count("clear")) {
            pasteboard.clear();
            return 0;
        }

        if (vm.count("preview")) {
            if (vm.count("file") == 0) {
                printf("%s\n", ConsoleColor::replaceColors(must_set_file).data());
                return -1;
            }
            pasteboard.preview(vm["file"].as<string>());
            return 1;
        }

        if (vm.count("file")) {
            pasteboard.copy2Pasteboard(vm["file"].as<string>());
        }

        if (vm.count("show")) {
            const string result = pasteboard.readPasteboard();
            cout<<result<<endl;
        }

        if (vm.count("output")) {
            pasteboard.copy2Output(vm["output"].as<string>());
        }
        
    }
    catch(std::exception& e)
    {
        printf(ConsoleColor::replaceColors(unknown_error).data(), e.what());
        return -1;
    }

    return 0;
}
