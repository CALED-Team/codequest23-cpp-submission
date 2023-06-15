#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

class Game {
public:
    void readAndParseJSON() {
        // Read input from stdin
        string input;
        getline(cin, input);
        
        // Parse input as JSON
        try {
            json parsedInput = json::parse(input);

            cout << parsedInput.value("a", "oops") << endl;
            
        } catch (json::parse_error& e) {
            cerr << "Error parsing JSON: " << e.what() << endl;
        }
    }
};

#endif  // GAME_H
