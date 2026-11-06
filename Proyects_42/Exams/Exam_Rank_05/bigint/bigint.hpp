#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>

class bigint {
	private:
		std::string str;

	public:
		bigint(unsigned long long n = 0) { std::stringstream ss; ss << n; str = ss.str(); }
		bigint(const std::string& s) : str(s.empty() ? "0" : s) {}

		std::string getStr() const { return str; }

		bigint operator+(const bigint& b) const {
			std::string r;
			int i = str.size() - 1, j = b.str.size() - 1, carry = 0;
			while (i >= 0 || j >= 0 || carry) {
				int sum = carry + (i >= 0 ? str[i--] - '0' : 0) + (j >= 0 ? b.str[j--] - '0' : 0);
				r.push_back((sum % 10) + '0');
				carry = sum / 10;
			}
			std::reverse(r.begin(), r.end());
			return bigint(r);
		}

		bigint& operator+=(const bigint& b) { return *this = *this + b; }
		bigint& operator++()                { return *this += 1; }
		bigint  operator++(int)             { bigint t = *this; ++(*this); return t; }

		bigint operator<<(size_t n) const { return (str == "0") ? *this : bigint(str + std::string(n, '0')); }
		bigint operator>>(size_t n) const { return (n >= str.size()) ? bigint(0) : bigint(str.substr(0, str.size() - n)); }

		bigint operator<<(const bigint& b) const { return *this << std::atoi(b.str.c_str()); }
		bigint operator>>(const bigint& b) const { return *this >> std::atoi(b.str.c_str()); }

		bigint& operator<<=(size_t n)        { return *this = *this << n; }
		bigint& operator>>=(size_t n)        { return *this = *this >> n; }
		bigint& operator<<=(const bigint& b) { return *this = *this << b; }
		bigint& operator>>=(const bigint& b) { return *this = *this >> b; }

		bool operator==(const bigint& b) const { return str == b.str; }
		bool operator!=(const bigint& b) const { return !(*this == b); }
		bool operator<(const bigint& b)  const { return str.size() != b.str.size() ? str.size() < b.str.size() : str < b.str; }
		bool operator>(const bigint& b)  const { return b < *this; }
		bool operator<=(const bigint& b) const { return !(*this > b); }
		bool operator>=(const bigint& b) const { return !(*this < b); }
};

inline std::ostream& operator<<(std::ostream& os, const bigint& b) { return os << b.getStr(); }
