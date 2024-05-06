/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/


TEST(GuesserTest, matchClean)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.match("Password"), true);
}
TEST(GuesserTest, matchEmpty)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.match(""), false);
}
TEST(GuesserTest, matchClose)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.match("password"), false);
}
TEST(GuesserTest, matchFar)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.match("fifteen"), false);
}
TEST(GuesserTest, matchClean_AfterClose)
{
	Guesser guess("Password");
	guess.match("password");
    ASSERT_EQ(guess.match("Password"), true);
}
TEST(GuesserTest, matchClean_AfterLockout)
{
	Guesser guess("Password");
	guess.match("fifteen");
    ASSERT_EQ(guess.match("Password"), false);
}
TEST(GuesserTest, matchClean_AfterLimit)
{
	Guesser guess("Password");
	guess.match("password");
	guess.match("password");
	guess.match("password");
    ASSERT_EQ(guess.match("Password"), false);
}
TEST(GuesserTest, matchLongGuess)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.match("PasswordPassword"), false);
}
TEST(GuesserTest, matchShortGuess)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.match("Pass"), false);
}
TEST(GuesserTest, remainingClean)
{
	Guesser guess("Password");
    ASSERT_EQ(guess.remaining(), 3);
}

TEST(GuesserTest, remaining2)
{
	Guesser guess("Password");
	guess.match("password");
    ASSERT_EQ(guess.remaining(), 2);
}
TEST(GuesserTest, remaining3)
{
	Guesser guess("Password");
	guess.match("password");
	guess.match("password");
    ASSERT_EQ(guess.remaining(), 1);
}
TEST(GuesserTest, remaining4)
{
	Guesser guess("Password");
	guess.match("password");
	guess.match("password");
	guess.match("password");
    ASSERT_EQ(guess.remaining(), 0);
}
TEST(GuesserTest, remainingReset)
{
	Guesser guess("Password");
	guess.match("password");
	guess.match("password");
	guess.match("Password");
    ASSERT_EQ(guess.remaining(), 3);
}
TEST(GuesserTest, constructorEmpty)
{
	Guesser guess("");
    ASSERT_EQ(guess.match(""), true);
}
TEST(GuesserTest, constructorOversize)
{
	Guesser guess("aaabbbcccdddeeefffggghhhiiijjjkkklll");
    ASSERT_EQ(guess.match("aaabbbcccdddeeefffggghhhiiijjjkk"), true);
}