#include <iostream>

using namespace std;

char b[10] = {'0','1','2','3','4','5','6','7','8','9'};

void d() {
    system("clear"); 
    cout << b[1] << "|" << b[2] << "|" << b[3] << "\n-+-+-\n"
         << b[4] << "|" << b[5] << "|" << b[6] << "\n-+-+-\n"
         << b[7] << "|" << b[8] << "|" << b[9] << "\n";
}

int w() {
    if (b[1] == b[2] && b[2] == b[3]) return 1;
    if (b[4] == b[5] && b[5] == b[6]) return 1;
    if (b[7] == b[8] && b[8] == b[9]) return 1;
    if (b[1] == b[4] && b[4] == b[7]) return 1;
    if (b[2] == b[5] && b[5] == b[8]) return 1;
    if (b[3] == b[6] && b[6] == b[9]) return 1;
    if (b[1] == b[5] && b[5] == b[9]) return 1;
    if (b[3] == b[5] && b[5] == b[7]) return 1;
    return 0;
}

int main() {
    int p = 1, s, i;
    char m;
    for (i = 0; i < 9; i++) {
        d();
        p = (i % 2 == 0) ? 1 : 2;
        m = (p == 1) ? 'X' : 'O';
        cout << "Player " << p << " (" << m << "), enter slot: ";
        cin >> s;
        if (s < 1 || s > 9 || b[s] == 'X' || b[s] == 'O') {
            i--;
            continue;
        }
        b[s] = m;
        if (w()) {
            d();
            cout << "Player " << p << " wins!";
            return 0;
        }
    }
    d();
    cout << "Tie!";
    return 0;
}