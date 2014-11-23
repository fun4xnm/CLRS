#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "common.h"
#include <sys/types.h>

int isPowerOf2(int n)
{
	/* if n is power of 2, it must be only one set bit in binary presation,
	 * so  (n - 1) must be all set bit . if n is 0x100, then n- 1 is 0xff
	 */
	return (n && (!(n & (n - 1))));
}

/* if n is 4, getSetBit return 3 ,mean the 3rd bit is one */
int getSetBit(int n)
{
	if (!isPowerOf2(n))
		return -1;
	int count = 0;
	while (n){
		n = n >> 1;
		++count;
	}
	return count;
}

/* if n is 0b00100001,then 0010 and 0001 are two nibbles */
uint8_t swapNibbles(uint8_t n)
{
	return ( (n & 0x0f) << 4 | (n &0xf0) >> 4);
}

/* return a number all bits same as n except the k'th bit which is made 0 */
int32_t turnOffK(int n, int k)
{
	if (n <= 0)
		return n;
	return (n & (~(1 << (k - 1))));	
}

bool isKBitSet(uint32_t n, uint32_t k)
{
	return (n & (1 << (k - 1))) ? true : false;
}

/* return true if binary representation of n is palindrome.0b1001 is paldindrome */
bool isPalindrome(uint32_t n)
{
	uint32_t left = 1;
	uint32_t right = sizeof(uint32_t) * 8;

	while (left < right){
		if (isKBitSet(n, left) != isKBitSet(n, right))
			return false;
		++left;
		--right;
	}
	return true;
}
