#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>


//int n = 3, hyplanes[13][3], num = 13;
int n = 4, hyplanes[40][4], num = 40;
//int n = 4, hyplanes[24][4], num = 24;
//long long n = 4, hyplanes[120][4], num = 120;


int main() {
    std::freopen("hyperplanes_b3.txt", "r", stdin);
    std::freopen("ch_vectors_b3.txt", "w", stdout);

    std::set<std::vector<long long>> result;
    std::vector<std::vector<long long>> A;
    std::vector<long long> dim1(n, 0), dim2(n, 0), dim3(n, 0), ans;
    result.clear();

    for (int i1 = 0; i1 < num; i1++) {
        for (i2 = 0; i2 < n; i2++) {
            std::cin >> hyplanes[i1][i2];
        }
    }

    for (int i1 = 0; i1 < num - 1; i1++) {
        for (int i2 = i1 + 1; i2 < num; i2++) {
//            for (int i3 = i2 + 1; i3 < num; i3++) {
                {
                    for (int k = 0; k < n; k++) {
                        dim1[k] = hyplanes[i1][k];
                        dim2[k] = hyplanes[i2][k];
//                        dim3[k] = hyplanes[i3][k];
                    }
                    A = {dim1, dim2};
                    ans = Solve(A);
                    result.insert(ans);
//                }
            }
        }
    }
    for (const auto & iter : result) {
        dim1 = iter;
        for (int k = 0; k < n; k++) {
            std::cout << dim1[k] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << result.size();
    return 0;
}
