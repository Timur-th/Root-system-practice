#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <numeric>

//int n = 3, hyplanes[13][3], num = 13;
//int n = 4, hyplanes[40][4], num = 40;
//int n = 4, hyplanes[24][4], num = 24;

long long n = 4, hyplanes[120][4], num = 120;

std::vector<long long> fsr(std::vector<std::vector<long long>> A) {
    int n = A.size() + 1;

    int j = 0;
    int non_zero_num = 0;
    int row = -1;
    while (j < n) {
        bool zero = true;
        for (int i = row + 1; i < n - 1; ++i) {
            zero = zero && (A[i][j] == 0);
            if (!zero) {
                row = i;
                break;
            }
        }
        if (zero) ++j;
        else {
            std::swap(A[non_zero_num], A[row]);
            for (int i = non_zero_num + 1; i < n - 1; ++i) {
                if (A[i][j] != 0) {
                    long long a = A[row][j];
                    long long b = A[i][j];
                    for (int i1 = 0; i1 < n; ++i1) {
                        A[i][i1] = A[i][i1] * a - A[row][i1] * b;
                    }
                }
            }
            ++non_zero_num;
            ++j;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                for (int i1 = i - 1; i1 >= 0; --i1) {
                    if (A[i1][j] != 0) {
                        long long a = A[i1][j];
                        for (int j1 = 0; j1 < n; ++j1) {
                            A[i1][j1] = A[i1][j1] * A[i][j] - A[i][j1] * a;
                        }
                    }
                }
                break;
            }
        }
    }

    long long free = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                free *= A[i][j];
                break;
            }
        }
    }

    std::vector<long long> ans(n);
    std::set<long long> second;
    for (int i = 0; i < n; ++i) {
        second.insert(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int count = 0;
        long long first = 0;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                ++count;
                if (count == 1) {
                    first = A[i][j];
                    second.erase(j);
                }
            }
            if (count > 1) {
                ans[i] = -A[i][j] * free / first;
                break;
            }
        }
        if (count == 1) {
            ans[i] = 0;
        }
    }
    ans[*second.begin()] = free;

    long long gcd = ans[0];
    for (int i = 1; i < n; ++i) {
        gcd = std::gcd(gcd, ans[i]);
    }
    for (int i = 0; i < n; ++i) {
        ans[i] /= gcd;
    }
    return ans;
}


int main() {
    std::freopen("/Users/timuraliev/CLionProjects/untitled/prac/hyperplanes_f4.txt", "r", stdin);
    std::freopen("/Users/timuraliev/CLionProjects/untitled/prac/ch_vectors_f4-4.txt", "w", stdout);

    std::set<std::vector<long long>> result;
    std::vector<std::vector<long long>> A;
    std::vector<long long> first(n, 0), second(n, 0), third(n, 0), ans;
    result.clear();

    int i1, i2, i3;
    for (i1 = 0; i1 < num; i1++) {
        for (i2 = 0; i2 < n; i2++) {
            std::cin >> hyplanes[i1][i2];
        }
    }

    for (i1 = 0; i1 < num - 2; i1++) {
        for (i2 = i1 + 1; i2 < num - 1; i2++) {
            for (i3 = i2 + 1; i3 < num - 0; i3++) {
                {
                    for (int k = 0; k < n; k++) {
                        first[k] = hyplanes[i1][k];
                        second[k] = hyplanes[i2][k];
                        third[k] = hyplanes[i3][k];
                    }
                    A = {first, second, third};
                    ans = fsr(A);
                    result.insert(ans);
                    for (long long & an : ans) {
                        an *= -1;
                    }
                    result.insert(ans);
                }
            }
        }
    }

    for (const auto &iter: result) {
        first = iter;
        for (int k = 0; k < n; k++) {
            std::cout << first[k] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << result.size();
}
