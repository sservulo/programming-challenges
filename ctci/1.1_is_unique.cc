#include<iostream>
#include<unordered_map>
using std::string;

bool IsUnique(const string& s) {
    if (s.size() > 128) {return false;}

    std::unordered_map<char, int> hash;
    for (auto c : s) {
        if (++hash[c] > 1) {return false;}
    }
    return true;
}

int main() {
    string s = "qwertyuio";
    std::cout << IsUnique(s) << std::endl;
    return 0;
}
