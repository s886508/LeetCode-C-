#include <iostream>
#include <map>

int rotatedDigits(int N);
bool isGoodNumber(int X);

int main(int argc, char **argv)
{
    std::cout << rotatedDigits(10);
    std::cin.get();
	return 0;
}

int rotatedDigits(int N) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (isGoodNumber(i))
            cnt++;
    }
    return cnt;
}
    
bool isGoodNumber(int X) {
    static std::map<int, int> rotate = { {0, 0}, {1, 1}, {2, 5}, {5, 2}, {6, 9}, {8, 8}, {9 ,6} };
    int newX = 0, oldX = X;
    int ratio = 1;
    while (X > 0) {
        auto d = X % 10;
        if (rotate.count(d) == 0)
            return false;
        X /= 10;
        newX += rotate[d] * ratio;
        ratio *= 10;
    }
    
    return newX != oldX;
}