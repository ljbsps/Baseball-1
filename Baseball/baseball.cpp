#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string input) {
		assertIllegalArgument(input);
	}

private:
	void assertIllegalArgument(const std::string& input)
	{
		if (input.length() != 3) {
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
		return input[0] == input[1]
			|| input[0] == input[2]
			|| input[1] == input[2];
	}
};