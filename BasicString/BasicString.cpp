#include "BasicString.h"

#include <cstdio>
#include <cstdlib>

#include <utility>
#include <algorithm>
#include <iterator>
#include <stdexcept>

using std::move;
using std::ostream_iterator;
using std::ostream;
using std::out_of_range;

BasicString::BasicString(const char* str) : m_string(strlen(str)) {
	memcpy_s(m_string.data(), m_string.size(), str, m_string.size());
}

BasicString::BasicString(const BasicString& other) : m_string(other.m_string) {}

BasicString::BasicString(BasicString&& other) : m_string(move(other.m_string)) {}

const BasicString& BasicString::operator=(const BasicString& other) {
	this->m_string = other.m_string;
	return *this;
}

const BasicString& BasicString::operator=(BasicString&& other) {
	this->m_string = move(other.m_string);
	return *this;
}

ostream& operator<<(ostream& stream, const BasicString& other) {
	std::copy(other.m_string.begin(), other.m_string.end(), ostream_iterator<char>(stream));
	return stream;
}

const BasicString& BasicString::insert(size_t index, size_t count, char charToInsert) {
	this->m_string.insert(this->m_string.begin() + index, count, charToInsert);
	return *this;
}

const BasicString& BasicString::insert(size_t index, const BasicString& strToInsert) {
	this->m_string.insert(this->m_string.begin() + index, strToInsert.m_string.begin(), strToInsert.m_string.end());
	return *this;
}

const BasicString& BasicString::erase(size_t index, size_t count) {
	if (index + count >= this->m_string.size()) {
		throw out_of_range("indicies to erase are out of range");
	}

	this->m_string.erase(this->m_string.begin() + index, this->m_string.begin() + index + count);
	return *this;
}