#include <iostream>
#include <vector>
#include <algorithm>

int smallestRangeI(std::vector<int>& A, int K) {
    auto minmax = std::minmax_element(A.begin(), A.end());
    return std::max(0, *minmax.second - *minmax.first - 2 * K);
}

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 5, 4, 8, 10};
	std::cout << smallestRangeI(v, 4) << std::endl;
    std::cin.get();
	return 0;
}
