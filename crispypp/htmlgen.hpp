#ifndef HTMLGEN_HPP
#define HTMLGEN_HPP

#include <string>
#include <vector>
#include "smartfile.hpp"

namespace crs {
    struct htmltag {
        std::string name;
        std::string attr;
        std::string value;
        std::vector<htmltag> tags;
    };

    class htmldocument {
    public:
        std::string document_type;

        htmldocument(const std::initializer_list<htmltag> tags) : tags(tags) {}

        std::string compile() {
            result.clear(); // Сброс результата перед компиляцией
            for (const auto& tag : tags) {
                _compile(tag);
            }
            return result;
        }

        void save2(const std::string& path) {
            smartfile file(path);
            file.write(compile());
        }

    private:
        void _compile(const htmltag &tag) {
            result += "<" + tag.name;
            if (!tag.attr.empty()) {
                result += " " + tag.attr;
            }
            result += ">\n";
            if (!tag.value.empty()) {
                result += tag.value;
            }
            for (const auto& under_tag : tag.tags) {
                _compile(under_tag);
            }
            result += "</" + tag.name + ">\n";
        }

        std::string result;
        std::vector<htmltag> tags;
    };
}

#endif // HTMLGEN_HPP
