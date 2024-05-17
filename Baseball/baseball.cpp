#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;

	static GuessResult correct(int strikes) {
		return { true, strikes, 0 };
	}
};

class Baseball {
public:
	Baseball(const string question) : question(question) {}

	GuessResult guess(const string guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return GuessResult::correct(LENGTH_QUESTION);
		}

		return getHint(guessNumber);
	}

private:
	const int LENGTH_QUESTION = 3;
	string question;

	void assertIllegalArgument(const std::string& input)
	{
		if (input.length() != LENGTH_QUESTION) {
			throw length_error("String length should be 3");
		}
		for (char ch : input) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("String should consist of number");
		}
		if (isDuplicatedNumber(input)) {
			throw invalid_argument("String should not have same number");
		}
	}

	bool isDuplicatedNumber(const string& input)
	{
		for (char ch : input) {
			if (input.find_first_of(ch) != input.find_last_of(ch)) {
				return true;
			}
		}
		return false;
	}

	GuessResult getHint(const string& guessNumber) {
		GuessResult guessResult = { 0, };
		int pos;

		for (int idx = 0; idx < LENGTH_QUESTION; idx++) {
			if ((pos = question.find(guessNumber[idx])) == -1) continue;

			if (pos == idx) guessResult.strikes++;
			else guessResult.balls++;
		}

		return guessResult;
	}
};