#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

int n = 3, num = 6, weyl_ch[6 * 3][3];
//int n = 4, num = 8, weyl_ch[8 * 4][4];

int main() {
    std::freopen("weyl_chambers_b3.txt", "r", stdin);
    std::freopen("hyperplanes_b3.txt", "w", stdout);

    std::set<std::vector<int>> w_ch_edges;

    std::vector<int> vec;
    for (int i = 0; i < num * n; ++i) {
        vec.clear();
        for (int j = 0; j < n; ++j) {
            std::cin >> vec[j];
        }
        w_ch_edges.insert(vec);
    }

    for (auto vec : w_ch_edges) {
        for (int i = 0; i < n; ++i) {
            std::cout << vec[i] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << w_ch_edges.size();
}