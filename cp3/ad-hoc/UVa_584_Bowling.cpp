#include <bits/stdc++.h>

using namespace std;

enum type_t { STRIKE, SPARE, NONE, PADDING };

struct frame {
    type_t type;
    int roll1, roll2;
    int score;
    frame(const type_t t, const int r1, const int r2)
        : type(t), roll1(r1), roll2(r2){}
};

int main() {
    string line;
    getline(cin, line);
    while (line.compare("Game Over") != 0) {
        vector<frame> game{};
        
        int index=0;

        // Parse input string, divide frames
        for (int i=0; i<line.length(); i++) {
            switch (line[i]) {
                case 'X':
                    game.push_back(frame(STRIKE, 10, 0));
                    index++;
                    break;
                case ' ': break; // Space between frames
                default:
                    if (line[i+2] == '/') {
                        game.push_back(frame(SPARE, line[i]-'0', 10-line[i]+'0'));
                    } else { // Two normal rolls
                        game.push_back(frame(NONE, line[i]-'0', (i+2 < line.length() ? line[i+2]-'0' : 0)));
                    }
                    i+=2;
                    index++;
            }
        }

        game.push_back(frame(PADDING, 0, 0)); // PADDING FOR LAST STRIKES AND SPARES
        game.push_back(frame(PADDING, 0, 0)); 
        /*
        for (frame f : game) {
            cout << f.type << " " << f.roll1 << " " << f.roll2 << endl;
        }
        */

        // Compute scores
        int score = 0;
        for (int i=0; i < 10; i++) { // Only first 10 frames actually define score
            //cout << score << endl;
            switch (game[i].type) {
                case STRIKE:
                    score += 10;
                    if (game[i+1].type != STRIKE) score += game[i+1].roll1 + game[i+1].roll2;
                    else score += game[i+1].roll1 + game[i+2].roll1;
                    break;
                case SPARE:
                    score += 10 + game[i+1].roll1;
                    break;
                case NONE:
                    score += game[i].roll1 + game[i].roll2;
                    break;
            }
            
        }

        cout << score << endl;
        getline(cin, line);
    }
    return 0;
}