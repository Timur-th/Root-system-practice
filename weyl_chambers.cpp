#include <iostream>
#include <cstdio>

int n = 3, weyl_ch[6 * 3][3], num = 6 * 3, base[3][3], some[3][3];
//int n = 3, weyl_ch[6*2][3], num = 6*2, base[2][3], some[2][3];
//int n = 3, weyl_ch[48*3][3], num = 48*3, base[3][3], some[3][3];
//int n = 4, weyl_ch[384*4][4], num = 384*4, base[4][4], some[4][4];
//int n = 4, weyl_ch[192*4][4], num = 192*4, base[4][4], some[4][4];


void prop(int k) {
    int flag;
    for (int div = 100; div > 1; div--) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (some[k][i] % div == 0) {
                flag++;
            }
        }
        if (flag == n) {
            for (int i = 0; i < n; i++) some[k][i] /= div;
            return;
        }
    }
}


int main() {
    std::freopen("b3.txt", "r", stdin);
    std::freopen("weyl_chambers_b3.txt", "w", stdout);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> base[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> weyl_ch[i][j];
            std::cout << weyl_ch[i][j] << ' ';
        }
        std::cout << '\n';
    }


    int end = n;
    int curr = 0;
    int a, b;
    int flag, flag_m;

    while (curr < end) {
        for (int k = 0; k < n; ++k) {
            a = 0;
            for (int i = 0; i < n; ++i) {
                a += base[k][i] * base[k][i];
            }
            for (int i = 0; i < n; ++i) {
                b = 0;
                for (int j = 0; j < n; ++j) {
                    b += weyl_ch[curr + i][j] * base[k][j];
                }
                for (int j = 0; j < n; ++j) {
                    some[i][j] = weyl_ch[curr + i][j] - 2 * base[k][j] * b / a;
                }
                prop(i);
            }
            flag_m = 0;
            for (int i = 0; i < end; i += n) {
                flag = 0;
                for (int j = 0; j < n; ++j) {
                    for (int l = 0; l < n; ++l) {
                        if (some[j][l] == weyl_ch[i + j][l]) {
                            flag++;
                        }
                    }
                }

                if (flag_m < flag) {
                    flag_m = flag;
                }
            }

            if (flag_m < n * n) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        weyl_ch[end + i][j] = some[i][j];
                        std::cout << some[i][j] << ' ';
                    }
                    std::cout << '\n';
                }
                end += n;
            }
        }
        curr += n;
    }
    std::cout << end;
    return 0;
}
