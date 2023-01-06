#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int global_answer = 0;


void full_zero(int ( &desk )[8][8]){
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            desk[i][j] = 0;
}

void print(int ( &desk )[8][8]){
    cout << endl << endl;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << desk[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

map<string, pair<int, int>> scan_queens(int ( &desk )[8][8]){
    map <string, pair<int, int>> res;
    int queen_num = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (desk[i][j] == 1){
                res.insert({"Queen_" + to_string(queen_num), make_pair(i, j)});
                queen_num++;
            }
        }
    }
    return res;
}

bool correct_pos(int ( &desk )[8][8], int ferz){
    if (ferz <= 1) return true;
    map <string, pair<int, int>> pos = scan_queens(desk);
    /*
    for (auto& [key, value] : pos){
        cout << key << ": " << value.first << ", " << value.second << endl;
    }
    */
    bool answer = true;
    for (auto& [key1, value1] : pos){
        if (answer == false) break;
        for (auto& [key2, value2] : pos){

            if ((value1.first == value2.first) && (key1 != key2)) { answer = false; break; }
            if ((value1.second == value2.second) && (key1 != key2)) { answer = false; break; }
            if ((key1 != key2) &&
                (abs(value1.first - value2.first) == abs(value1.second - value2.second))) {
                answer = false; break;
            }
        }
    }
    if (answer && ferz == 8){
        print(desk);
        global_answer++;
    }
    return answer;
}

int main(){
    int desk[8][8];
    full_zero(desk);

    for (int a = 0; a < 8; a++){
        for (int b = 8; b < 16; b++){
            for (int c = 16; c < 24; c++){
                for (int d = 24; d < 32; d++){
                    for (int e = 32; e < 40; e++){
                        for (int f = 40; f < 48; f++){
                            for (int g = 48; g < 56; g++){
                                for (int h = 56; h < 64; h++){
                                    full_zero(desk);
                                    desk[a / 8][a % 8] = 1;
                                    desk[b / 8][b % 8] = 1;
                                    desk[c / 8][c % 8] = 1;
                                    desk[d / 8][d % 8] = 1;
                                    desk[e / 8][e % 8] = 1;
                                    desk[f / 8][f % 8] = 1;
                                    desk[g / 8][g % 8] = 1;
                                    desk[h / 8][h % 8] = 1;
                                    correct_pos(desk, 8);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "ANSWER: " << global_answer << endl;
    return 0;
}
