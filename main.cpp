#include <iostream>
#include "ext/clip/clip.h"

int main(int, char **)
{
    std::cout << "Hello, world!\n";
    clip::format my_format =
        clip::register_format("com.appname.FormatName");

    int value = 32;
    clip::set_text("Hello World112\n haha");

    // clip::lock l;
    // l.clear();
    // l.set_data(clip::text_format(), "Alternative text for value 32");
    // l.set_data(my_format, &value, sizeof(int));
}
