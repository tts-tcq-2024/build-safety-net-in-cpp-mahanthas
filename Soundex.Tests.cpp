#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesSimpleNames) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(SoundexTest, IgnoresNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("O'Hara"), "O600");
    EXPECT_EQ(generateSoundex("Smith!"), "S530");
}

TEST(SoundexTest, HandlesDoubleLetters) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

TEST(SoundexTest, HandlesNamesWithVowelsAndSilentLetters) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

TEST(SoundexTest, HandlesNamesWithHAndWSeparators) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

TEST(SoundexTest, HandlesNamesWithRepeatedSoundexValues) {
    EXPECT_EQ(generateSoundex("Gutierrez"), "G362");
    EXPECT_EQ(generateSoundex("Jackson"), "J250");
}

TEST(SoundexTest, HandlesShortNames) {
    EXPECT_EQ(generateSoundex("Li"), "L000");
    EXPECT_EQ(generateSoundex("Lee"), "L000");
}

TEST(SoundexTest, PadsWithZerosWhenNeeded) {
    EXPECT_EQ(generateSoundex("E"), "E000");
    EXPECT_EQ(generateSoundex("Ei"), "E000");
    EXPECT_EQ(generateSoundex("Eio"), "E000");
}
