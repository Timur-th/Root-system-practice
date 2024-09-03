#include <cstdio>
#include <iostream>

//int n = 2, weyl_ch[8*2][2], vect[8][2];
int n = 3, weyl_ch[48*3][3], vect[50][3];

bool is_ok(int k_w_ch, int k_vect) {
    int flag = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += weyl_ch[n * k_w_ch + i][j] * vect[k_vect][j];
        }
        if (sum > 0) {
            flag++;
        } else if (sum < 0) {
            flag--;
        }
    }
    if (flag == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("/Users/timuraliev/CLionProjects/untitled/prac/in_b2.txt", "r", stdin);
//    freopen("/Users/timuraliev/CLionProjects/untitled/prac/sep_syst_b3_orb.txt", "w", stdout);

    for (auto & i : weyl_ch) {
        for (int & j : i) {
            std::cin >> j;
        }
    }

    for (auto & i : vect) {
        for (int & j : i) {
            std::cin >> j;
        }
    }

    for (int i1 = 0; i1 < 8 - 2; ++i1) {
        for (int i2 = i1 + 1; i2 < 8 - 1; ++i2) {
            for (int i3 = i2 + 1; i3 < 8 ; ++i3) {
//                for (int i4 = i3 + 1; i4 < 8; ++i4) {
//                    for (int i5 = i4 + 1; i5 < 48 - 5; ++i5) {
//                        for (int i6 = i5 + 1; i6 < 48 - 5; ++i6) {

                            bool res = true;
                            for (int j = 0; j < 8; ++j) {
                                bool verd = (is_ok(i1, j) || is_ok(i2, j) || is_ok(i3, j));
                                res = res && verd;
                            }
                            if (res) {
                                std::cout << "Yes" << '\n';
//                                cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << ' ' << i5 << ' ' << i6;
//                            }
//                        }
//                    }
                }
            }
        }
    }
}
