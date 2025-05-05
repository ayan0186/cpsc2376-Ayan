#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <sstream>

class TextFilter {
public:
    virtual std::string apply(const std::string& in) const = 0;
    virtual ~TextFilter() = default;
};

// ───────── concrete filters ─────────
class ReverseFilter : public TextFilter {
public:
    std::string apply(const std::string& in) const override {
        return {in.rbegin(), in.rend()};
    }
};

class UppercaseFilter : public TextFilter {
public:
    std::string apply(const std::string& in) const override {
        std::string out = in;
        std::transform(out.begin(), out.end(), out.begin(),
                       [](unsigned char c){ return std::toupper(c); });
        return out;
    }
};

class RemoveVowelsFilter : public TextFilter {
public:
    std::string apply(const std::string& in) const override {
        std::string out;
        for(char c : in) {
            char lower = static_cast<char>(std::tolower(c));
            if(lower!='a'&&lower!='e'&&lower!='i'&&lower!='o'&&lower!='u')
                out.push_back(c);
        }
        return out;
    }
};

class CensorFilter : public TextFilter {
    static const std::unordered_set<std::string>& badWords() {
        static const std::unordered_set<std::string> words{
            "bad", "ugly", "evil", "stupid", "idiot", "fuck", "shit", "damn"
        };
        return words;
    }
public:
    std::string apply(const std::string& in) const override {
        std::istringstream iss(in);
        std::ostringstream oss;
        std::string word;
        bool first = true;
        while(iss >> word) {
            if(!first) oss << ' ';
            first = false;
            std::string lower = word;
            std::transform(lower.begin(), lower.end(), lower.begin(),
                           [](unsigned char c){ return std::tolower(c); });
            if(badWords().find(lower) != badWords().end())
                oss << "***";
            else
                oss << word;
        }
        return oss.str();
    }
};

// ───────── context ─────────
class Processor {
    std::unique_ptr<TextFilter> filter;
public:
    void setFilter(std::unique_ptr<TextFilter> f) { filter = std::move(f); }
    std::string run(const std::string& in) const {
        return filter ? filter->apply(in) : in;
    }
};

int main() {
    std::cout << "Enter a sentence:\n> ";
    std::string sentence;
    std::getline(std::cin, sentence);

    Processor p;
    char choice{};
    do {
        std::cout << "\nChoose filter:\n"
                  << "1) reverse  2) uppercase  3) remove-vowels  4) censor  q) quit\n> ";
        std::cin >> choice;
        
        if (choice == '1') {
            p.setFilter(std::make_unique<ReverseFilter>());
        }
        else if (choice == '2') {
            p.setFilter(std::make_unique<UppercaseFilter>());
        }
        else if (choice == '3') {
            p.setFilter(std::make_unique<RemoveVowelsFilter>());
        }
        else if (choice == '4') {
            p.setFilter(std::make_unique<CensorFilter>());
        }
        else if (choice == 'q' || choice == 'Q') {
            continue;        // go back to the menu loop
        }
        else {
            std::cout << "Invalid option\n";
            continue;        // ask again
        }        
        std::cout << p.run(sentence) << '\n';
    } while(choice!='q'&&choice!='Q');

}
