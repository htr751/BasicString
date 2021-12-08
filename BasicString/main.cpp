#include <iostream>
#include <utility>

#include "BasicString.h"

using std::cout;
using std::move;

int main() {
	BasicString str = "hello world";
	cout << str << "\r\n";

	BasicString strCopy = str;
	cout << strCopy << "\r\n";

	BasicString strMove = move(strCopy);
	cout << strMove << "\r\n";

	strMove.insert(0, "Hi Roy Cabouly, ");
	cout << strMove << "\r\n";

	strMove.insert(1, 2, 'i');
	str = strMove;

	cout << str << "\r\n";

	str.erase(1, 2);
	cout << str << "\r\n";

	return 0;
}