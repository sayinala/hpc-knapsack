#ifndef UTIL_STRINGUTILS_H_
#define UTIL_STRINGUTILS_H_

#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>
#include <sstream>

class StringUtils {
public:
	static inline std::string& ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static inline std::string& rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static inline std::string& trim(std::string &s) {
		return ltrim(rtrim(s));
	}


	static std::vector<std::string> split(std::string str, char delimiter);

};

#endif /* UTIL_STRINGUTILS_H_ */