#include <vector>

std::vector<std::vector<int>> pascal_triangle(int numRows) {
    std::vector<std::vector<int>> rows = {{1}, {1, 1}};

    if (numRows == 1) {
        return {rows[0]};
    }
    if (numRows == 2) {
        return rows;
    }

    for (int i = 2; i < numRows; i++) {
        // every row starts with 1
        std::vector<int> row = {1};

        // add sum of the j-th and j+1 element of the row above to the current row
        for (int j = 0; j < i-1; j++) {
            row.push_back(rows[i-1][j] + rows[i-1][j+1]);
        }

        // every row ends with 1
        row.push_back(1);
        // and push row to the "triangle"
        rows.push_back(row);
    }

    return rows;
}
