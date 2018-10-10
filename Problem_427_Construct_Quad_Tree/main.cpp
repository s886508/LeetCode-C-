#include <iostream>
#include <vector>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* createTree(std::vector<std::vector<int>>& grid, int start_row, int start_col, int size) {
    int sum = 0;
    for (int row = start_row; row < (start_row + size); row++) {
        for (int col = start_col; col < (start_col + size); col++) {
            sum += grid[row][col];
        }
    }
    
    if (sum == size * size || sum == 0)
        return new Node((bool)sum, true, nullptr, nullptr, nullptr, nullptr);
    
    auto new_size = size / 2;
    Node* tl = createTree(grid, start_row, start_col, new_size);
    Node* tr = createTree(grid, start_row, start_col + new_size, new_size);
    Node* bl = createTree(grid, start_row + new_size, start_col, new_size);
    Node* br = createTree(grid, start_row + new_size, start_col + new_size, new_size);
    return new Node((bool)sum, false, tl, tr, bl, br);
}

Node* construct(std::vector<std::vector<int>>& grid) {
    return createTree(grid, 0, 0, grid.size());
}

int main(int argc, char **argv)
{
    std::vector<std::vector<int>> v = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    auto node = construct(v);
    std::cin.get();
	return 0;
}
