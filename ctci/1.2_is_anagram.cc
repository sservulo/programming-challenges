#include<iostream>
#include<unordered_map>
using std::string;

bool IsAnagram(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {return false;}

    std::unordered_map<char, int> hash;
    for (auto c : s1) {
        hash[c]++;
    }
    for (auto c : s2) {
        hash[c]--;
    }
    for (const auto& iterator : hash) {
        if (iterator.second != 0) {return false;}
    }
    return true;
}

int main() {
    string s1 = "potato";
    string s2 = "topato";
    std::cout << IsAnagram(s1, s2) << std::endl;
    return 0;
}
