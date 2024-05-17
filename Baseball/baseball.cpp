#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
public:
	string guess(const string input) {
		if (input.length() != 3) {
			throw length_error("string length should be 3");
		}
		for (char ch : input) {
			if (ch < '0' || ch >'9') {
				throw invalid_argument("input should consist of number");
			}
		}
	}
};