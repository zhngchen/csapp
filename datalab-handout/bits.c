/* 
 * CS:APP Data Lab 
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // 简单的布尔代数, 用非，与表示异或
  int nx = ~x;
  int ny = ~y;
  int res;

  res = ~(~(x & ny) & ~(nx & y));
  return res;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // 01 左移即可
  int res = 0x01;
  res = res << 31;
  return res;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // 要判断是否是Tmax, 考虑~T == T + 1, 同时要排除-1
  int res;
  res = !(~x ^ (x + 1)) & !!~x;
  return res;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // x & 0xAA.. == 0xAAAA..,  需要0xAA..
  int a = 0xAA << 8;  // 0xAA00
  int b = a | 0xAA;   // 0xAAAA
  int c = b | (b << 16); // 0x AAAAAAAA
  int res = !((x & c) ^ c);
  return res;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  int res = ~x + 1;
  return res;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // x - 0x30 >= 0  && 0x39 - x >= 0
  int negate = 0x01 << 31;
  int res;

  res = !((x + ~0x30 + 1) & negate) & !((0x39 + ~x + 1) & negate);

  return res;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // (x and y) | (~x and z) bool变量必然可以
  // 将x的值映射到 0x0000 或 0xFFFF
  int tmp = ~(!!x) + 1;  // x == 0 tmp = 0;  x != 0 tmp = 0XFFF..
  int res = (tmp & y) | (~tmp & z);

  return res;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // y - x >= 0(有可能溢出)
  // 处理溢出需要判断符号位, 同号不可能溢出
  int sgn_x = x >> 31;  // 0x0000 或 0xFFFF
  int sgn_y = y >> 31;
  int res = (!!(sgn_x & !sgn_y)) | ((!(sgn_x ^ sgn_y)) & !((y + ~x + 1) >> 31));
  // 前面依据符号位给出0/1 后面在x == y下计算y - x >= 0

  return res;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 只要x不为0， x与x的补码最高位一定有一个为1
  int res = ((x | (~x + 1)) >> 31) + 1;
  // 最高位为1，进行算数右移

  return res;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
// 首先把题想明白，12 => 01100, -1 => 1, -5 => 1011
int howManyBits(int x) {
  int sign, b0, b1, b2, b4, b8, b16;
  sign = (x >> 31);
  x = (sign & ~x) | (~sign & x); // 让x>=0时不变，<0则取反
  b16 = !!(x >> 16) << 4;  // 高16bit不为0，意味着至少需要16bit表示低位
  x = x >> b16;            
  b8 = !!(x >> 8) << 3;
  x = x >> b8;
  b4 = !!(x >> 4) << 2;
  x = x >> b4;
  b2 = !!(x >> 2) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  b0 = x >> b1;
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned e = (uf >> 23) & 0xff;  // 阶码
  unsigned s = uf & (0x01 << 31);  // 符号位, 10000.. 或 00000..,便于组合
  unsigned f = (uf << 9) >> 9;          // 尾数
  unsigned res;

  if (e == 0x00)  // 非规格化
  {
    // 除了符号位，整体左移一位
    res = uf << 1 | s;

  }
  else if (e == 0xff)  // 特殊值
  {
    res = uf;
  }
  else // 规格
  {
    if (e == 0xfe) // 无穷
    {
      res = s | (0xff000000 >> 1);
    }
    else
      res = s | ((e + 1) << 23) | f;
  }

  return res;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned e = (uf >> 23) & 0xff;  // 阶码
  unsigned s = uf & (0x01 << 31);  // 符号位, 10000.. 或 00000..,便于组合
  unsigned f = (uf << 9) >> 9;     // 尾数

  if (!s && e == 0x9e && f == 0)  // 此时边界, E = e - bias = 31
    return 0x01 << 31;
  
  if (e >= 0x9e) // 超出; 特殊值
    return 0x80000000;

  if (e < 127) //  < 1  bias = 127
    return 0;
  // 规格化，范围内
  unsigned E = e - 127;
  // 1.f * 2^E,  应该需要f的前E个bit
  int g = E <= 23 ? (f >> (23 - E)) : (f << (E - 23));
  int pos_res = g | 0x01 << E;  // 填上1,此时符号位一定为0
  int res = !s ? pos_res : ~pos_res + 1;  // 为负的调整

  return res;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // float E范围 : -126 ~ 127
  if (x < -126)
    return 0;
  
  if (x > 127)
    return 0xff000000 >> 1;
  
  if (x == -126) // 非规格化
    return 0x01;
  
  unsigned e = x + 127;
  return e << 23;
}
