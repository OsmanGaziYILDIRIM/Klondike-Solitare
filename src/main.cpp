#include <iostream>
#include "Klondike.cpp"

using namespace std;


int main(int argc, char **argv) {
    string deck = argv[1];
    string commands = argv[2];
    string outputFile = (argv[3]);
    Klondike *klondike = new Klondike;
    klondike->start(deck, commands, outputFile);
    return 0;
}
