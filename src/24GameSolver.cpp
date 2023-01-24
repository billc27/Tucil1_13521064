// 24-Game Solver
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

string intToStr (int a) {
    return (to_string(a));
}

float compute (float a, float b, char op) {
    if (op == '+') {
        return (a + b);
    } else if (op == '*') {
        return (a * b);
    } else if (op == '-') {
        return (a - b);
    } else if (op == '/') {
        if (b != 0) { 
            return (a / b);
        } else {
            return 99999999;
        }
    }
    return 0;
}

vector<vector<int>> numPermutations(vector<int> num) {
    vector<vector<int>> permutations;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            if(i != j) {
                for(int k = 0; k <= 3; k++) {
                    if(j != k and k != i) {
                        for(int h = 0; h <= 3; h++) {
                            if(h != i and h != j and h != k) {
                                vector<int> temp;
                                temp.push_back(num[i]);
                                temp.push_back(num[j]);
                                temp.push_back(num[k]);
                                temp.push_back(num[h]);
                                permutations.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    return permutations;
}

vector<vector<char>> opPermutations(vector<char> op) {
    vector<vector<char>> permutations;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            for(int k = 0; k <= 3; k++) {       
                vector<char> temp;
                temp.push_back(op[i]);
                temp.push_back(op[j]);
                temp.push_back(op[k]);
                permutations.push_back(temp);  
            }
        }
    }
    return permutations;
}

void startSolver() {
    int inputCount = 0;
    int answerCount = 0;
    int goal = 24;
    bool valid;

    string userInput;
    vector<int> numInput;
    vector<char> op = {'+', '-', '*', '/'};
    vector<string> result;
    bool validInputChoice = false;
    int inputChoice;
    string validInput[13] = {"A", "J", "Q", "K", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    
    cout << "=========================o========================= \n";
    cout << "Selamat datang di 24-Game Solver! \n";
    cout << "Silakan input 4 kartu valid (nilainya saja), yaitu A, J, Q, K, dan 2 hingga 10! \n";
    cout << "Keterangan: \n" << "A bernilai 1 \n" << "J bernilai 11 \n" << "Q bernilai 12 \n" << "K bernilai 13 \n\n";

    // Choose Whether User Wants to Input Number Manually or Generate Random Numbers
    while (!validInputChoice) {
        cout << "Pilih cara pemilihan angka-angka! \n";
        cout << "1. Manual Input \n";
        cout << "2. Random \n";
        cout << "Ketik (1/2) : ";
        cin >> inputChoice;
        if (inputChoice == 1) {
            cout << "Masukkan 4 Kartu (pisahkan dengan spasi atau enter) : ";
            while (inputCount < 4) {
                valid = true;
                cin >> userInput;
                if (userInput == "A") {
                    numInput.push_back(1);
                } else if (userInput == "J") {
                    numInput.push_back(11);
                } else if (userInput == "Q") {
                    numInput.push_back(12);
                } else if (userInput == "K") {
                    numInput.push_back(13);
                } else if (userInput == "2") {
                    numInput.push_back(2);    
                } else if (userInput == "3") {
                    numInput.push_back(3);
                } else if (userInput == "4") {
                    numInput.push_back(4);
                } else if (userInput == "5") {
                    numInput.push_back(5);
                } else if (userInput == "6") {
                    numInput.push_back(6);
                } else if (userInput == "7") {
                    numInput.push_back(7);
                } else if (userInput == "8") {
                    numInput.push_back(8);
                } else if (userInput == "9") {
                    numInput.push_back(9);
                } else if (userInput == "10") {
                    numInput.push_back(10);
                } else {
                    valid = false;
                }
                
                if (valid) {
                    inputCount++;
                } else {
                    cout << "Input tidak valid, silakan input ulang kartu yang tidak valid! \n";
                    cout << "Kartu yang valid adalah A, J, Q, K, dan 2 hingga 10! \n";
                }
            }
            validInputChoice = true;
        } else if (inputChoice == 2) {
            cout << "Hasil generate kartu random : ";
            for(int i = 0; i <= 3; i++) {
                int randomIndex = rand() % 13;
                cout << validInput[randomIndex] << " ";
                if (validInput[randomIndex] == "A") {
                    numInput.push_back(1);
                } else if (validInput[randomIndex] == "J") {
                    numInput.push_back(11);
                } else if (validInput[randomIndex] == "Q") {
                    numInput.push_back(12);
                } else if (validInput[randomIndex] == "K") {
                    numInput.push_back(13);
                } else if (validInput[randomIndex] == "2") {
                    numInput.push_back(2);    
                } else if (validInput[randomIndex] == "3") {
                    numInput.push_back(3);
                } else if (validInput[randomIndex] == "4") {
                    numInput.push_back(4);
                } else if (validInput[randomIndex] == "5") {
                    numInput.push_back(5);
                } else if (validInput[randomIndex] == "6") {
                    numInput.push_back(6);
                } else if (validInput[randomIndex] == "7") {
                    numInput.push_back(7);
                } else if (validInput[randomIndex] == "8") {
                    numInput.push_back(8);
                } else if (validInput[randomIndex] == "9") {
                    numInput.push_back(9);
                } else if (validInput[randomIndex] == "10") {
                    numInput.push_back(10);
                }
            }
            cout << "\n";
            validInputChoice = true;
        } else {
            cout << "Input pilihan tidak valid, silakan ulangi! \n\n";
        }
    }

    vector<vector<int>> allNumPossibilities = numPermutations(numInput);
    vector<vector<char>> allOpPossibilities = opPermutations(op);
    clock_t start, end;

    // Algorithm to Find All Solutions
    start = clock();

    for(int i = 0; i <= 23; i++) {
        for(int j = 0; j <= 63; j++) {
            float possibility_1 = compute(allNumPossibilities[i][0], compute(allNumPossibilities[i][1], compute(allNumPossibilities[i][2], allNumPossibilities[i][3], allOpPossibilities[j][2]), allOpPossibilities[j][1]), allOpPossibilities[j][0]);
            float possibility_2 = compute(allNumPossibilities[i][0], compute(compute(allNumPossibilities[i][1], allNumPossibilities[i][2], allOpPossibilities[j][1]), allNumPossibilities[i][3], allOpPossibilities[j][2]), allOpPossibilities[j][0]);
            float possibility_3 = compute(compute(allNumPossibilities[i][0], compute(allNumPossibilities[i][1], allNumPossibilities[i][2], allOpPossibilities[j][1]), allOpPossibilities[j][0]), allNumPossibilities[i][3], allOpPossibilities[j][2]);
            float possibility_4 = compute(compute(allNumPossibilities[i][0], allNumPossibilities[i][1], allOpPossibilities[j][0]), compute(allNumPossibilities[i][2], allNumPossibilities[i][3], allOpPossibilities[j][2]), allOpPossibilities[j][1]);
            float possibility_5 = compute(compute(compute(allNumPossibilities[i][0], allNumPossibilities[i][1], allOpPossibilities[j][0]), allNumPossibilities[i][2], allOpPossibilities[j][1]), allNumPossibilities[i][3], allOpPossibilities[j][2]);

            // Check whether the result is the same as the goal, which is 24
            if (possibility_1 == 24) {
                string eq = intToStr(allNumPossibilities[i][0]) + allOpPossibilities[j][0] + "(" + intToStr(allNumPossibilities[i][1]) + allOpPossibilities[j][1] + "(" + intToStr(allNumPossibilities[i][2]) + allOpPossibilities[j][2] + intToStr(allNumPossibilities[i][3]) + "))";
                (result).push_back(eq);
                answerCount++;
                // cout << eq << "\n";
            }
            if (possibility_2 == 24) {
                string eq = intToStr(allNumPossibilities[i][0]) + allOpPossibilities[j][0] + "((" + intToStr(allNumPossibilities[i][1]) + allOpPossibilities[j][1] + intToStr(allNumPossibilities[i][2]) + ")" + allOpPossibilities[j][2] + intToStr(allNumPossibilities[i][3]) + ")";
                (result).push_back(eq);
                answerCount++;
                // cout << eq << "\n";
            }
            if (possibility_3 == 24) {
                string eq = "(" + intToStr(allNumPossibilities[i][0]) + allOpPossibilities[j][0] + "(" + intToStr(allNumPossibilities[i][1]) + allOpPossibilities[j][1] + intToStr(allNumPossibilities[i][2]) + "))" + allOpPossibilities[j][2] + intToStr(allNumPossibilities[i][3]);
                (result).push_back(eq);
                answerCount++;
                // cout << eq << "\n";
            }
            if (possibility_4 == 24) {
                string eq = "(" + intToStr(allNumPossibilities[i][0]) + allOpPossibilities[j][0] + intToStr(allNumPossibilities[i][1]) + ")" + allOpPossibilities[j][1] + "(" + intToStr(allNumPossibilities[i][2]) + allOpPossibilities[j][2] + intToStr(allNumPossibilities[i][3]) +")";
                (result).push_back(eq);
                answerCount++;
                // cout << eq << "\n";
            }
            if (possibility_5 == 24) {
                string eq = "((" + intToStr(allNumPossibilities[i][0]) + allOpPossibilities[j][0] + intToStr(allNumPossibilities[i][1]) + ")" + allOpPossibilities[j][1] + intToStr(allNumPossibilities[i][2]) + ")" + allOpPossibilities[j][2] + intToStr(allNumPossibilities[i][3]);
                (result).push_back(eq);
                answerCount++;
                // cout << eq << "\n";
            }
        }
    }

    // Number of Solutions
    if (answerCount == 0) {
        cout << "Tidak ada solusi yang ditemukan! \n";
    } else if (answerCount == 1) {
        cout << "Hanya ada 1 solusi yang ditemukan! \n";
    } else {
        cout << "Ada " << answerCount << " solusi yang ditemukan! \n";
    }
    
    end = clock();

    // Choice to Save the Solution(s) in a File
    char choice;
    bool validChoice;

    validChoice = false;
    while (!validChoice) {
        cout << "Apakah Anda ingin menyimpan solusi di dalam file? Ketik y untuk menyimpan atau n untuk tidak menyimpan: ";
        cin >> choice;
        if (choice == 'y') {
            string fileName;
            cout << "Masukkan nama file : ";
            cin >> fileName;
            ofstream outputFile;
            string path = "../test/" + fileName + ".txt";
            ofstream outFile(path);

            outputFile.open(path);
            if (answerCount == 0) {
                outputFile << "There is no solution! \n";
            } else if (answerCount == 1) {
                outputFile << "There is only " << answerCount << " solution found! \n";
                for(int i = 0; i < result.size(); i++) {
                    outputFile << result.at(i) << "\n";
                }
            } else {
                outputFile << "There are " << answerCount << " solutions found! \n";
                for(int i = 0; i < result.size(); i++) {
                    outputFile << result.at(i) << "\n";
                }
            }
            validChoice = true;

            outputFile.close();

            // Time Taken to Find All Solutions
            double takenTime = (double(end) - double(start)) / double(CLOCKS_PER_SEC);

            cout << "Waktu yang dibutuhkan untuk menemukan seluruh solusi: " << takenTime << " seconds \n";

            // Check If the User Want To Start Over
            char continueChoice;
            bool validContinueChoice;

            validContinueChoice = false;
            
            while (!validContinueChoice) {
                cout << "Apakah Anda ingin mengulang 24-Game Solver dari awal? \n";
                cout << "Ketik y untuk memulai ulang atau n untuk berhenti: ";
                cin >> continueChoice;
                if (continueChoice == 'y') {
                    validContinueChoice = true;
                    cout << "=========================o========================= \n";
                    cout << "\n";
                    startSolver();
                } else if (continueChoice == 'n') {
                    cout << "Terima kasih telah mencoba 24-Game Solver :) \n";
                    cout << "=========================o========================= \n";
                    cout << "\n";
                    validContinueChoice = true;
                } else {
                    cout << "Input tidak valid, silakan ulangi! \n";
                }
            }
        } else if (choice == 'n') {
            validChoice = true;

            // Time Taken to Find All Solutions
            double takenTime = (double(end) - double(start)) / double(CLOCKS_PER_SEC);

            cout << "Waktu yang dibutuhkan untuk menemukan seluruh solusi: " << takenTime << " seconds \n";
            char continueChoice;
            bool validContinueChoice;

            validContinueChoice = false;
            
            while (!validContinueChoice) {
                cout << "Apakah Anda ingin mengulang 24-Game Solver dari awal? \n";
                cout << "Ketik y untuk memulai ulang atau n untuk berhenti: ";
                cin >> continueChoice;
                if (continueChoice == 'y') {
                    validContinueChoice = true;
                    cout << "=========================o========================= \n";
                    cout << "\n";
                    startSolver();
                } else if (continueChoice == 'n') {
                    cout << "Terima kasih telah mencoba 24-Game Solver :) \n";
                    cout << "=========================o========================= \n";
                    cout << "\n";
                    validContinueChoice = true;
                } else {
                    cout << "Input tidak valid, silakan ulangi! \n";
                }
            }
        } else {
            cout << "Pilihan tidak valid, silakan ulangi! \n";
        }
    }  
}

int main() {
    startSolver();
}