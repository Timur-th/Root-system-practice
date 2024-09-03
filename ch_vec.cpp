#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>


//int n = 3, hyplanes[13][3], num = 13;
int n = 4, hyplanes[40][4], num = 40;
//int n = 4, hyplanes[24][4], num = 24;
//long long n = 4, hyplanes[120][4], num = 120;

std::vector<long long> Solve(std::vector<std::vector<long long>> A) {
    int count = 0, number = 0;
    int size = A.size();
    int some;
    std::vector<long long> ans(size + 1, 0);
    std::vector<long long> cont1, cont2;
    int k = 0;
    bool f = false;
    for (int i = 0; i < size + 1; ++i) {
        if (A[k][i] == 0) {
            f = true;
            for (int j = k + 1; j < size; ++j) {
                if (A[j][i] != 0) {
                    f = false;
                    cont1 = A[i];
                    cont2 = A[j];
                    A[i].swap(cont2);
                    A[j].swap(cont1);
                }
            }
        }
        if (f) {
            f = false;
            count++;
            number = i;
        } else {
            for (int j = 0; j < size; j++) {
                if (j != k) {
                    some = A[j][i];
                    for (int q = 0; q <= size; q++) {
                        A[j][q] = A[j][q] * A[k][i] - some * A[k][q];
                    }
                }
            }
            if (k < size - 1) {
                k++;
            } else break;
        }
    }
    if (count == 1) ans[number] = 1;
    {
        if (number == 0) {
            int prod = A[0][0];
            for (int i = 1; i < size; i++) {
                prod *= A[i][i];
            }
            for (int i = 0; i < size; i++) {
                ans[i] = (-A[i][size] * prod) / A[i][i];
            }
            ans[size] = prod;
            int min = abs(prod);
            for (int i = 0; i <= size; i++) {
                if (abs(ans[i]) > 0) min = abs(ans[i]);
            }
            for (int i = 0; i <= size; i++) {
                if (abs(ans[i]) > 0 && abs(ans[i]) < min) min = abs(ans[i]);
            }
            for (int i = min; i > 1; i--) {
                f = true;
                for (int j = 0; j <= size; j++) {
                    if (ans[j] % i != 0) f = false;
                }
                if (f) {
                    for (int j = 0; j <= size; j++) ans[j] = ans[j] / i;
                    break;
                }
            }
        }
    }

    int i = 0;
    while (ans[i] == 0) {
        i++;
    }
    if (ans[i] < 0) {
        for (int j = 0; j <= size; j++)
            ans[j] *= -1;
    }
    return ans;
}


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
        for (int k = 0; k < n; k++) std::cout << dim1[k] << ' ';
        std::cout << '\n';
    }
    std::cout << result.size();
    return 0;
}
