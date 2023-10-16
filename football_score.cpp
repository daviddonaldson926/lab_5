#include <iostream>
#include <vector>

void findCombinations(int score) {
    std::cout << "possible combinations of scoring plays:" << std::endl;
    // Define the points for each type of score
    const int TD_6 = 6;  // Touchdown
    const int TD_7 = 7;  // Touchdown + 1-point field goal
    const int TD_8 = 8;  // Touchdown + 2-point conversion
    const int FG = 3;    // Field goal
    const int SAFETY = 2; // Safety

    // Check all combinations
    for (int td_8 = 0; td_8 <= score / TD_8; ++td_8) {
        for (int td_7 = 0; td_7 <= score / TD_7; ++td_7) {
            for (int td_6 = 0; td_6 <= score / TD_6; ++td_6) {
                for (int fg = 0; fg <= score / FG; ++fg) {
                    for (int safety = 0; safety <= score / SAFETY; ++safety) {
                        if (td_8 * TD_8 + td_7 * TD_7 + td_6 * TD_6 + fg * FG + safety * SAFETY == score) {
                            std::cout << td_8 << " TD + 2pt, " << td_7 << " TD + FG, " << td_6 << " TD, " << fg << " 3pt FG, " << safety << " Safety" << std::endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    std::cout << "Enter 0 or 1 to STOP" << std::endl;
    do {
        std::cout << "Enter the NFL score: ";
        std::cin >> score;
        if (score > 1) {
            findCombinations(score);
        }
    } while (score > 1);

    return 0;
}
