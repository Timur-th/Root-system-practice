#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> C = {{1, 1, 0, 0}, {2, 1, 1, 0}, {3, 1, 1, 1}, {2, 0, 0, 0}};
int n = 4;

std::vector<int> vec_in_new_basis(std::vector<int>& vec) {
    std::vector<int> new_vec(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            new_vec[i] += C[i][j] * vec[j];
        }
    }
    return new_vec;
}

int main() {
    std::freopen("/Users/timuraliev/CLionProjects/untitled/prac/ch_vectors_f4-4.txt", "r", stdin);
    std::freopen("/Users/timuraliev/CLionProjects/untitled/prac/ch_vectors_f4-simple.txt", "w", stdout);

    std::set<std::vector<int>> res;

    std::vector<int> vec(n);

    for (int i = 0; i < 37872; ++i) {

        for (int j = 0; j < n; ++j) {
            std::cin >> vec[j];
        }

        vec = vec_in_new_basis(vec);
        res.insert(vec);
    }

    for (const auto &iter: res) {
        vec = iter;
        for (int k = 0; k < n; k++) {
            std::cout << vec[k] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << res.size();
}
