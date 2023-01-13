#include <array>
#include <string_view>

using namespace std;

class ConsoleColor
{
private:
    static std::array<std::pair<std::string_view, std::string_view>, 8> colors;

public:
    static std::string replaceColors(const std::string_view &str);
};

std::array<std::pair<std::string_view, std::string_view>, 8> ConsoleColor::colors = {{{"{red}", "\033[38;5;196m"},
                                                                                      {"{green}", "\033[38;5;40m"},
                                                                                      {"{yellow}", "\033[38;5;214m"},
                                                                                      {"{blue}", "\033[38;5;51m"},
                                                                                      {"{orange}", "\033[38;5;208m"},
                                                                                      {"{pink}", "\033[38;5;219m"},
                                                                                      {"{bold}", "\033[1m"},
                                                                                      {"{blank}", "\033[0m"}}};

std::string ConsoleColor::replaceColors(const std::string_view &str)
{
    std::string temp(str); // a string to do scratch work on
    for (const auto &key : colors)
    { // iterate over all the possible colors to replace
        for (int i = 0; (i = temp.find(key.first, i)) != std::string::npos; i += key.second.length())
        {
            temp.replace(i, key.first.length(), key.second);
        }
    }
    return temp;
}