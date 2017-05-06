/* 
 *Lab of Computer Architecture 
 * 
 * <Please put your name and userid here>
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

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
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

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
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
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) 
{
	//De Morgan Law
	int x1, y1;
	x1 = ~x;
	y1 = ~y;
	return ~(x1 | y1);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) 
{
	int y;
	y = n << 3;							/*the shifts that x should take*/
  	return ((x >> y) & 0xff);			/*get shifted number last two bytes*/
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) 
{
	int xs, mask;
	xs = x >> n;						/*shift x to the right by n first, whether pos or neg*/
  	mask = ~(((1 << 31) >> n) << 1); 	/*make the shifted bits on the left 0*/
  	return xs & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) 
{
	int mask1 = 0x55;
	int mask2 = 0x33;
	int mask3 = 0x0F;

	mask1 = (mask1 << 8) + 0x55;
	mask1 = (mask1 << 8) + 0x55;
	mask1 = (mask1 << 8) + 0x55; 
	/*mask1 = 010101...*/

	mask2 = (mask2 << 8) + 0x33;
	mask2 = (mask2 << 8) + 0x33;
	mask2 = (mask2 << 8) + 0x33;
	/*mask2 = 00110011...*/

	mask3 = (mask3 << 8) + 0x0F;
	mask3 = (mask3 << 8) + 0x0F;
	mask3 = (mask3 << 8) + 0x0F;
	/*mask3 = 00001111...*/

	x = (x & mask1) + ((x >> 1) & mask1); 	/*1 to 1 combine*/
	x = (x & mask2) + ((x >> 2) & mask2); 	/*2 to 2 combine*/
	x = (x & mask3) + ((x >> 4) & mask3); 	/*4 to 4 combine*/
	x = x + (x >> 8);						/*8 to 8 combine*/
	x = x + (x >> 16);						/*16 to 16 combine*/

	/*the answer has a max size of 32*/
	return (x & 0x3F);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) 
{
	//~x + 1 = -x, only if x = 0 that -x | x == 0
  	int tmp = ((~x + 1)|x)>>31;
  	return tmp + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) 
{
	//basic concepts of complement of two 
  	return 1 << 31;
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
int fitsBits(int x, int n) 
{
  	int s = 33 + ~n;					/*shift = 32 - n*/
  	return !(x ^ ((x << s) >> s));		/*if x doesn't excedes 1<<n then there no overflow of (x<<s)>>s*/
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n)
{
	int MSB, tmp;
	MSB = ((x >> 31) & 1);				/*fetch MSB*/
	tmp = (MSB << n);					/*if neg, to ensure it rounds toward 0*/
	tmp = tmp + ((MSB << 31) >> 31);	/*x should minus 2^n - 1*/
    return ((x + tmp) >> n);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) 
{
	//basic concepts of bit op
	return (~x + 1);				
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) 
{
	return !((x >> 31) | !x);			/*fetch MSB and discard 0*/
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  	int xMSB, yMSB;
  	xMSB = (x >> 31) & 1;				/*fetch MSB*/
  	yMSB = (y >> 31) & 1;				/*fetch MSB*/

  	//judge equal will waste op so judge x > y then return opposition
  	//case 1:  xMSB = yMSB, in this case we do  x - y and fetch the new MSB
  	//case 2:  xMSB != yMSB, then judge if yMSB < 0
  	return !(((!(xMSB ^ yMSB)) & (((y + 1 + ~x) >> 31) & 1)) 
  		| ((xMSB ^ yMSB) & (yMSB & 1)));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4                                                
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x)
{
  	int x16, x8, x4, x2, x1, shift16, shift8, shift4, shift2;
  	//test the left half of x
	x16 = !(!(x >> 16));      
	//if left half != 0, than test the left-left half of x
	//if left half = 0, than test the right-left half of x			
	shift16 = x16 << 4;						
	x8 = !(!(x >> (8 + shift16)));
	//if left-left half != 0, than test the left-left-left half of x
	//if left-left half = 0, than test the left-right-left half of x	
	//if right-left half != 0, than test the right-left-left half of x
	//if right-left half = 0, than test the right-right-left half of x
	shift8 = (x8 << 3) + shift16;
	x4 = !(!(x >> (4 + shift8)));
	//we keep dividing x for 5 times
	shift4 = (x4 << 2) + shift8; 
	x2 = !(!(x >> (2 + shift4)));
	shift2 = (x2 << 1) + shift4;
	x1 = (x >> (1 + shift2));
	return x1 + shift2;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) 
{
	//test NaN and INF first
	int res,NAN_flg;
	res = uf ^ (1 << 31);
   	NAN_flg = 0x7FFFFFFF & uf; 

   	// uf is NAN or INF
   	if (NAN_flg > 0x7F800000)
      	return uf;

	return res;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) 
{
	unsigned MSB_helper, x_new, tmp, base, exp, i, fraction_helper, fraction;		
	//if x = 0, return it
	if (x == 0)                     
		return x;
	//fetch MSB
	MSB_helper = 0x80000000;
	x_new = MSB_helper & x; 
	//make x <- |x|
	if (x_new)
		x = -x;
	tmp = x;	
	base = 126;		
	i = 0;	
	//fetch exponent
	while (tmp)
	{
		tmp >>= 1;
		i += 1;	
	}
	exp = base + i;
	//fetch fraction
	x_new += (exp << 23);
	x <<= (31 - i);	      
	fraction = x >> 7;
	fraction_helper = 0x007FFFFF;
	fraction = fraction & fraction_helper;
	x_new += fraction;	
	//modify	
	x_new += (0x40 & x) && (0x40 ^ (x & 0xff));  	
	return x_new;  
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{ 
    if ((uf & 0x7F800000) == 0)			/*exp == 0, keep MSB and shift fraction to left by 1*/
        return ((uf & 0x007FFFFF)<<1) | (0x80000000 & uf);  
   
   	if ((uf & 0x7F800000) != 0x7F800000)/*exp not max and > 0, exp += 1.*/
        return (uf + 0x00800000);  							  
   
    return uf;  						/*if NaN or INF, directly return uf*/
}
