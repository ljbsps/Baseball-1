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
	}
};