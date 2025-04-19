#include <iostream>
#include "../crispypp/htmlgen.hpp"

int main() {
    crs::htmldocument doc = {
        {"html", "", "", {
                    {"head", "", "", {
                        {"title", "", "My Document", {}}
                    }},
                    {"body", "", "", {
                        {"h1", "", "Hello World", {}},
                        {"p", "class='text'", "This is a paragraph.", {}}
                    }}
        }}
    };

    std::cout << doc.compile() << "\n";

    return 0;
}
