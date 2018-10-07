#include <iostream>
#include <string>

std::string reverseOnlyLetters(std::string S);

int main(int argc, char **argv) {
    std::cout << reverseOnlyLetters("ab-cd") << std::endl;
    std::cout << reverseOnlyLetters("a-bC-dEf-ghIj") << std::endl;
    std::cout << reverseOnlyLetters("Test1ng-Leet=code-Q!") << std::endl;
    std::cout << reverseOnlyLetters("") << std::endl;
    std::cin.get();
	return 0;
}

std::string reverseOnlyLetters(std::string S) {
    auto isLetter = [&](char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };
    int size = S.size();
    int front = 0, back = size - 1;
    do {
        auto is_letter_front = isLetter(S[front]);
        auto is_letter_back = isLetter(S[back]);
        if (is_letter_front && is_letter_back) {
            std::swap(S[front], S[back]);
            front++;
            back--;
            continue;
        }
        
        if (is_letter_front)
            back--;
        else
            front++;
    } while (front < back);
    
    return S;
}