#include <gtest/gtest.h>
#include "StringUtils.h"
#include <string>
#include <vector>

using namespace StringUtils;

TEST(StringUtilsTest, SliceTest) {
    EXPECT_EQ(Slice("Hello, World!", 0, 5), "Hello");
    EXPECT_EQ(Slice("Hello, World!", 7, 12), "World");
    EXPECT_EQ(Slice("Hello, World!", 7, 0), "");  // End is 0 which is handled as the length of the string.
    EXPECT_EQ(Slice("Hello", 1, 1), "");  // Start and end are the same.
    EXPECT_EQ(Slice("", 0, 1), "");  // Empty string.
}

TEST(StringUtilsTest, Capitalize) {
    EXPECT_EQ(Capitalize("hello"), "Hello");
    EXPECT_EQ(Capitalize("Hello"), "Hello");
    EXPECT_EQ(Capitalize(""), "");
    EXPECT_EQ(Capitalize("123abc"), "123abc");
}

TEST(StringUtilsTest, Upper) {
    EXPECT_EQ(Upper("hello"), "HELLO");
    EXPECT_EQ(Upper("Hello"), "HELLO");
    EXPECT_EQ(Upper(""), "");
    EXPECT_EQ(Upper("123abc"), "123ABC");
}

TEST(StringUtilsTest, Lower) {
    EXPECT_EQ(Lower("HELLO"), "hello");
    EXPECT_EQ(Lower("Hello"), "hello");
    EXPECT_EQ(Lower(""), "");
    EXPECT_EQ(Lower("123ABC"), "123abc");
}

TEST(StringUtilsTest, LStrip) {
    EXPECT_EQ(LStrip("   Hello"), "Hello");
    EXPECT_EQ(LStrip("Hello   "), "Hello   ");
    EXPECT_EQ(LStrip("   Hello   "), "Hello   ");
    EXPECT_EQ(LStrip(""), "");
    EXPECT_EQ(LStrip("Hello"), "Hello");
}

TEST(StringUtilsTest, RStrip) {
    EXPECT_EQ(RStrip("   Hello"), "   Hello");
    EXPECT_EQ(RStrip("Hello   "), "Hello");
    EXPECT_EQ(RStrip("   Hello   "), "   Hello");
    EXPECT_EQ(RStrip(""), "");
    EXPECT_EQ(RStrip("Hello"), "Hello");
}

TEST(StringUtilsTest, Strip) {
    EXPECT_EQ(Strip("   Hello   "), "Hello");
    EXPECT_EQ(Strip("Hello"), "Hello");
    EXPECT_EQ(Strip("   "), "");
    EXPECT_EQ(Strip(""), "");
}

TEST(StringUtilsTest, Center) {
    EXPECT_EQ(Center("Hello", 11, ' '), "   Hello   ");
    EXPECT_EQ(Center("Hello", 10, '*'), "**Hello***");
    EXPECT_EQ(Center("Hello", 3, '*'), "Hello");
    EXPECT_EQ(Center("", 3, '*'), "***");
}

TEST(StringUtilsTest, LJust) {
    EXPECT_EQ(LJust("Hello", 10, ' '), "Hello     ");
    EXPECT_EQ(LJust("Hello", 3, ' '), "Hello");
    EXPECT_EQ(LJust("", 3, '*'), "***");
}

TEST(StringUtilsTest, RJust) {
    EXPECT_EQ(RJust("Hello", 10, ' '), "     Hello");
    EXPECT_EQ(RJust("Hello", 3, ' '), "Hello");
    EXPECT_EQ(RJust("", 3, '*'), "***");
}

TEST(StringUtilsTest, Replace) {
    EXPECT_EQ(Replace("Hello World", "World", "There"), "Hello There");
    EXPECT_EQ(Replace("Hello Hello", "Hello", "Hi"), "Hi Hi");
    EXPECT_EQ(Replace("Hello", "Hello", ""), "");
}

TEST(StringUtilsTest, Split) {
    EXPECT_EQ(Split("Hello World", " "), (std::vector<std::string>{"Hello", "World"}));
    EXPECT_EQ(Split("One,Two,Three", ","), (std::vector<std::string>{"One", "Two", "Three"}));
    EXPECT_EQ(Split("Hello", " "), (std::vector<std::string>{"Hello"}));
}

TEST(StringUtilsTest, Join) {
    EXPECT_EQ(Join({"Hello", "World"}, " "), "Hello World");
    EXPECT_EQ(Join({"One", "Two", "Three"}, ","), "One,Two,Three");
    EXPECT_EQ(Join({"Hello"}, " "), "Hello");
    EXPECT_EQ(Join({}, " "), "");
}

TEST(StringUtilsTest, ExpandTabs) {
    EXPECT_EQ(ExpandTabs("Hello\tWorld", 4), "Hello    World");
    EXPECT_EQ(ExpandTabs("\tStart", 2), "  Start");
    EXPECT_EQ(ExpandTabs("No\tTabs", 0), "NoTabs");
    EXPECT_EQ(ExpandTabs("", 4), "");
}

TEST(StringUtilsTest, EditDistance) {
    EXPECT_EQ(EditDistance("kitten", "sitting", false), 3);
    EXPECT_EQ(EditDistance("Saturday", "Sunday", false), 3);
    EXPECT_EQ(EditDistance("flaw", "lawn", false), 2);
    EXPECT_EQ(EditDistance("", "", false), 0);
    EXPECT_EQ(EditDistance("same", "same", false), 0);
    // Case-insensitive edit distance
    EXPECT_EQ(EditDistance("kitten", "SITTING", true), 3);
}

