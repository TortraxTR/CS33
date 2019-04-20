#include "BITS.C"
#include <iostream>
#include <limits>
#include <string>
#include <cassert>
using namespace std;

void testBitParity() {
	assert(bitParity(5) == 0);
	assert(bitParity(7) == 1);
	cout << "Passed all tests for [bitParity]" << endl;
	cout << endl;
}


void testRotateRight() {
	assert(rotateRight(0x87654321, 4) == 0x18765432);
	assert(rotateRight(0x87654321, 0) == 0x87654321);
	cout << "Passed all tests for [rotateRight]" << endl;
	cout << endl;
}

void testByteSwap() {
	assert(byteSwap(0x12345678, 1, 3) == 0x56341278);
	assert(byteSwap(0xDEADBEEF, 0, 2) == 0xDEEFBEAD);
	cout << "Passed all tests for [byteSwap]" << endl;
	cout << endl;
}

void testFitsShort() {
	assert(fitsShort(33000) == 0);
	assert(fitsShort(-32768) == 1);
	cout << "Passed all tests for [fitsShort]" << endl;
	cout << endl;
}

void testBitAnd() {
	assert(bitAnd(6, 5) == 4);
	assert(bitAnd(3, 4) == 0);
	cout << "Passed all tests for [bitAnd]" << endl;
	cout << endl;
}

void testSubOK() {
	assert(subOK(0x80000000, 0x80000000) == 1);
	assert(subOK(0x80000000, 0x70000000) == 0);
	cout << "Passed all tests for [subOK]" << endl;
	cout << endl;
}

void testIsGreater() {
	assert(isGreater(4, 5) == 0);
	assert(isGreater(5, 4) == 1);
	assert(isGreater(4, 4) == 0);
	cout << "Passed all tests for [isGreater]" << endl;
	cout << endl;
}

void testFitsBits() {
	assert(fitsBits(5, 3) == 0);
	assert(fitsBits(-4, 3) == 1);
	cout << "Passed all tests for [fitsBits]" << endl;
	cout << endl;
}

void testNegate() {
	int x = LONG_MAX + 1; //-2147482648
	int y = 0;
	int z = -2000;
	cout << x << endl;
	cout << negate(x) << endl;
	assert(x == -1 * negate(x));
	cout << y << endl;
	cout << negate(y) << endl;
	assert(y == -1 * negate(y));
	cout << z << endl;
	cout << negate(z) << endl;
	assert(z == -1 * negate(z));
	cout << "Passed all tests for [negate]" << endl;
	cout << endl;
}

void testIsTmax() {
	int x = LONG_MAX;
	int y = x - 1;
	int z = x + 1;
	cout << x << endl;
	cout << isTmax(x) << endl;
	cout << y << endl;
	cout << isTmax(y) << endl;
	cout << z << endl;
	cout << isTmax(z) << endl;
	cout << "Passed all tests for [isTmax]" << endl;
	cout << endl;
}

int main() {
	testBitParity();
	testRotateRight();
	testByteSwap();
	testFitsShort();
	testBitAnd();
	testSubOK();
	testIsGreater();
	testFitsBits();
	testNegate();
	testIsTmax();
}
