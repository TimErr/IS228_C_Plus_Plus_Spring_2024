#include <iostream>
#include "CPPVerbalExpressions/verbalexpressions.hpp"

int main() {
    using verex::verex;
    // Build the regular expression using human-like commands
    verex expr = verex()
         .find("http")
         .maybe("s")
         .then("://")
         .maybe("www.")
         .anything_but(" ")
         .end_of_line();

    // Test if a string matches the regular expression
    std::string url = "https://www.example.com";
    if (expr.test(url)) {
        std::cout << url << std::endl;
        std::cout << "That looks like a valid URL!" << std::endl;
    } else {
        std::cout << "Hmm, that doesn't seem to be a valid URL." << std::endl;
    }

    return 0;
}