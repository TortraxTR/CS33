/*
 * CS:APP Data Lab
 *
 * Esther Li 604892225
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
 /*
  * Instructions to Students:
  *
  * STEP 1: Read the following instructions carefully.
  */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES :

Replace the "return" statement in each function with one
or more lines of C code that implements the function.Your code
must conform to the following style :

int Funct(arg1, arg2, ...) {
	/* brief description of how your implementation works */
	int var1 = Expr1;
	...
		int varM = ExprM;

	varJ = ExprJ;
	...
		varN = ExprN;
	return ExprR;
}

Each "Expr" is an expression using ONLY the following :
1. Integer constants 0 through 255 (0xFF), inclusive.You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables(no global variables).
3. Unary integer operations !~
4. Binary integer operations & ^ | +<< >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators.You are not restricted to
one operator per line.

You are expressly forbidden to :
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, || , -, or ? :
	6. Use any form of casting.
	7. Use any data type other than int.This implies that you
	cannot use arrays, structs, or unions.


	You may assume that your machine :
1. Uses 2s complement, 32 - bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE :
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
	/* exploit ability of shifts to compute powers of 2 */
	return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
	/* exploit ability of shifts to compute powers of 2 */
	int result = (1 << x);
	result += 4;
	return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating - point operations,
the coding rules are less strict.You are allowed to use looping and
conditional control.You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to :
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc(data lab checker) compiler(described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators(!~& ^ | +<< >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc.Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function.If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
 /*
  * bitParity - returns 1 if x contains an odd number of 0's
  *   Examples: bitParity(5) = 0, bitParity(7) = 1
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 20
  *   Rating: 4
  */

int bitParity(int x) {
	/*
	use XOR to mask the upper 16 bits, then the next 8 bits, then the next 4 bits, and so on
	use AND to extract the lowest (least significant) bit to determine if there is an odd number of 0's
	*/
	int parity;
	parity = x ^ (x >> 16);
	parity ^= parity >> 8;
	parity ^= parity >> 4;
	parity ^= parity >> 2;
	parity ^= parity >> 1;
	parity &= 0x1;
	return parity;
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
	/*
	extracts the lower n bits using AND mask
	right shift x by n, use AND to set the upper n bits of x to be 0
	use OR to set the upper n bits to the lower n bits
	*/
	int lowerMask, nBits, result, upperMask, nonzero;
	lowerMask = (1 << n) + ~1 + 1; //(1 << n) - 1 creates a mask of n 1's; using the rule -1 = ~1 + 1
	nBits = x & lowerMask;		  //extracts the least significant n bits of x
	result = x >> n;					   //shifts right by n
	upperMask = (1 << 31) >> (n + ~1 + 1); //creates a mask for most significant n bits (like 11110000...0)
	upperMask = ~upperMask;					   //flips so upperMask is 00001111...1
	result = result & upperMask;			   //frees up the most significant n bits of x
	nBits = nBits << (33 + ~n);				   //prepare to set the first n bits of x  
	result = nBits | result;
	nonzero = ((!(!n)) << 31) >> 31;		//checks if n = 0
	return (nonzero & result) | (~nonzero & x);
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	/*
	gets the 8 bits of the nth and mth byte, then use AND to mask x so the nth and mth bytes are 0's
	use OR to set x's nth byte and mth byte
	*/
	int a, b, mask, nByte, mByte, result;
	a = n << 3; //get the 8 bits of the nth byte
	b = m << 3; //get the 8 bits of the mth byte
	mask = (0xFF << a) | (0xFF << b); //creates a mask where 000...1...000...1...000
																 //^ nth     ^ mth 
	nByte = 0xFF & (x >> a); //extracts the nth byte
	mByte = 0xFF & (x >> b); //extracts the mth byte
	result = (~mask & x) | (nByte << b) | (mByte << a);	//first sets nth and mth bytes to 0
														//then sets x's nth byte to mByte and mth byte to nByte
	return result;
}

/*
 * fitsShort - return 1 if x can be represented as a
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
	/*
	right shifts by 15, then check of all the bits are bits are the same (0's if x > 0, 1's if x < 0)
	if x does not fit in 16 bits, not all the remaining bits will be the same
	*/
	x = x >> 15; 
	return !(x ^ 0) + !(x ^ ~0);	//if x fits and x<0, x^0 == 1, x^~0 == 0, so !1+!0 == 1
									//if x fits and x>0, x^0 == 0, x^~0 == 1, so !0+!1 == 1
									//if x does not fit, x^0 == 1, x^~0 == 1, so !1+!1 == 0
}
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	/*
	uses De Morgan's Law: !(x && y) == !x || !y, so !!(x && y) == !(!x || !y)
	*/
	return ~(~x | ~y);
}
/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
	/*
	extract the signs of x and y, then determine if their difference has the same sign as y
	 x > 0, y > 0, no overflow
     x < 0, y < 0, no overflow 
     x > 0, y < 0, overflow if difference < 0
     x < 0, y > 0, overflow if difference > 0
	*/
	int xSign, ySign, diffSign, sub, subSign;
	xSign = (x >> 31) & 0x1; //extracts the sign of x
	ySign = (y >> 31) & 0x1; //extracts the sign of y
	diffSign = xSign ^ ySign; //diffSign == 0 if x and y have same signs
	sub = x + ~y + 1; //calculates the result of subraction using -y = ~y + 1
	subSign = (sub >> 31) & 0x1; //extracts the sign of the result
	return !((subSign ^ xSign) & diffSign); //subSign^xSign == 0 if sub and x have same signs
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	/*
	extract the signs of x and y, then determine if their difference is positive or negative
	*/
	int xSign, ySign, diffSign, subSign, same, notSame;
	xSign = (x >> 31) & 0x1; //extracts the sign of x
	ySign = (y >> 31) & 0x1; //extracts the sign of y
	diffSign = xSign ^ ySign; //diffSign == 0 if x and y have same signs
	subSign = ((x + ~y) >> 31) & 0x1; //subSign == 0 if x - y - 1 >= 0 
	same = (!diffSign) & subSign; //if x and y have same signs, !diffSign & subSign == 0
	notSame = xSign & !ySign; //if x and y have different signs, xSign & !ySign == 0 for x to be greater than y
	return !(same | notSame); 
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	/*
	fills remaining upper bits with the most significant bit of x
	checks if new bit sequence is still equal to x
	*/
	int upper;
	upper = ~n + 33;
	return !(((x << upper) >> upper) ^ x);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	/*
	uses -x = ~x + 1 to calculate the result
	*/
	return ~x + 1; //-x = ~x + 1
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	/*
	if x = Tmax, num becomes Tmin, then x becomes Umax
	x (now Umax)'s complement is 00...0 and num is set to 00...0
	returns 0x01 (true) if both num and x are 0x00
	*/
	int num;
	num = x + 1;		//if x = Tmax, in bits: Tmax + 1 = Tmin
	x += num;			//Umax = 2 * Tmax + 1
	x = ~x;				//Umax (11...1) becomes 0 (00...0)
	num = !num;			//Tmin (11...1) becomes 0 
	return !(x | num);	//only returns 1 if both conditions are false 
}


