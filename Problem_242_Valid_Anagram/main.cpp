#include <iostream>
#include <string>

bool isAnagram(std::string s, std::string t) {
    int num = 0;
    for (auto c : s) {
        auto index = t.find_first_of(c);
        if (index == std::string::npos)
            return false;
        t.erase(t.begin() + index);
    }
    return t.empty();
}

int main(int argc, char **argv)
{
	std::cout << isAnagram("anagram", "nagaram");
    std::cin.get();
	return 0;
}
