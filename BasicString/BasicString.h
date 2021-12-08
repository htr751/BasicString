#pragma once

#include <cstdio>
#include <iostream>
#include <vector>

using std::ostream;
using std::vector;

class BasicString {
public:
	BasicString(const char* str);
	BasicString(const BasicString& other);
	BasicString(BasicString&& other);

	const BasicString& operator=(const BasicString& other);
	const BasicString& operator=(BasicString&& other);

	friend ostream& operator<<(ostream& stream, const BasicString& other);

	/**
	 * Insert a char count times in the specified index.
	 * Returns a reference to this.
	 */
	const BasicString& insert(size_t index, size_t count, char charToInsert);

	/**
	 * Insert a string in the specified index.
	 * Returns a reference to this.
	 */
	const BasicString& insert(size_t index, const BasicString& strToInsert);

	/**
	 * Erase count characters in the string from index.
	 * Return reference to this.
	 */
	const BasicString& erase(size_t index, size_t count);

	~BasicString() = default;

private:
	vector<char> m_string;
};

