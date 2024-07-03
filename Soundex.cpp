#include "Soundex.h"
#include <cctype>
#include <unordered_map>
#include <unordered_set>

// Helper function to get the Soundex code for a character
char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    
    c = toupper(c);
    auto it = soundexMap.find(c);
    return it != soundexMap.end() ? it->second : '0'; // For A, E, I, O, U, H, W, Y
}

// Helper function to check if a character is a vowel
bool isVowel(char c) {
    static const std::unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
    return vowels.find(toupper(c)) != vowels.end();
}

// Helper function to process each character in the name
void processCharacter(char currentChar, char &prevCode, std::string &soundex) {
    char code = getSoundexCode(currentChar);
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}

// Main function to generate the Soundex code for a given name
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0])); // Retain the first letter (capitalized)
    char prevCode = getSoundexCode(name[0]); // Get the Soundex code for the first letter

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        processCharacter(name[i], prevCode, soundex);
    }

    // Pad with zeros if needed
    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex; // Return the final Soundex code
}
