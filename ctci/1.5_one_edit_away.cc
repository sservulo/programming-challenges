#include<iostream>
using std::string;

bool OneAway(string s1, string s2);
bool ReplaceEdit(string s1, string s2);
bool OneEdit(string s1, string s2);

bool OneAway(string s1, string s2) {
    if (s1.size() == s2.size()) {return ReplaceEdit(s1, s2);}
    if (s1.size() == s2.size() - 1) {return OneEdit(s1, s2);}
    if (s1.size() - 1 == s2.size()) {return OneEdit(s2, s1);}
    return false;
}

bool ReplaceEdit(string s1, string s2) {
    for (size_t idx = 0; idx < s1.size(); idx++) {
        if (s1[idx] != s2[idx]) {
            s2[idx] = s1[idx];
            if (s1 == s2) {return true;}
            break;
        }
    }
    return false;
}

bool OneEdit(string s1, string s2) {
    for (int idx = 0; idx < s1.size(); idx++) {
        if (s1[idx] != s2[idx]) {
            s1.insert(idx, 1, s2[idx]);
            if (s1 == s2) {return true;}
            break;
        }
    }
    return false;
}

int main() {
  string s1 = "tacot";
  string s2 = "taco";
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << OneAway(s1, s2) << std::endl;
  return 0;
}
