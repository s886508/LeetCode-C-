#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    auto size = prices.size();
    if (size == 0)
        return 0;
        
    int profit = 0, mx = prices[0], mn = prices[0];
    for (size_t i = 1; i < size; i++) {
        if (prices[i] - prices[i - 1] < 0) {
            profit += mx - mn;
            mx = mn = prices[i];
        }
        mx = std::max(mx, prices[i]);
        mn = std::min(mn, prices[i]);
    }
    return std::max(profit, profit + mx - mn);
}

int main(int argc, char **argv)
{
	std::vector<int> v = {7,6,4,3,1};
    std::cout << maxProfit(v);
    std::cin.get();
	return 0;
}
