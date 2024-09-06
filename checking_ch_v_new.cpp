#include <cstdio>
#include <iostream>

//int n = 2, weyl_ch[8*2][2], vect[8][2];
//int n = 3, weyl_ch[48*3][3], vect[50][3];
int n = 4, weyl_ch[384*4][4], vect[609][4];
//int n = 4, weyl_ch[1152*4][4], vect[16406][4];

bool is_ok1(int k_w_ch, int k_vect) {
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
bool is_ok2(int k_w_ch, int k_vect) {
    int flag = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += -weyl_ch[n * k_w_ch + i][j] * vect[k_vect][j];
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
bool is_ok1_p(int k_w_ch, int k_vect) {
    int flag = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += weyl_ch[n * k_w_ch + i][j] * (-vect[k_vect][j]);
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
bool is_ok2_p(int k_w_ch, int k_vect) {
    int flag = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += -weyl_ch[n * k_w_ch + i][j] * vect[k_vect][j];
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
    freopen("/Users/timuraliev/CLionProjects/untitled/prac/in_b4.txt", "r", stdin);
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
    bool flag = false;
    int step = 0;
    for (int i1 = 1; i1 < 384 - 2; ++i1) {
        if (flag) break;
        for (int i2 = i1 + 1; i2 < 384 - 1; ++i2) {
            if (flag) break;
            for (int i3 = i2 + 1; i3 < 384 - 0; ++i3) {
//                ++step;
//                std::cout << step << '\n';
                bool verd = true;
                bool res = true;
                for (int j = 0; j < 609; ++j) {
                    verd = is_ok1(0, j) || is_ok2(0, j) || is_ok1(i1, j) || is_ok2(i1, j) || is_ok1(i2, j) || is_ok2(i2, j);
                    res = res && verd;
                }
                if (res) {
                    std::cout << 0 << ' ' << i1 << ' ' << i2 << ' ' << i3;
                    flag = true;
                    break;
                }
            }
        }
    }

}
