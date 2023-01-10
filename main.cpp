#include <boost/program_options.hpp>

namespace po = boost::program_options;

#include <iostream>
#include <iterator>
#include "clip.h"
#include "pasteboard.h"

using namespace std;

// A helper function to simplify the main part.
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    return os;
}

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
            ("file,f", po::value<string>(), "input file")
            ("output,o", po::value<string>(), "output file")
            // ("optimization", po::value<int>(&opt)->default_value(10),
            //       "optimization level")
            // ("verbose,v", po::value<int>()->implicit_value(1),
            //       "enable verbosity (optionally specify level)")
            // ("listen,l", po::value<int>(&portnum)->implicit_value(1001)
            //       ->default_value(0,"no"),
            //       "listen on a port.")
            // ("include-path,I", po::value< vector<string> >(),
            //       "include path")
            // ("input-file", po::value< vector<string> >(), "input file")
        ;

        po::positional_options_description positionalOptionsDesc;
        positionalOptionsDesc.add("file", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(ac, av).options(optionsDesc).positional(positionalOptionsDesc).run(), vm);
        po::notify(vm);

        if (vm.count("help")) {
            cout << "Usage: c2p [ps] [-f] file\n";
            cout << optionsDesc;
            return 0;
        }

        if (vm.count("include-path"))
        {
            cout << "Include paths are: "
                 << vm["include-path"].as< vector<string> >() << "\n";
        }

        if (vm.count("input-file"))
        {
            cout << "Input files are: "
                 << vm["input-file"].as< vector<string> >() << "\n";
        }

        if (vm.count("verbose")) {
            cout << "Verbosity enabled.  Level is " << vm["verbose"].as<int>()
                 << "\n";
        }

        cout << "Optimization level is " << opt << "\n";

        cout << "Listen port is " << portnum << "\n";

        // if (vm.count("preview")) {
        //     if (vm.count("file") == 0) {
        //         cout<<"please specify file"<<endl;
        //         return 0;
        //     }

        // }

        if (vm.count("file")) {
            Pasteboard pasteboard(vm["file"].as<string>());
            pasteboard.copy2Pasteboard();
        }

        if (vm.count("show")) {
            const string result = Pasteboard::readPasteboard();
            cout<<result<<endl;
        }
        
    }
    catch(std::exception& e)
    {
        cout << e.what() << "\n";
        return 1;
    }

    return 0;
    // std::cout << "Hello, world!\n";
    // clip::format my_format =
    //     clip::register_format("com.appname.FormatName");

    // int value = 32;
    // clip::set_text("Hello World112\n haha");

    // clip::lock l;
    // l.clear();
    // l.set_data(clip::text_format(), "Alternative text for value 32");
    // l.set_data(my_format, &value, sizeof(int));
}
