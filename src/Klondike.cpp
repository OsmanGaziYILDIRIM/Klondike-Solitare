#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Klondike {
public:
    void start(string deckF, string commandsF,string output) {
        ifstream deckFile;
        deckFile.open(deckF);
        string deck[52];
        string row;
        int count5 = 0;
        while (getline(deckFile, row)) {
            deck[count5] = row;
            count5++;
        }
        deckFile.close();

        ifstream commandsFile;
        commandsFile.open(commandsF);
        string commands[200];
        string row2;
        int count21 = 0;
        while (getline(commandsFile, row2)) {
            commands[count21] = row2;
            count21++;
        }
        commandsFile.close();
        string stock[24];
        int count = 0;
        for (int i = 23; i > -1; i--) {
            stock[count] = deck[i];
            count++;
        }
        string pile[25][7];
        int count2 = 0;
        int k = 51;
        for (int j = 0; j < 7; j++) {
            for (int i = count2; i < 7; i++) {
                pile[j][i] = deck[k];
                k--;
                if (k < 24) {
                    break;
                }
            }
            count2++;
        }
        fstream outputFile;
        outputFile.open(output, ios::out);
        outputFile << "@@@ ___ ___ ___         ___ ___ ___ ___ " << "\n \n";

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (pile[i][j] == "") {
                    outputFile << "   ";
                }
                if (pile[i + 1][j] == "") {
                    outputFile << pile[i][j] << "   ";

                } else {
                    outputFile << "@@@   ";
                }
            }
            outputFile << endl;
        }
        outputFile << endl;
        string waste[12][3];
        string foundation[13][4];

        string move = "move";
        string to = "to";
        string f = "foundation";
        string w = "waste";
        string p = "pile";
        string o = "open";
        string h = "Hearth";
        string d = "Diamond";
        string c = "Club";
        string s = "Spades";

        for (int l = 0; l < 200; l++) {
            outputFile << commands[l] << "\n\n";
            outputFile << "****************************************\n" << endl;


            if (commands[l][0] == move[0]) {
                if (commands[l][5] == to[0]) {


                    if (commands[l][19] == w[0]) { // move to foundation waste
                        bool count = false;
                        for (int i = 0; i < 12; i++) {
                            if (count) {
                                break;
                            }
                            if (waste[i + 1][0] == "") {
                                if (waste[i][1] == "" || waste[i][1] == "___") {
                                    string card = waste[i][0];
                                    if (card[0] == h[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][0] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][0] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }

                                            } else if (foundation[j + 1][0] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][0][1];
                                                mervik1[1] = foundation[j][0][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][0] = card;
                                                    waste[i][0] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;


                                            }
                                        }
                                    } else if (card[0] == d[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][1] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][1] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][1] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][1][1];
                                                mervik1[1] = foundation[j][1][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][1] = card;
                                                    waste[i][0] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }
                                    } else if (card[0] == s[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][2] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][2] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][2] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][2][1];
                                                mervik1[1] = foundation[j][2][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][2] = card;
                                                    waste[i][0] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }

                                    } else if (card[0] == c[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][3] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][3] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][3] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][3][1];
                                                mervik1[1] = foundation[j][3][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][3] = card;
                                                    waste[i][0] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }
                                    }


                                }
                                if (waste[i][2] == "" || waste[i][2] == "___") {
                                    string card = waste[i][1];
                                    if (card[0] == h[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][0] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][0] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][0] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][0][1];
                                                mervik1[1] = foundation[j][0][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][0] = card;
                                                    waste[i][1] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;


                                            }
                                        }
                                    } else if (card[0] == d[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][1] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][1] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][1] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][1][1];
                                                mervik1[1] = foundation[j][1][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][1] = card;
                                                    waste[i][1] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }
                                    } else if (card[0] == s[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][2] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][2] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][2] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][2][1];
                                                mervik1[1] = foundation[j][2][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][2] = card;
                                                    waste[i][1] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }

                                    } else if (card[0] == c[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][3] == "") {
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == 1) {
                                                    foundation[0][3] = card;
                                                    waste[i][0] = "___";
                                                    count = true;
                                                    break;
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                            } else if (foundation[j + 1][3] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][3][1];
                                                mervik1[1] = foundation[j][3][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][3] = card;
                                                    waste[i][1] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }
                                    }

                                } else {
                                    string card = waste[i][2];
                                    if (card[0] == h[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][0] == "") {
                                                foundation[0][0] == card;
                                                waste[i][2] = "___";
                                                count = true;
                                                break;

                                            } else if (foundation[j + 1][0] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][0][1];
                                                mervik1[1] = foundation[j][0][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][0] = card;
                                                    waste[i][2] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;


                                            }
                                        }
                                    } else if (card[0] == d[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][1] == "") {
                                                foundation[0][1] = card;
                                                waste[i][2] = "___";
                                                count = true;
                                                break;

                                            } else if (foundation[j + 1][1] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][1][1];
                                                mervik1[1] = foundation[j][1][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][1] = card;
                                                    waste[i][2] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }
                                    } else if (card[0] == s[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][2] == "") {
                                                foundation[0][2] = card;
                                                waste[i][2] = "___";
                                                count = true;
                                                break;

                                            } else if (foundation[j + 1][2] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][2][1];
                                                mervik1[1] = foundation[j][2][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][2] = card;
                                                    waste[i][2] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }

                                    } else if (card[0] == c[0]) {
                                        for (int j = 0; j < 13; j++) {
                                            if (foundation[0][3] == "") {
                                                foundation[0][3] = card;
                                                waste[i][2] = "___";
                                                count = true;
                                                break;

                                            } else if (foundation[j + 1][3] == "") {
                                                string mervik1 = "mo";
                                                mervik1[0] = foundation[j][3][1];
                                                mervik1[1] = foundation[j][3][2];
                                                stringstream geek(mervik1);
                                                int number1 = 0;
                                                geek >> number1;
                                                string mervik2 = "mo";
                                                mervik2[0] = card[1];
                                                mervik2[1] = card[2];
                                                stringstream geek1(mervik2);
                                                int number2 = 0;
                                                geek1 >> number2;
                                                if (number2 == number1 + 1) {
                                                    foundation[j][3] = card;
                                                    waste[i][2] = "___";
                                                } else {
                                                    outputFile << "Invalid Move!\n";
                                                    outputFile << "\n****************************************\n"
                                                               << endl;
                                                }
                                                count = true;
                                                break;

                                            }
                                        }
                                    }
                                }
                            }
                        }
                        outputFile << "@@@ ";
                        for (int m = 0; m < 12; m++) {
                            if (waste[0][0] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (waste[m + 1][0] == "") {
                                outputFile << waste[m][0] << " ";
                                break;
                            }
                        }
                        for (int n = 0; n < 12; n++) {
                            if (waste[0][1] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (waste[n + 1][1] == "") {
                                outputFile << waste[n][1] << " ";
                                break;
                            }
                        }
                        for (int i1 = 0; i1 < 12; i1++) {
                            if (waste[0][2] == "") {
                                outputFile << "___         ";
                                break;
                            } else if (waste[i1 + 1][2] == "") {
                                outputFile << waste[i1][2] << "         ";
                                break;
                            }
                        }
                        for (int j1 = 0; j1 < 13; j1++) {
                            if (foundation[0][0] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[j1 + 1][0] == "") {
                                outputFile << foundation[j1][0] << " ";
                                break;
                            }
                        }
                        for (int k1 = 0; k1 < 13; k1++) {
                            if (foundation[0][1] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[k1 + 1][1] == "") {
                                outputFile << foundation[k1][1] << " ";
                                break;
                            }
                        }
                        for (int l1 = 0; l1 < 13; l1++) {
                            if (foundation[0][2] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[l1 + 1][2] == "") {
                                outputFile << foundation[l1][2] << " ";
                                break;
                            }
                        }
                        for (int m1 = 0; m1 < 13; m1++) {
                            if (foundation[0][3] == "") {
                                outputFile << "___\n\n";
                                break;
                            } else if (foundation[m1 + 1][3] == "") {
                                outputFile << foundation[m1][3] << "\n\n";
                                break;
                            }
                        }
                        for (int n1 = 0; n1 < 13; n1++) {
                            for (int j = 0; j < 7; j++) {
                                if (pile[n1][j] == "") {
                                    outputFile << "   ";
                                }
                                if (pile[n1 + 1][j] == "") {
                                    outputFile << pile[n1][j] << "   ";
                                } else {
                                    outputFile << "@@@   ";
                                }
                            }
                            outputFile << endl;
                        }

                    } else if (commands[l][19] == p[0]) { // move to foundation pile
                        string mervi = "s";
                        mervi[0] = commands[l][24];
                        stringstream geek(mervi);
                        int number = 0;
                        geek >> number;
                        for (int i = 0; i < 24; i++) {
                            bool count = false;
                            if (count) { break; }
                            bool changer = true;
                            if (pile[i + 1][number] == "") {
                                string card = pile[i][number];
                                if (card[0] == h[0]) {
                                    for (int j = 0; j < 13; j++) {
                                        if (foundation[0][0] == "") {
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == 1) {
                                                foundation[0][0] = card;
                                                count = true;
                                                break;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n"
                                                           << endl;
                                                changer = false;
                                            }
                                        } else if (foundation[j + 1][0] == "") {
                                            string mervik1 = "mo";
                                            mervik1[0] = foundation[j][0][1];
                                            mervik1[1] = foundation[j][0][2];
                                            stringstream geek(mervik1);
                                            int number1 = 0;
                                            geek >> number1;
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == number1 + 1) {
                                                foundation[j][0] = card;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n" << endl;
                                                changer = false;
                                            }
                                            count = true;
                                            break;


                                        }
                                    }
                                } else if (card[0] == d[0]) {
                                    for (int j = 0; j < 13; j++) {
                                        if (foundation[0][1] == "") {
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == 1) {
                                                foundation[0][1] = card;
                                                count = true;
                                                break;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n"
                                                           << endl;
                                                changer = false;
                                            }
                                        } else if (foundation[j + 1][1] == "") {
                                            string mervik1 = "mo";
                                            mervik1[0] = foundation[j][1][1];
                                            mervik1[1] = foundation[j][1][2];
                                            stringstream geek(mervik1);
                                            int number1 = 0;
                                            geek >> number1;
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == number1 + 1) {
                                                foundation[j][1] = card;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n" << endl;
                                                changer = false;
                                            }
                                            count = true;
                                            break;

                                        }
                                    }
                                } else if (card[0] == s[0]) {
                                    for (int j = 0; j < 13; j++) {
                                        if (foundation[0][2] == "") {
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == 1) {
                                                foundation[0][2] = card;
                                                count = true;
                                                break;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n"
                                                           << endl;
                                                changer = false;
                                            }
                                        } else if (foundation[j + 1][2] == "") {
                                            string mervik1 = "mo";
                                            mervik1[0] = foundation[j][2][1];
                                            mervik1[1] = foundation[j][2][2];
                                            stringstream geek(mervik1);
                                            int number1 = 0;
                                            geek >> number1;
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == number1 + 1) {
                                                foundation[j][2] = card;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n" << endl;
                                                changer = false;
                                            }
                                            count = true;
                                            break;

                                        }
                                    }

                                } else if (card[0] == c[0]) {
                                    for (int j = 0; j < 13; j++) {
                                        if (foundation[0][3] == "") {
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == 1) {
                                                foundation[0][3] = card;
                                                count = true;
                                                break;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n"
                                                           << endl;
                                                changer = false;
                                            }
                                        } else if (foundation[j + 1][3] == "") {
                                            string mervik1 = "mo";
                                            mervik1[0] = foundation[j][3][1];
                                            mervik1[1] = foundation[j][3][2];
                                            stringstream geek(mervik1);
                                            int number1 = 0;
                                            geek >> number1;
                                            string mervik2 = "mo";
                                            mervik2[0] = card[1];
                                            mervik2[1] = card[2];
                                            stringstream geek1(mervik2);
                                            int number2 = 0;
                                            geek1 >> number2;
                                            if (number2 == number1 + 1) {
                                                foundation[j][3] = card;
                                            } else {
                                                outputFile << "Invalid Move!\n";
                                                outputFile << "\n****************************************\n" << endl;
                                                changer = false;
                                            }
                                            count = true;
                                            break;

                                        }
                                    }
                                }
                                if (changer) { pile[i][number] = ""; }


                                outputFile << "@@@ ";
                                for (int m = 0; m < 12; m++) {
                                    if (waste[0][0] == "") {
                                        outputFile << "___ ";
                                        break;
                                    } else if (waste[m + 1][0] == "") {
                                        outputFile << waste[m][0] << " ";
                                        break;
                                    }
                                }
                                for (int n = 0; n < 12; n++) {
                                    if (waste[0][1] == "") {
                                        outputFile << "___ ";
                                        break;
                                    } else if (waste[n + 1][1] == "") {
                                        outputFile << waste[n][1] << " ";
                                        break;
                                    }
                                }
                                for (int i1 = 0; i1 < 12; i1++) {
                                    if (waste[0][2] == "") {
                                        outputFile << "___         ";
                                        break;
                                    } else if (waste[i1 + 1][2] == "") {
                                        outputFile << waste[i1][2] << "         ";
                                        break;
                                    }
                                }
                                for (int j1 = 0; j1 < 13; j1++) {
                                    if (foundation[0][0] == "") {
                                        outputFile << "___ ";
                                        break;
                                    } else if (foundation[j1 + 1][0] == "") {
                                        outputFile << foundation[j1][0] << " ";
                                        break;
                                    }
                                }
                                for (int k1 = 0; k1 < 13; k1++) {
                                    if (foundation[0][1] == "") {
                                        outputFile << "___ ";
                                        break;
                                    } else if (foundation[k1 + 1][1] == "") {
                                        outputFile << foundation[k1][1] << " ";
                                        break;
                                    }
                                }
                                for (int l1 = 0; l1 < 13; l1++) {
                                    if (foundation[0][2] == "") {
                                        outputFile << "___ ";
                                        break;
                                    } else if (foundation[l1 + 1][2] == "") {
                                        outputFile << foundation[l1][2] << " ";
                                        break;
                                    }
                                }
                                for (int m1 = 0; m1 < 13; m1++) {
                                    if (foundation[0][3] == "") {
                                        outputFile << "___\n\n";
                                        break;
                                    } else if (foundation[m1 + 1][3] == "") {
                                        outputFile << foundation[m1][3] << "\n\n";
                                        break;
                                    }
                                }
                                for (int n1 = 0; n1 < 13; n1++) {
                                    for (int j = 0; j < 7; j++) {
                                        if (pile[n1][j] == "") {
                                            outputFile << "   ";
                                        }
                                        if (pile[n1 + 1][j] == "") {
                                            if (i == n1 + 1 && number == j) {
                                                outputFile << "@@@   ";
                                            } else {
                                                outputFile << pile[n1][j] << "   ";
                                            }
                                        } else {
                                            outputFile << "@@@   ";
                                        }
                                    }
                                    outputFile << endl;
                                }
                                break;
                            }

                        }
                    }


                } else if (commands[l][5] == p[0]) { // move pile

                    string f = "f";
                    string s = "s";
                    string b = "b";
                    f[0] = commands[l][10];
                    b[0] = commands[l][12];
                    s[0] = commands[l][14];
                    stringstream geek(f);
                    stringstream geek1(b);
                    stringstream geek2(s);

                    int number1 = 0;
                    int number2 = 0;
                    int number3 = 0;
                    geek >> number1;
                    geek1 >> number2;
                    geek2 >> number3;
                    bool count = true;
                    for (int i = 0; i < 19; i++) {
                        if (pile[i + number2 + 1][number1] == "") {
                            for (int j = 0; j < number2 + 1; j++) {
                                for (int m = 0; m < 19; m++) {
                                    if (pile[m][number3] == "") {
                                        if (m > 0) {
                                            string mervi = "mo";
                                            mervi[0] = pile[m - 1][number3][1];
                                            mervi[1] = pile[m - 1][number3][2];
                                            int minik = 0;
                                            stringstream geek(mervi);
                                            geek >> minik;
                                            string mervik = "mc";
                                            mervik[0] = pile[i + j][number1][1];
                                            mervik[1] = pile[i + j][number1][2];
                                            stringstream geek1(mervik);
                                            int minik2 = 0;
                                            geek1 >> minik2;
                                            if (minik - 1 == minik2) {
                                                string h = "H";
                                                string d = "D";
                                                string s = "S";
                                                string c = "C";
                                                if (pile[m - 1][number3][0] == h[0]) {
                                                    if (pile[i + j][number1][0] == c[0] ||
                                                        pile[i + j][number1][0] == s[0]) {
                                                        pile[m][number3] = pile[i + j][number1];
                                                        pile[i + j][number1] = "";
                                                    }
                                                } else if (pile[m - 1][number3][0] == d[0]) {
                                                    if (pile[i + j][number1][0] == c[0] ||
                                                        pile[i + j][number1][0] == s[0]) {
                                                        pile[m][number3] = pile[i + j][number1];
                                                        pile[i + j][number1] = "";
                                                    }

                                                } else if (pile[m - 1][number3][0] == s[0]) {
                                                    if (pile[i + j][number1][0] == h[0] ||
                                                        pile[i + j][number1][0] == d[0]) {
                                                        pile[m][number3] = pile[i + j][number1];
                                                        pile[i + j][number1] = "";
                                                    }

                                                } else if (pile[m - 1][number3][0] == c[0]) {
                                                    if (pile[i + j][number1][0] == h[0] ||
                                                        pile[i + j][number1][0] == d[0]) {
                                                        pile[m][number3] = pile[i + j][number1];
                                                        pile[i + j][number1] = "";
                                                    }

                                                }
                                            }
                                        } else {
                                            pile[m][number3] = pile[i + j][number1];
                                            pile[i + j][number1] = "";
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (count) {
                        outputFile << "@@@ ";
                        for (int m = 0; m < 12; m++) {
                            if (waste[0][0] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (waste[m + 1][0] == "") {
                                outputFile << waste[m][0] << " ";
                                break;
                            }
                        }
                        for (int n = 0; n < 12; n++) {
                            if (waste[0][1] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (waste[n + 1][1] == "") {
                                outputFile << waste[n][1] << " ";
                                break;
                            }
                        }
                        for (int i1 = 0; i1 < 12; i1++) {
                            if (waste[0][2] == "") {
                                outputFile << "___         ";
                                break;
                            } else if (waste[i1 + 1][2] == "") {
                                outputFile << waste[i1][2] << "         ";
                                break;
                            }
                        }
                        for (int j1 = 0; j1 < 13; j1++) {
                            if (foundation[0][0] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[j1 + 1][0] == "") {
                                outputFile << foundation[j1][0] << " ";
                                break;
                            }
                        }
                        for (int k1 = 0; k1 < 13; k1++) {
                            if (foundation[0][1] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[k1 + 1][1] == "") {
                                outputFile << foundation[k1][1] << " ";
                                break;
                            }
                        }
                        for (int l1 = 0; l1 < 13; l1++) {
                            if (foundation[0][2] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[l1 + 1][2] == "") {
                                outputFile << foundation[l1][2] << " ";
                                break;
                            }
                        }
                        for (int m1 = 0; m1 < 13; m1++) {
                            if (foundation[0][3] == "") {
                                outputFile << "___\n\n";
                                break;
                            } else if (foundation[m1 + 1][3] == "") {
                                outputFile << foundation[m1][3] << "\n\n";
                                break;
                            }
                        }
                        for (int n1 = 0; n1 < 13; n1++) {
                            for (int j = 0; j < 7; j++) {
                                if (pile[n1][j] == "") {
                                    outputFile << "   ";
                                }
                                if (pile[n1 + 1][j] == "") {
                                    outputFile << pile[n1][j] << "   ";
                                } else {
                                    outputFile << "@@@   ";
                                }
                            }
                            outputFile << endl;

                        }
                    }

                } else if (commands[l][5] = w[0]) {    //move waste

                    bool count = true;
                    string mervi = "m";
                    mervi[0] = commands[l][11];
                    int mervik = 0;
                    stringstream geek(mervi);
                    geek >> mervik;
                    for (int i = 0; i < 12; i++) {
                        if (waste[i + 1][0] == "") {
                            if (waste[i][1] == "" || waste[i][1] == "___") {
                                for (int j = 0; j < 19; j++) {
                                    if (pile[j][mervik] == "") {
                                        pile[j][mervik] = waste[i][0];
                                        waste[i][0] = "___";
                                        break;
                                    }
                                    if (pile[j + 1][mervik] == "") {
                                        string mervi = "mo";
                                        mervi[0] = pile[j][mervik][1];
                                        mervi[1] = pile[j][mervik][2];
                                        int minik = 0;
                                        stringstream geek(mervi);
                                        geek >> minik;
                                        string mervikim = "mc";
                                        mervikim[0] = waste[i][0][1];
                                        mervikim[1] = waste[i][0][2];
                                        stringstream geek1(mervikim);
                                        int minik2 = 0;
                                        geek1 >> minik2;
                                        if (minik - 1 == minik2) {
                                            string h = "H";
                                            string d = "D";
                                            string s = "S";
                                            string c = "C";
                                            if (pile[j][mervik][0] == h[0]) {
                                                if (waste[i][0][0] == c[0] ||
                                                    waste[i][0][0] == s[0]) {
                                                    pile[j + 1][mervik] = waste[i][0];
                                                    waste[i][0] = "___";
                                                    break;
                                                }
                                            } else if (pile[j][mervik][0] == d[0]) {
                                                if (waste[i][0][0] == c[0] ||
                                                    waste[i][0][0] == s[0]) {
                                                    pile[j + 1][mervik] = waste[i][0];
                                                    waste[i][0] = "___";
                                                    break;
                                                }

                                            } else if (pile[j][mervik][0] == s[0]) {
                                                if (waste[i][0][0] == h[0] ||
                                                    waste[i][0][0] == d[0]) {
                                                    pile[j + 1][mervik] = waste[i][0];
                                                    waste[i][0] = "___";
                                                    break;
                                                }

                                            } else if (pile[j][mervik][0] == c[0]) {
                                                if (waste[i][0][0] == h[0] ||
                                                    waste[i][0][0] == d[0]) {
                                                    pile[j + 1][mervik] = waste[i][0];
                                                    waste[i][0] = "___";
                                                    break;
                                                }

                                            }
                                        } else {
                                            outputFile << "Invalid Move!\n";
                                            outputFile << "\n****************************************\n" << endl;
                                            count = false;
                                        }
                                    }
                                }
                                break;
                            }
                            if (waste[i][2] == "" || waste[i][2] == "___") {
                                for (int j = 0; j < 19; j++) {
                                    if (pile[j][mervik] == "") {
                                        pile[j][mervik] = waste[i][1];
                                        waste[i][1] = "___";
                                        break;
                                    }
                                    if (pile[j + 1][mervik] == "") {
                                        string mervi = "mo";
                                        mervi[0] = pile[j][mervik][1];
                                        mervi[1] = pile[j][mervik][2];
                                        int minik = 0;
                                        stringstream geek(mervi);
                                        geek >> minik;
                                        string mervikim = "mc";
                                        mervikim[0] = waste[i][1][1];
                                        mervikim[1] = waste[i][1][2];
                                        stringstream geek1(mervikim);
                                        int minik2 = 0;
                                        geek1 >> minik2;
                                        if (minik - 1 == minik2) {
                                            string h = "H";
                                            string d = "D";
                                            string s = "S";
                                            string c = "C";
                                            if (pile[j][mervik][0] == h[0]) {
                                                if (waste[i][1][0] == c[0] ||
                                                    waste[i][1][0] == s[0]) {
                                                    pile[j + 1][mervik] = waste[i][1];
                                                    waste[i][1] = "___";
                                                    break;
                                                }
                                            } else if (pile[j][mervik][0] == d[0]) {
                                                if (waste[i][1][0] == c[0] ||
                                                    waste[i][1][0] == s[0]) {
                                                    pile[j + 1][mervik] = waste[i][1];
                                                    waste[i][1] = "___";
                                                    break;
                                                }

                                            } else if (pile[j][mervik][0] == s[0]) {
                                                if (waste[i][1][0] == h[0] ||
                                                    waste[i][1][0] == d[0]) {
                                                    pile[j + 1][mervik] = waste[i][1];
                                                    waste[i][1] = "___";
                                                    break;
                                                }

                                            } else if (pile[j][mervik][0] == c[0]) {
                                                if (waste[i][1][0] == h[0] ||
                                                    waste[i][1][0] == d[0]) {
                                                    pile[j + 1][mervik] = waste[i][1];
                                                    waste[i][1] = "___";
                                                    break;
                                                }

                                            }
                                        } else {
                                            outputFile << "Invalid Move!\n";
                                            outputFile << "\n****************************************\n" << endl;
                                            count = false;
                                        }
                                    }
                                }
                                break;
                            }
                            if (waste[i][2] != "" && waste[i][2] != "___") {
                                for (int j = 0; j < 19; j++) {
                                    if (pile[j][mervik] == "") {
                                        pile[j][mervik] = waste[i][2];
                                        waste[i][2] = "___";
                                        break;
                                    }
                                    if (pile[j + 1][mervik] == "") {
                                        string mervi = "mo";
                                        mervi[0] = pile[j][mervik][1];
                                        mervi[1] = pile[j][mervik][2];
                                        int minik = 0;
                                        stringstream geek(mervi);
                                        geek >> minik;
                                        string mervikim = "mc";
                                        mervikim[0] = waste[i][2][1];
                                        mervikim[1] = waste[i][2][2];
                                        stringstream geek1(mervikim);
                                        int minik2 = 0;
                                        geek1 >> minik2;
                                        if (minik - 1 == minik2) {
                                            string h = "H";
                                            string d = "D";
                                            string s = "S";
                                            string c = "C";
                                            if (pile[j][mervik][0] == h[0]) {
                                                if (waste[i][2][0] == c[0] ||
                                                    waste[i][2][0] == s[0]) {
                                                    pile[j + 1][mervik] = waste[i][2];
                                                    waste[i][2] = "___";
                                                    break;
                                                }
                                            } else if (pile[j][mervik][0] == d[0]) {
                                                if (waste[i][2][0] == c[0] ||
                                                    waste[i][2][0] == s[0]) {
                                                    pile[j + 1][mervik] = waste[i][2];
                                                    waste[i][2] = "___";
                                                    break;
                                                }

                                            } else if (pile[j][mervik][0] == s[0]) {
                                                if (waste[i][2][0] == h[0] ||
                                                    waste[i][2][0] == d[0]) {
                                                    pile[j + 1][mervik] = waste[i][2];
                                                    waste[i][2] = "___";
                                                    break;
                                                }

                                            } else if (pile[j][mervik][0] == c[0]) {
                                                if (waste[i][2][0] == h[0] ||
                                                    waste[i][2][0] == d[0]) {
                                                    pile[j + 1][mervik] = waste[i][2];
                                                    waste[i][2] = "___";
                                                    break;
                                                }

                                            }
                                        } else {
                                            outputFile << "Invalid Move!\n";
                                            outputFile << "\n****************************************\n" << endl;
                                            count = false;
                                        }
                                    }
                                }
                                break;
                            }

                        }
                    }
                    if (count) {
                        outputFile << "@@@ ";
                        for (int m = 0; m < 12; m++) {
                            if (waste[0][0] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (waste[m + 1][0] == "") {
                                outputFile << waste[m][0] << " ";
                                break;
                            }
                        }
                        for (int n = 0; n < 12; n++) {
                            if (waste[0][1] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (waste[n + 1][1] == "") {
                                outputFile << waste[n][1] << " ";
                                break;
                            }
                        }
                        for (int i1 = 0; i1 < 12; i1++) {
                            if (waste[0][2] == "") {
                                outputFile << "___         ";
                                break;
                            } else if (waste[i1 + 1][2] == "") {
                                outputFile << waste[i1][2] << "         ";
                                break;
                            }
                        }
                        for (int j1 = 0; j1 < 13; j1++) {
                            if (foundation[0][0] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[j1 + 1][0] == "") {
                                outputFile << foundation[j1][0] << " ";
                                break;
                            }
                        }
                        for (int k1 = 0; k1 < 13; k1++) {
                            if (foundation[0][1] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[k1 + 1][1] == "") {
                                outputFile << foundation[k1][1] << " ";
                                break;
                            }
                        }
                        for (int l1 = 0; l1 < 13; l1++) {
                            if (foundation[0][2] == "") {
                                outputFile << "___ ";
                                break;
                            } else if (foundation[l1 + 1][2] == "") {
                                outputFile << foundation[l1][2] << " ";
                                break;
                            }
                        }
                        for (int m1 = 0; m1 < 13; m1++) {
                            if (foundation[0][3] == "") {
                                outputFile << "___\n\n";
                                break;
                            } else if (foundation[m1 + 1][3] == "") {
                                outputFile << foundation[m1][3] << "\n\n";
                                break;
                            }
                        }
                        for (int n1 = 0; n1 < 13; n1++) {
                            for (int j = 0; j < 7; j++) {
                                if (pile[n1][j] == "") {
                                    outputFile << "   ";
                                }
                                if (pile[n1 + 1][j] == "") {
                                    outputFile << pile[n1][j] << "   ";
                                } else {
                                    outputFile << "@@@   ";
                                }
                            }
                            outputFile << endl;
                        }


                    }
                }
            } else if (commands[l][0] == o[0]) {


                if (commands[l][5] == f[0]) { // open from stock
                    bool count = true;
                    int mervem = 0;
                    if (stock[23] == "") {
                        count = false;
                        mervem = 1;
                    }
                    if (count) {
                        for (int i = 0; i < 24; i++) {
                            if (stock[i] != "") {
                                for (int j = 0; j < 3; j++) {
                                    for (int m = 0; m < 12; m++) {
                                        if (waste[m][0] == "") {
                                            if (j == 0) {
                                                waste[m][j] = stock[i + j];
                                                stock[i + j] = "";
                                                break;
                                            } else if (stock[23] != "") {
                                                waste[m - 1][j] = stock[i + j];
                                                stock[i + j] = "";
                                                break;
                                            }

                                        }
                                    }
                                }
                                if (stock[23] == "") {
                                    count = false;
                                }
                                break;
                            }
                        }
                    }
                    if (mervem == 1) {
                        for (int i = 23; i > -1; i--) {
                            for (int j = 11; j > -1; j--) {
                                for (int m = 2; m > -1; m--) {
                                    if (waste[j][0] != "" && waste[j][0] != "___") {
                                        if (waste[j][2] != "___" && waste[j][2] != "") {
                                            stock[i--] = waste[j][2];
                                            waste[j][2] = "";
                                        } else if (waste[j][1] != "___" && waste[j][1] != "") {
                                            stock[i--] = waste[j][1];
                                            waste[j][1] = "";
                                        } else if (waste[j][0] != "" && waste[j][0] != "___") {
                                            stock[i--] = waste[j][0];
                                            waste[j][0] = "";
                                        }
                                    } else if (waste[j][0] == "___") {
                                        waste[j][0] = "";
                                        waste[j][1] = "";
                                        waste[j][2] = "";
                                    }
                                }
                            }
                        }
                        for (int n = 0; n < 12; n++) {
                            for (int i = 0; i < 3; i++) {
                                waste[n][i] = "";
                            }
                        }
                        count = true;
                    }
                    if (count) { outputFile << "@@@ "; }
                    else {
                        outputFile << "___ ";
                    }

                    for (int m = 0; m < 12; m++) {
                        if (waste[0][0] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (waste[m + 1][0] == "") {
                            outputFile << waste[m][0] << " ";
                            break;
                        }
                    }
                    for (int n = 0; n < 12; n++) {
                        if (waste[0][1] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (waste[n + 1][1] == "") {
                            outputFile << waste[n][1] << " ";
                            break;
                        }
                    }
                    for (int i1 = 0; i1 < 12; i1++) {
                        if (waste[0][2] == "") {
                            outputFile << "___         ";
                            break;
                        } else if (waste[i1 + 1][2] == "") {
                            outputFile << waste[i1][2] << "         ";
                            break;
                        }
                    }
                    for (int j1 = 0; j1 < 13; j1++) {
                        if (foundation[0][0] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (foundation[j1 + 1][0] == "") {
                            outputFile << foundation[j1][0] << " ";
                            break;
                        }
                    }
                    for (int k1 = 0; k1 < 13; k1++) {
                        if (foundation[0][1] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (foundation[k1 + 1][1] == "") {
                            outputFile << foundation[k1][1] << " ";
                            break;
                        }
                    }
                    for (int l1 = 0; l1 < 13; l1++) {
                        if (foundation[0][2] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (foundation[l1 + 1][2] == "") {
                            outputFile << foundation[l1][2] << " ";
                            break;
                        }
                    }
                    for (int m1 = 0; m1 < 13; m1++) {
                        if (foundation[0][3] == "") {
                            outputFile << "___\n\n";
                            break;
                        } else if (foundation[m1 + 1][3] == "") {
                            outputFile << foundation[m1][3] << "\n\n";
                            break;
                        }
                    }
                    for (int n1 = 0; n1 < 13; n1++) {
                        for (int j = 0; j < 7; j++) {
                            if (pile[n1][j] == "") {
                                outputFile << "   ";
                            }
                            if (pile[n1 + 1][j] == "") {
                                outputFile << pile[n1][j] << "   ";
                            } else {
                                outputFile << "@@@   ";
                            }
                        }
                        outputFile << endl;
                    }


                } else { // open
                    outputFile << "@@@ ";
                    for (int m = 0; m < 12; m++) {
                        if (waste[0][0] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (waste[m + 1][0] == "") {
                            outputFile << waste[m][0] << " ";
                            break;
                        }
                    }
                    for (int n = 0; n < 12; n++) {
                        if (waste[0][1] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (waste[n + 1][1] == "") {
                            outputFile << waste[n][1] << " ";
                            break;
                        }
                    }
                    for (int i1 = 0; i1 < 12; i1++) {
                        if (waste[0][2] == "") {
                            outputFile << "___         ";
                            break;
                        } else if (waste[i1 + 1][2] == "") {
                            outputFile << waste[i1][2] << "         ";
                            break;
                        }
                    }
                    for (int j1 = 0; j1 < 13; j1++) {
                        if (foundation[0][0] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (foundation[j1 + 1][0] == "") {
                            outputFile << foundation[j1][0] << " ";
                            break;
                        }
                    }
                    for (int k1 = 0; k1 < 13; k1++) {
                        if (foundation[0][1] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (foundation[k1 + 1][1] == "") {
                            outputFile << foundation[k1][1] << " ";
                            break;
                        }
                    }
                    for (int l1 = 0; l1 < 13; l1++) {
                        if (foundation[0][2] == "") {
                            outputFile << "___ ";
                            break;
                        } else if (foundation[l1 + 1][2] == "") {
                            outputFile << foundation[l1][2] << " ";
                            break;
                        }
                    }
                    for (int m1 = 0; m1 < 13; m1++) {
                        if (foundation[0][3] == "") {
                            outputFile << "___\n\n";
                            break;
                        } else if (foundation[m1 + 1][3] == "") {
                            outputFile << foundation[m1][3] << "\n\n";
                            break;
                        }
                    }
                    for (int n1 = 0; n1 < 13; n1++) {
                        for (int j = 0; j < 7; j++) {
                            if (pile[n1][j] == "") {
                                outputFile << "   ";
                            }
                            if (pile[n1 + 1][j] == "") {
                                outputFile << pile[n1][j] << "   ";
                            } else {
                                outputFile << "@@@   ";
                            }
                        }
                        outputFile << endl;
                    }
                }
            } else {
                if (foundation[0][0] == "H13" && foundation[0][1] == "D13" && foundation[0][2] == "S13"
                    && foundation[0][03] == "C13") {
                    outputFile<<"\nYou Win!\n\nGame Over!"<<endl;
                    outputFile.close();
                    break;
                } else{
                    outputFile<<"\nGame Over!"<<endl;
                    outputFile.close();
                    break;
                }
            }
        }
    }

};