### Задание 49. Кратчайший путь в матрице

**Вопрос.** В матрице из нулей и единиц найдите минимальное число шагов от верхнего левого угла до нижнего правого. Единицы — препятствия; перемещение разрешено по четырём направлениям. Если пути нет, выведите `-1`.

**Правильный ответ:** правильный ответ — приведённая ниже реализация.

**Объяснение:** BFS обходит клетки слоями расстояния. Временная и пространственная сложности — `O(R·C)`.

**Листинг программы:**

```cpp
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    if (rows <= 0 || cols <= 0) return 1;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (auto& row : grid) {
        for (int& cell : row) {
            cin >> cell;
            if (cell != 0 && cell != 1) return 1;
        }
    }

    if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    const array<int, 4> dr = {-1, 1, 0, 0};
    const array<int, 4> dc = {0, 0, -1, 1};

    // BFS находит кратчайший путь в невзвешенной сетке.
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (grid[nr][nc] == 1 || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    cout << dist[rows - 1][cols - 1] << '\n';
    return 0;
}
```
