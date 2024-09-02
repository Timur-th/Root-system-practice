#include <iostream>
#include <cstdio>

int n = 3, weyl_ch[48 * 3][3], base[3][3], some[3][3];
//int n = 4, weyl_ch[384*4][4], base[4][4], some[4][4];
//int n = 4, weyl_ch[192*4][4], base[4][4], some[4][4];
//int n = 4, weyl_ch[1152*4][4], base[4][4], some[4][4];

void prop(int number) {
    int f;
    for (int div = 60; div > 1; div--) {
        f = 0;
        for (int i = 0; i < n; i++) {
            if (some[number][i] % div == 0) {
                f++;
            }
        }
        if (f == n) {
            for (int i = 0; i < n; i++) {
                some[number][i] /= div;
            }
        }
    }
}


int main() {
    std::freopen("/Users/timuraliev/CLionProjects/untitled/prac/b3.txt", "r", stdin);
    std::freopen("/Users/timuraliev/CLionProjects/untitled/prac/weyl_chambers_b3.txt", "w", stdout);

    int alpha, beta;
    int last, curr = 0;
    int f, f1;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> base[i][j];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> weyl_ch[i][j];
            std::cout << weyl_ch[i][j] << ' ';
        }
        std::cout << '\n';
    }
    last = n;
    while (curr < last) {
        for (int k = 0; k < n; k++) {
            alpha = 0;
            for (int i = 0; i < n; i++) {
                alpha += base[k][i] * base[k][i];
            }
            for (int i = 0; i < n; i++) {
                beta = 0;
                for (int j = 0; j < n; j++) {
                    beta += weyl_ch[curr + i][j] * base[k][j];
                }
                for (int j = 0; j < n; j++) {
                    some[i][j] = weyl_ch[curr + i][j] - 2 * base[k][j] * beta / alpha;
                }
                prop(i);
            }
            f1 = 0;
            for (int i = 0; i < last; i += n) {
                f = 0;
                for (int j = 0; j < n; j++)
                    for (int l = 0; l < n; l++) {
                        if (some[j][l] == weyl_ch[i + j][l]) {
                            f++;
                        }
                    }
                if (f1 < f) f1 = f;
            }
            if (f1 < n * n) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        weyl_ch[last + i][j] = some[i][j];
                        std::cout << some[i][j] << ' ';
                    }
                    std::cout << '\n';
                }
                last += n;
            }
        }
        curr += n;
    }
    std::cout << last;
}
