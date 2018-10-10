#include <iostream>
#include <string>

bool isAnagram(std::string s, std::string t) {
//    Version 1
//    int num = 0;
//    for (auto c : s) {
//        auto index = t.find_first_of(c);
//        if (index == std::string::npos)
//            return false;
//        t.erase(t.begin() + index);
//    }
//    return t.empty();
    
    // Version 2
    int cnt[26] = {0};
    for (auto c : s)
        cnt[c - 'a']++;
    for (auto c : t)
        cnt[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0)
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
	std::cout << isAnagram("anagram", "nagaram");
    std::cin.get();
	return 0;
}
